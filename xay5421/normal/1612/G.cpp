#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
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
int m,c[500005],cnt[1000005],fac[1000005],ifac[1000005];
int sum(int l,int r){
	return su(mu(r,r+1,(P+1)>>1),mu(l-1,l,(P+1)>>1));
}
int main(){
	fac[0]=fac[1]=1;
	rep(i,2,1000004)fac[i]=mu(fac[i-1],i);
	ifac[1000004]=po(fac[1000004],P-2);
	per(i,1000004,1)ifac[i-1]=mu(ifac[i],i);
	rd(m);
	rep(i,0,m-1)rd(c[i]),++cnt[c[i]-1];
	for(int i=1000000;i>=2;--i){
		uad(cnt[i-2],cnt[i]);
	}
	int cur=1,ans=0,tot=1;
	per(i,1000000,1){
		uad(ans,mu(su(0,i),sum(cur,cur+cnt[i]-1)));
		uad(cur,cnt[i]);
		tot=mu(tot,fac[cnt[i]]);
	}
	rep(i,0,1000000){
		uad(ans,mu(i,sum(cur,cur+cnt[i]-1)));
		uad(cur,cnt[i]);
		tot=mu(tot,fac[cnt[i]]);
	}
	printf("%d %d\n",ans,tot);
	return 0;
}