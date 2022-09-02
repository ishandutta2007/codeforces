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
const int N=2005;
int n,m,w1[N][N],w2[N][N],dp1[N][N],dp2[N][N];
char s[N][N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	if(n==1&&m==1){
		puts("1"),exit(0);
	}
	rep(i,1,n){
		scanf("%s",s[i]+1);
		per(j,m,1){
			w1[i][j]=w1[i][j+1]+(s[i][j]=='R');
		}
	}
	rep(j,1,m){
		per(i,n,1){
			w2[i][j]=w2[i+1][j]+(s[i][j]=='R');
		}
	}
	dp1[1][1]=1,dp1[1][2]=P-1,dp2[1][1]=1,dp2[2][1]=P-1;
	rep(i,1,n){
		rep(j,1,m){
			uad(dp1[i][j],dp1[i][j-1]);
			uad(dp2[i][j],dp2[i-1][j]);
			
			uad(dp1[i][j+1],dp2[i][j]);
			usu(dp1[i][m-w1[i][j+1]+1],dp2[i][j]);
			
			uad(dp2[i+1][j],dp1[i][j]);
			usu(dp2[n-w2[i+1][j]+1][j],dp1[i][j]);
		}
	}
	printf("%d\n",ad(dp1[n][m],dp2[n][m]));
	return 0;
}