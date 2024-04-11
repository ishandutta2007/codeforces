#include<bits/stdc++.h>
using namespace std;
const int N=13,M=2005;
int a[N][N],b[N][M],c[M],d[M],dp[N][1<<N],e[N],flag[N][1<<N],V[N][1<<N],S[N][1<<N],n,m,T,K[1<<12][(1<<12)+5];
inline int dfs(int x,int y){
	if (x==m+1)return 0;
	if (flag[x][y])return dp[x][y];
	flag[x][y]=1;
	int v=0;
	for (int i=0;i<n;i++)
		if (!((1<<i)&y))v+=1<<i;
	for (int j=1;j<=K[v][0];j++)
		dp[x][y]=max(dp[x][y],dfs(x+1,y|K[v][j])+S[x][K[v][j]]);
	return dp[x][y];
}
inline int cmp(int x,int y){
	return c[x]>c[y];
}
inline void doit(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=1;j<=m;j++)scanf("%d",&b[i][j]),c[j]=max(c[j],b[i][j]);
	for (int i=1;i<=m;i++)d[i]=i;
	sort(d+1,d+m+1,cmp);
	for (int i=1;i<=n&&i<=m;i++)
		for (int j=0;j<n;j++)a[j][i]=b[j][d[i]];
	m=min(n,m);
	for (int i=1;i<=m;i++)
		for (int j=0;j<n;j++){
			memset(V[i],0,sizeof V[i]);
			for (int k=0;k<n;k++)V[i][1<<k]=a[(j+k)%n][i];
			for (int k=0;k<n;k++)
				for (int l=0;l<1<<n;l++)
					if ((1<<k)&l)V[i][l]+=V[i][l^(1<<k)];
			for (int k=0;k<1<<n;k++)S[i][k]=max(S[i][k],V[i][k]);
		}
	printf("%d\n",dfs(1,0));
} 
int main(){
	for (int i=0;i<1<<12;i++)
		for (int j=0;j<1<<12;j++)
			if ((i&j)==j)K[i][++K[i][0]]=j;	
	scanf("%d",&T);
	while (T--){
		doit();
		memset(dp,0,sizeof dp);
		memset(flag,0,sizeof flag);
		memset(c,0,sizeof c);
		memset(S,0,sizeof S);
		memset(V,0,sizeof V); 
	}
}