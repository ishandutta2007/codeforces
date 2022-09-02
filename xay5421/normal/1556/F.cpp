// author: xay5421
// created: Sun Aug 29 23:27:09 2021
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
const int N=20;
int n,a[N],win[N][N],w2[N][(1<<14)+5],f[(1<<14)+5],g[(1<<14)+5];
int calc(int s,int t){
	int res=1;
	rep(i,0,n-1)if(s>>i&1)res=mu(res,w2[i][t]);
	return res;
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,0,n-1){
		scanf("%d",&a[i]);
	}
	rep(i,0,n-1){
		rep(j,0,n-1){
			win[i][j]=mu(a[i],po(ad(a[i],a[j]),P-2));
		}
	}
	rep(i,0,n-1){
		rep(j,0,(1<<n)-1){
			w2[i][j]=1;
			rep(k,0,n-1)if(j>>k&1)w2[i][j]=mu(w2[i][j],win[i][k]);
		}
	}
	f[0]=1;
	rep(s,1,(1<<n)-1){
		int low=s&-s;
		/*for(int t=(s-1)&s;t;--t&=s)if(t&low){
			usu(g[s],mu(f[t^s],g[t]));
		}*/
		f[s]=1;
		for(int t=(s-1)&s;t;--t&=s){
			int t_=s^t;
			usu(f[s],mu(calc(t_,t),g[t]));
		}
		uad(g[s],f[s]);
	}
	//rep(i,0,(1<<n)-1)D("f[%d]=%d\n",i,f[i]);
	int ans=0;
	rep(i,1,(1<<n)-1){
		int p=1;
		rep(j,0,n-1)rep(k,0,n-1)if((i>>j&1)&&(~i>>k&1)){
			p=mu(p,win[j][k]);
		}
		uad(ans,mu(p,f[i],__builtin_popcount(i)));
	}
	printf("%d\n",ans);
	return 0;
}