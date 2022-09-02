// author: xay5421
// created: Sat Oct 30 15:19:54 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int P=998244353;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<class... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<class... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<class... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<class... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<class... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
int n,K;
int main(){
	scanf("%d%d",&n,&K);
	if(K==1){
		vector<vector<int > >dp(n+1,vector<int>(n+1,0));
		dp[0][0]=1;
		rep(i,1,n){
			rep(j,0,n){
				dp[i][j]=ad(dp[i-1][j],j-i>=0?dp[i][j-i]:0);
			}
		}
		int ans=0;
		rep(j,1,n)uad(ans,dp[n][j]);
		printf("%d\n",ans);
	}else if(K==2){
		vector<vector<int> >dp(n+1,vector<int>(n+1,0));
		dp[0][0]=1;
		rep(i,1,n){
			int s=min((LL)n+1,(LL)i*(i+1)/2);
			rep(j,0,n){
				dp[i][j]=ad(dp[i-1][j],j-s>=0?dp[i][j-s]:0);
			}
		}
		int ans=0;
		rep(j,1,n)uad(ans,dp[n][j]);
		printf("%d\n",ans);
	}else{
		int ans=0;
		array<int,100>a={0};
		auto chk=[&](int len){ // 0..len
			vector<int>b(a.begin(),a.begin()+len);
			rep(_,1,K-1){
				int sum=0;
				rep(i,0,SZ(b)-1)sum+=b[i]*(i+1);
				if(sum>n)return 0;
				vector<int>nb;
				per(i,SZ(b)-1,0){
					rep(j,1,b[i])nb.pb(i+1);
				}
				b=nb;
			}
			int sum=0;
			rep(i,0,SZ(b)-1)sum+=b[i];
			if(sum>n)return 0;
			/*rep(i,0,len-1)D("%d ",a[i]);
			D("\n");*/
			return 1;
		};
		function<void(int,int,int)>dfs=[&](int step,int lst,int sum){
			for(int i=1;i<=lst;++i){
				a[step]=i;
				if(chk(step+1)){
					++ans;
					dfs(step+1,i,sum+i);
				}else return;
			}
		};
		dfs(0,n,0);
		printf("%d\n",ans);
	}
	return 0;
}