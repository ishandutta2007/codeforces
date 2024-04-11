// author: xay5421
// created: Wed Sep 15 11:42:32 2021
#include<bits/stdc++.h>
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int P=1e9+7;
int ad(int k1,int k2){return k1+=k2-P,k1+=k1>>31&P;}
int su(int k1,int k2){return k1-=k2,k1+=k1>>31&P;}
int mu(int k1,int k2){return 1LL*k1*k2%P;}
void uad(int&k1,int k2){k1+=k2-P,k1+=k1>>31&P;}
void usu(int&k1,int k2){k1-=k2,k1+=k1>>31&P;}
template<typename... T>int ad(int k1,T... k2){return ad(k1,ad(k2...));}
template<typename... T>int su(int k1,T... k2){return su(k1,ad(k2...));}
template<typename... T>int mu(int k1,T... k2){return mu(k1,mu(k2...));}
template<typename... T>void uad(int&k1,T... k2){return uad(k1,ad(k2...));}
template<typename... T>void usu(int&k1,T... k2){return usu(k1,ad(k2...));}
int po(int k1,int k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
const int N=1000005;
int n,a[N],pre[N];
int p[N],mind[N],fac[N],inv[N],ifac[N];
bool ban[N];
vector<int>vec[78505];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return 1LL*fac[k1]*ifac[k2]%P*ifac[k1-k2]%P;
}
void sieve(){
	ban[0]=ban[1]=1;
	for(int i=1;i<N;++i){
		if(!ban[i]){
			p[++p[0]]=i;
			mind[i]=p[0];
		}
		for(int j=1;j<=p[0]&&i*p[j]<N;++j){
			ban[i*p[j]]=1;
			mind[i*p[j]]=j;
			if(i%p[j]==0)break;
		}
	}
}
int main(){
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	for(int i=2;i<N;++i)fac[i]=1LL*fac[i-1]*i%P,inv[i]=1LL*(P-P/i)*inv[P%i]%P,ifac[i]=1LL*ifac[i-1]*inv[i]%P;
	sieve();
	rd(n);
	rep(i,1,n){
		rd(a[i]);
		int x=a[i];
		while(x>1){
			int t=mind[x],cnt=0;
			while(x%p[t]==0)x/=p[t],++cnt;
			vec[t].push_back(cnt);
		}
	}
	rep(i,0,n){
		pre[i]=ad(i?pre[i-1]:0,C(n-1,i-1));
	}
	static int cost1[N],cost2[N];
	int ans=0;
	rep(_,1,p[0])if(!vec[_].empty()){
		sort(vec[_].begin(),vec[_].end());
		int w0=n-SZ(vec[_]);
		int k1=w0;
		rep(i,0,SZ(vec[_])-1){
			cost1[i]=ad(C(n-2,k1-1),C(n-2,k1-2));
			cost2[i]=ad(C(n-2,k1),C(n-2,k1-1));
			uad(ans,mu(C(n-1,k1-1),vec[_][i]));
			++k1;
		}
		int sum=w0?pre[w0-1]:0;
		rep(i,0,SZ(vec[_])-1){
			uad(ans,mu(sum,vec[_][i]));
			uad(sum,cost1[i]);
		}
		sum=0;
		per(i,SZ(vec[_])-1,0){
			usu(ans,mu(sum,vec[_][i]));
			uad(sum,cost2[i]);
		}
	}
	printf("%d\n",ans);
	return 0;
}