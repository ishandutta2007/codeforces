// author: xay5421
// created: Sat Oct  2 23:22:37 2021
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
using LL=long long;
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
int po(int k1,LL k2){
	int k3=1;
	for(;k2;k2>>=1,k1=mu(k1,k1))if(k2&1)k3=mu(k3,k1);
	return k3;
}
int n,m,K,r,c,ax,ay,bx,by;
int main(){
	scanf("%d%d%d%d%d",&n,&m,&K,&r,&c);
	scanf("%d%d%d%d",&ax,&ay,&bx,&by);
	LL area=0;
	if(ax==bx&&ay==by){
		area=1LL*n*m;
	}else{
		if(ax>bx)swap(ax,bx),swap(ay,by);
		int xx=max(0,ax+r-1-bx+1);
		int yy=max(0,ay+c-1-by+1);
		area=1LL*n*m-1LL*r*c;
	}
	printf("%d\n",po(K,area));
	return 0;
}