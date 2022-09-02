// author: xay5421
// created: Wed Dec  9 16:29:45 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef long long LL;
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
LL n;
int K,fm=1,inv[105];
int deal(int k1,int k2){
	D("deal %d %d\n",k1,k2);
	vector<int>f(k2+1);
	f[k2]=1;
	rep(_,1,K){
		int s=0;
		per(i,k2,0){
			s=ad(s,mu(f[i],inv[i+1]));
			f[i]=s;
		}
	}
	int pw=1,ans=0,tot=0;
	rep(i,0,k2){
		if(i)pw=mu(pw,k1);
		ans=ad(ans,mu(pw,f[i]));
		tot=ad(tot,f[i]);
	}
	fm=mu(fm,tot);
	//D("ans=%d\n",ans);
	return ans;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	inv[0]=inv[1]=1;
	rep(i,2,104)inv[i]=mu(P-P/i,inv[P%i]);
	scanf("%lld%d",&n,&K);
	int ans=1;
	for(int i=2;i<=n/i;++i)if(n%i==0){
		int tt=0;
		while(n%i==0)n/=i,++tt;
		ans=mu(ans,deal(i,tt));
	}
	if(n>1){
		ans=mu(ans,deal(n%P,1));
	}
	printf("%d\n",mu(ans,po(fm,P-2)));
	return 0;
}