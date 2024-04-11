//CF 1023F
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
const int N = 555555;
const int inf = 2e9;
void cmin(int&x,int y){
	if(x>y)
		x=y;
}
int ff[N];
int fnd(int x){
	if(ff[x]==x)
		return x;
	return ff[x]=fnd(ff[x]);
}
int n,k,m,a[N],b[N],w[N];
vector<int> v[N];
int d[N],f[N][22],g[N][22];
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	f[u][0]=fa;
	int i=v[u].size(),x;
	while(i--){
		x=v[u][i];
		if(x!=fa)
			dfs(x,u);
	}
}
void solve(int x,int y,int z){
	int j;
	if(d[x]<d[y])
		swap(x,y);
	for(j=20;j>=0;j=j-1)
		if(d[f[x][j]]>=d[y])
			cmin(g[x][j],z),x=f[x][j];
	if(x==y)
		return;
	for(j=20;j>=0;j=j-1)
		if(f[x][j]!=f[y][j])
			cmin(g[x][j],z),x=f[x][j],cmin(g[y][j],z),y=f[y][j];
	cmin(g[x][0],z),cmin(g[y][0],z);
}
int main()
{
	int i,j,x,y,z;
	LL ans=0;
	scanf("%d%d%d",&n,&k,&m);
	for(i=1;i<=n;i=i+1)
		ff[i]=i;
	for(i=1;i<=k;i=i+1){
		scanf("%d%d",&x,&y);
		ff[fnd(x)]=fnd(y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(i=1;i<=m;i=i+1){
		scanf("%d%d%d",&x,&y,&z);
		a[i]=x,b[i]=y,w[i]=z;
		if(fnd(x)!=fnd(y)){
			ff[fnd(x)]=fnd(y);
			v[x].push_back(y);
			v[y].push_back(x);
			ans-=z;
		}
	}
	dfs(1,0);
	for(j=1;j<=20;j=j+1)
		for(i=1;i<=n;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	for(j=0;j<22;j=j+1)
		for(i=1;i<=n;i=i+1)
			g[i][j]=inf;
	for(i=1;i<=m;i=i+1)
		solve(a[i],b[i],w[i]);
	for(j=20;j;j=j-1)
		for(i=1;i<=n;i=i+1)
			cmin(g[i][j-1],g[i][j]),cmin(g[f[i][j-1]][j-1],g[i][j]);
	for(i=1;i<=n;i=i+1)
		if(f[i][0]){
			if(g[i][0]>=inf){
				cout<<-1;
				return 0;
			}
			ans+=g[i][0];
		}
	cout<<ans;
	return 0;
}