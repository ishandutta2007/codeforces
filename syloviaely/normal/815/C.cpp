#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct bian{
	int next,point;
}b[6000];
int p[6000],g[6000][6000],f[6000][6000],A[6000],B[6000],inf;
int size[6000],w[6000],d[60000],n,m,len,c[6000];
void add(int k1,int k2){
	b[++len]=(bian){p[k1],k2}; p[k1]=len;
}
void merge(int k1,int k2){
	int N=size[k1]+size[k2];
	for (int i=0;i<=N;i++) A[i]=B[i]=inf;
	for (int i=0;i<=size[k1];i++)
		for (int j=0;j<=size[k2];j++){
			A[i+j]=min(A[i+j],min(f[k1][i],g[k1][i])+min(f[k2][j],g[k2][j]));
			B[i+j]=min(B[i+j],g[k1][i]+g[k2][j]);
		}
	for (int i=0;i<=N;i++){
		f[k1][i]=min(f[k1][i],A[i]);
		g[k1][i]=min(g[k1][i],B[i]);
	}
	size[k1]=N;
}
void getdp(int k){
	g[k][0]=0;
	for (int i=p[k];i;i=b[i].next){
		int j=b[i].point; getdp(j);
		merge(k,j);
	}
	size[k]++;
	for (int i=size[k];i;i--){
		f[k][i]=min(g[k][i-1],f[k][i-1])+c[k]-d[k];
		g[k][i]=min(g[k][i],g[k][i-1]+c[k]);
	}
	f[k][0]=inf;
}
int main(){
	scanf("%d%d",&n,&m);
	memset(f,0x3f,sizeof f);
	memset(g,0x3f,sizeof g); inf=f[1][1];
	for (int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
		int k; if (i>1){scanf("%d",&k); add(k,i);}
	}
	getdp(1);
	int ans=0;
	for (int i=1;i<=n;i++) if (f[1][i]<=m||g[1][i]<=m) ans=i;
	printf("%d\n",ans);
	return 0;
}