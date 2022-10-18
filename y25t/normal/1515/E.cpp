#include<cstdio>
#include<algorithm>
#define N 405

int P;

inline int fmo(int x){
	return x+((x>>31)&P);
}

int n;

int f[4][N][N],g[4][N][N];
int sf[4][N][N],sg[4][N][N];

int ans;

int main(){
	scanf("%d%d",&n,&P);
	f[1][1][1]=g[1][1][1]=1;
	sf[1][1][1]=sf[1][1][2]=sg[1][1][1]=sg[1][1][2]=1;
	for(int i=2;i<=n;i++){
		for(int s=1;s<=i;s++)
			for(int x=1;x<=s+1;x++)
				f[i&3][s][x]=g[i&3][s][x]=sf[i&3][s][x]=sg[i&3][s][x]=0;
		for(int s=1;s<=i;s++){
			for(int x=1;x<=s;x++){
				f[i&3][s][x]=fmo(f[i&3][s][x]+sf[(i+2)&3][s-1][s-1]-P);
				f[i&3][s][x]=fmo(f[i&3][s][x]+sf[(i+3)&3][s-1][x-1]-P);
				f[i&3][s][x]=fmo(f[i&3][s][x]+fmo(sg[(i+3)&3][s-1][s-1]-sg[(i+3)&3][s-1][x-1])-P);
				g[i&3][s][x]=fmo(f[i&3][s][x]-sf[(i+3)&3][s-1][x-1]);
			}
			for(int x=1;x<=s+1;x++){
				sf[i&3][s][x]=fmo(sf[i&3][s][x-1]+f[i&3][s][x]-P);
				sg[i&3][s][x]=fmo(sg[i&3][s][x-1]+g[i&3][s][x]-P);
			}
		}
	}
	for(int s=1;s<=n;s++)
		ans=fmo(ans+sf[n&3][s][s]-P);
	printf("%d\n",ans);
}