// author: xay5421
// created: Thu Dec 10 08:21:43 2020
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
const int N=200005,P=998244353;
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
int n,m,pw[N],pw2[N],fac[N],inv[N],ifac[N];
char s[N];
int C(int k1,int k2){
	if(k1<0||k2<0||k1-k2<0)return 0;
	return mu(fac[k1],ifac[k2],ifac[k1-k2]);
}
struct solver{
	int F,pos,sum; // sum=sum(i=[0,pos] C(F,i))
	void up(int f,int p){
		p=min(p,f);
		while(pos>p)sum=su(sum,C(F,pos--));
		while(F<f)sum=su(ad(sum,sum),C(F,pos)),++F;
		while(F>f)--F,sum=ad(sum,C(F,pos)),sum=mu(sum,(P+1)>>1);
		while(pos<p)sum=ad(sum,C(F,++pos));
		/*int tem=0;
		rep(i,0,p)tem=ad(tem,C(f,i));
		assert(tem==sum);*/
	}
	const int pre(){return sum;}
	const int suf(){return su(pw2[F],sum);}
}a,b,c,d;
int sol(int F,int x){
	if(F<=3){
		int res=0;
		for(int i=x&1;i<=F;i+=2)uad(res,mu(C(F,i),abs(x-i)));
		return res;
	}
	a.up(F-1,x-2);
	b.up(F-2,x-3);
	c.up(F-2,x-1);
	d.up(F-1,x);
	/*{
		int tem=0;
		rep(i,0,x-2)if((x&1)==(i&1))tem=ad(tem,C(F,i));
		assert(tem==a.pre());
	}
	{
		int tem=0;
		rep(i,0,x-2)if((x&1)==(i&1))tem=ad(tem,C(F-1,i-1));
		assert(tem==b.pre());
	}
	{
		int tem=0;
		rep(i,x+2,F)if((x&1)==(i&1))tem=ad(tem,C(F-1,i-1));
		assert(tem==c.suf());
	}*/
	return ad(su(mu(x,a.pre()),mu(F,b.pre())),su(mu(F,c.suf()),mu(x,d.suf())));
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	pw[0]=pw2[0]=1;
	rep(i,1,N-1)pw[i]=mu(pw[i-1],(P+1)>>1),pw2[i]=ad(pw2[i-1],pw2[i-1]);
	fac[0]=fac[1]=inv[0]=inv[1]=ifac[0]=ifac[1]=1;
	rep(i,2,N-1)fac[i]=mu(fac[i-1],i),inv[i]=mu(P-P/i,inv[P%i]),ifac[i]=mu(ifac[i-1],inv[i]);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	int x=0,F=0;
	rep(i,1,n){
		if(i&1)x-=s[i]=='b';
		else x-=s[i]=='w';
		F+=s[i]=='?';
	}
	x+=n/2;
	a.sum=b.sum=c.sum=d.sum=1;
	rep(i,0,m){
		if(i){
			int k1,k2;
			scanf("%d",&k1);
			while(k2=getchar(),k2!='w'&&k2!='b'&&k2!='?');
			if(k1&1)x+=s[k1]=='b';
			else x+=s[k1]=='w';
			F-=s[k1]=='?';
			s[k1]=k2;
			if(k1&1)x-=s[k1]=='b';
			else x-=s[k1]=='w';
			F+=s[k1]=='?';
		}
		printf("%d\n",mu(sol(F,x),pw[F]));
	}
	return 0;
}