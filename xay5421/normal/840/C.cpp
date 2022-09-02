#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
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
const int N=100005;
int n,a[305],fac[N],inv[N],ifac[N];
int C(int k1,int k2){
	if(k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
void deal(int&x){
	rep(i,2,x/i){
		while(x%(i*i)==0){
			x=x/i/i;
		}
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d",&a[i]);
		deal(a[i]);
	}
	sort(a+1,a+n+1);
	vector<int>v;
	for(int i=1,j;i<=n;i=j){
		j=i+1;
		while(j<=n&&a[i]==a[j])++j;
		v.pb(j-i);
	}
	int sum=0;
	vector<int>dp(sum+1); // dp[i]i,sum-i
	dp[0]=1;
	for(auto&sz:v){
		int nsum=sum+sz;
		vector<int>ndp(nsum+1);
		rep(a,0,sum){
			rep(b,0,sz-1){
				uad(ndp[a+b],mu(dp[a],C(sum-a+sz-b,sz-b),C(sz-1,sz-b-1)));
			}
		}
		dp=move(ndp);
		sum=nsum;
	}
	int res=0;
	rep(i,0,sum){
		if(i&1)usu(res,dp[i]);
		else uad(res,dp[i]);
	}
	for(auto&x:v){
		res=mu(res,fac[x]);
	}
	printf("%d\n",res);
	return 0;
}