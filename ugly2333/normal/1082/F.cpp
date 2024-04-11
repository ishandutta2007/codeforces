//CF1082F
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 555;
const int K = 11;
const int inf = 1e9;
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
int n=1,k,a[N],b[N],d[N],e[N][K],f[N][N][K],g[K];
char ch[N];
int l,w;
int ad(int u,int i){
	if(!u)
		u=++n;
	d[u]=i;
	if(i==l){
		a[u]+=w;
		return u;
	}
	e[u][ch[i]-'0']=ad(e[u][ch[i]-'0'],i+1);
	return u;
}
void go(int u,int x){
	int i,j,o;
	for(i=1;i<=n;i=i+1){
		if(!b[i])
			continue;
		for(j=0;j<=k;j=j+1)
			g[j]=inf;
		for(j=0;j<=k;j=j+1)
			for(o=0;o+j<=k;o=o+1)
				cmin(g[j+o],f[u][i][j]+min(f[x][i][o],f[x][x][o]));
		for(j=0;j<=k;j=j+1)
			f[u][i][j]=g[j];
	}
}
void dfs(int u){
	b[u]=1;
	int i,j;
	for(i=1;i<=n;i=i+1)
		for(j=0;j<=k;j=j+1)
			if(!b[i])
				f[u][i][j]=inf;
	for(i=0;i<=9;i=i+1)
		if(e[u][i])
			dfs(e[u][i]),go(u,e[u][i]);
	for(i=1;i<=n;i=i+1)
		for(j=0;j<=k;j=j+1)
			if(b[i])
				f[u][i][j]+=a[u]*(d[u]-d[i]);
	if(u==1)
		return;
	for(j=k;j;j=j-1)
		f[u][u][j]=f[u][u][j-1];
	f[u][u][0]=inf;
	b[u]=0;
}
int main()
{
	int m,i,j;
	cin>>m>>k;
	while(m--){
		cin>>ch>>w;
		l=strlen(ch);
		ad(1,0);
	}
	dfs(1);
	cout<<f[1][1][k];
	return 0;
}