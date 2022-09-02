#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const LL INF=0X3F3F3F3F3F3F3F3FLL;
template<typename T>bool umax(T&x,const T&y){
	return x<y?x=y,1:0;
}
template<typename T>bool umin(T&x,const T&y){
	return x>y?x=y,1:0;
}
const int N=5005;
int n,s,t;
LL x[N],A[N],B[N],C[N],D[N],f[N][N];
int main(){
	memset(f,63,sizeof(f));
	scanf("%d%d%d",&n,&s,&t);
	rep(i,1,n)scanf("%lld",x+i);
	rep(i,1,n)scanf("%lld",A+i),A[i]+=x[i];
	rep(i,1,n)scanf("%lld",B+i),B[i]-=x[i];
	rep(i,1,n)scanf("%lld",C+i),C[i]+=x[i];
	rep(i,1,n)scanf("%lld",D+i),D[i]-=x[i];
	if(s==1){
		f[2][1]=D[1];
	}else if(t==1){
		f[2][1]=B[1];
	}else f[2][1]=B[1]+D[1];
	rep(i,2,n){
		if(i==s){
			rep(j,1,i){
				if(j==1&&i>t&&i<n);else umin(f[i+1][j],f[i][j]+C[i]);
				umin(f[i+1][j+1],f[i][j]+D[i]);
			}
		}else if(i==t){
			rep(j,1,i){
				if(j==1&&i>s&&i<n);else umin(f[i+1][j],f[i][j]+A[i]);
				umin(f[i+1][j+1],f[i][j]+B[i]);
			}
		}else{
			rep(j,1,i){
				umin(f[i+1][j+1],f[i][j]+B[i]+D[i]);
				if(j==1&&i>t);else umin(f[i+1][j],f[i][j]+A[i]+D[i]);
				if(j==1&&i>s);else umin(f[i+1][j],f[i][j]+B[i]+C[i]);
				if(j<=2&&i>s&&i>t&&i<n);else umin(f[i+1][j-1],f[i][j]+C[i]+A[i]);
			}
		}
	}
	printf("%lld\n",f[n+1][1]);
	return 0;
}