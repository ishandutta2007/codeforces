// author: xay5421
// created: Mon Nov 15 22:09:10 2021
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
const int P=1e9+7;
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
const int N=1000005,INF=0X3F3F3F3F;
int n,dp[N],coef[N];
char s_[N],s[N];
struct seg{
	int a,k,sz;
};
int main(){
	scanf("%s",s_+1);
	{
		int n_=strlen(s_+1);
		if(n_&1)puts("0"),exit(0);
		rep(i,1,n_/2){
			s[++n]=s_[i];
			s[++n]=s_[n_-i+1];
		}
		//D("s=%s\n",s+1);
	}
	vector<seg>G;
	dp[0]=1;
	rep(i,1,n){
		vector<seg>G1,G2;
		for(auto&x:G)if(x.a>1&&s[x.a-1]==s[i])G1.pb((seg){x.a-1,x.k,x.sz});
		int pos=~INF;
		for(auto&x:G1){
			if(x.a-pos!=x.k){
				G2.pb((seg){x.a,x.a-pos,1});
				if(x.sz>1)G2.pb((seg){x.a+x.k,x.k,x.sz-1});
			}else{
				G2.pb(x);
			}
			pos=x.a+x.k*(x.sz-1);
		}
		if(i>1&&s[i-1]==s[i])G2.pb((seg){i-1,i-1-pos,1}),pos=i-1;
		G2.pb((seg){i,i-pos,1});
		
		G.clear();
		seg now=G2[0];
		G2.erase(G2.begin());
		for(auto&x:G2){
			if(now.k==x.k){
				now.sz+=x.sz;
			}else{
				G.pb(now);
				now=x;
			}
		}
		G.pb(now);
		
		for(auto&x:G){
			pos=x.a+x.k*(x.sz-1);
			int cur=dp[pos-1];
			if(x.sz>1)uad(cur,coef[x.a-x.k]);
			if(x.a-x.k>=0)coef[x.a-x.k]=cur;
			if(~i&1)uad(dp[i],cur);
		}
		//D("dp[%d]=%d\n",i,dp[i]);
	}
	printf("%d\n",dp[n]);
	return 0;
}