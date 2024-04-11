#include<bits/stdc++.h>
#define P 1000000007
#define N 1000005

inline void fmo(int &x){
	x+=((x>>31)&P);
}

int T;

int n;

int pw[N],ipw[N];

int f[N],g[N];

int main(){
	pw[0]=ipw[0]=1;
	for(int i=1;i<=1e6;i++){
		fmo(pw[i]=pw[i-1]+pw[i-1]-P);
		ipw[i]=1ll*ipw[i-1]*(P+1)/2%P;
	}
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<=n+1;i++)
			f[i]=g[i]=0;
		for(int i=n;i>=n/2+1;i--){
			f[i]=1;
			fmo(g[i]=g[i+1]+1ll*ipw[i]*f[i]%P-P);
		}
		for(int i=n/2;i;i--){
			f[i]=1ll*pw[i]*(g[i+1]-g[i+i]+P)%P;
			fmo(g[i]=g[i+1]+1ll*ipw[i]*f[i]%P-P);
		}
		for(int i=1;i<=n;i++){
			int tmp=i==n?1:ipw[1];
			tmp=1ll*tmp*ipw[(i-1)/2]%P;
			tmp=1ll*tmp*f[i]%P;
			printf("%d\n",tmp);
		}
	}
}