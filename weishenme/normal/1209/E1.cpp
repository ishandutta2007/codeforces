#include<bits/stdc++.h>
using namespace std;
const int N=13,M=2005;
int a[N][N],b[N][M],c[M],d[M],dp[N][1<<N],flag[N][1<<N],n,m,T;
int dfs(int x,int y){
	if (x==m+1)return 0;
	if (flag[x][y])return dp[x][y];
	flag[x][y]=1;
	int b[20],c[20],tot=0;
	for (int i=0;i<n;i++)
		if (!((1<<i)&y))b[tot++]=i;
	for (int i=0;i<n;i++){
		memset(c,0,sizeof c); 
		for (int j=0;j<n;j++)c[j]=max(c[j],a[(j+i)%n][x]);
		for (int j=0;j<1<<tot;j++){
			int num=0,num2=0;
			for (int k=0;k<tot;k++)
				if ((1<<k)&j)num+=1<<b[k],num2+=c[b[k]];
			dp[x][y]=max(dp[x][y],dfs(x+1,y|num)+num2);		
		}
	}
	return dp[x][y];
}
int cmp(int x,int y){
	return c[x]>c[y];
}
void doit(){
	scanf("%d%d",&n,&m);
	for (int i=0;i<n;i++)
		for (int j=1;j<=m;j++)scanf("%d",&b[i][j]),c[j]=max(c[j],b[i][j]);
	for (int i=1;i<=m;i++)d[i]=i;
	sort(d+1,d+m+1,cmp);
	for (int i=1;i<=n&&i<=m;i++)
		for (int j=0;j<n;j++)a[j][i]=b[j][d[i]];
	m=min(n,m);
	printf("%d\n",dfs(1,0));	
} 
int main(){
	scanf("%d",&T);
	while (T--){
		doit();
		memset(dp,0,sizeof dp);
		memset(flag,0,sizeof flag);
		memset(c,0,sizeof c);
	}
}