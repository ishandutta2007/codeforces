// author: xay5421
// created: Mon Aug  2 17:36:02 2021
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
const int P=31607;
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
const int I=po(10000,P-2);
int n,a[25][25],_a[25][25],ia[25][25],v[25],_v[25],f[50],C[50][50];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	C[0][0]=1;
	rep(i,1,49){
		C[i][0]=1;
		rep(j,1,i)C[i][j]=ad(C[i-1][j-1],C[i-1][j]);
	}
	scanf("%d",&n);
	rep(i,0,n-1)rep(j,0,n-1)scanf("%d",&a[i][j]),a[i][j]=mu(a[i][j],I);
	int ans=0;
	memcpy(_a,a,sizeof(a));
	rep(f1,0,1)rep(f2,0,1){
		int p=1;
		memcpy(a,_a,sizeof(a));
		fill(v,v+n,1);
		rep(i,0,n-1)rep(j,0,n-1){
			if((f1&&i==j)||(f2&&i+j==n-1))p=mu(p,a[i][j]),a[i][j]=1;
			else v[j]=mu(v[j],a[i][j]);
			ia[i][j]=po(a[i][j],P-2);
		}
		int s=0;
		rep(_,0,(1<<n)-1){
			if(_){
				int t=_&(-_),i=__builtin_ctz(t);
				if(s&t){
					rep(j,0,n-1)p=mu(p,ia[i][j]),v[j]=mu(v[j],a[i][j]);
				}else{
					rep(j,0,n-1)p=mu(p,a[i][j]),v[j]=mu(v[j],ia[i][j]);
				}
				s^=t;
			}
			int cnt=f1+f2+__builtin_popcount(s);
			int dp[2]={1,0};
			rep(j,0,n-1){
				int ndp[2]={0,0};
				rep(o,0,1){
					uad(ndp[o^1],mu(dp[o],v[j]));
					uad(ndp[o],dp[o]);
				}
				dp[0]=ndp[0],dp[1]=ndp[1];
			}
			rep(o,0,1){
				if((cnt+o)&1){
					usu(ans,mu(dp[o],p));
				}else{
					uad(ans,mu(dp[o],p));
				}
			}
		}
	}
	printf("%d\n",su(1,ans));
	return 0;
}