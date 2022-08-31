//CF 983E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 222222;
int n,d[N],f[N][22],g[N][22];
int tt,tin[N],tout[N];
int m,q,ans[N],p[N];
vector<int> v[N],h[N];
vector<pair<int,int> > r[N][2];
int t[N];
void dfs1(int u,int fa){
	d[u]=d[fa]+1;
	f[u][0]=fa;
	tin[u]=++tt;
	for(int i=v[u].size();i--;)
		dfs1(v[u][i],u);
	tout[u]=tt;
}
int lca(int x,int y){
	int j;
	if(d[x]<d[y])
		swap(x,y);
	for(j=19;d[x]>d[y];j=j-1)
		if(d[f[x][j]]>=d[y])
			x=f[x][j];
	if(x==y)
		return x;
	for(j=19;f[x][0]!=f[y][0];j=j-1)
		if(f[x][j]!=f[y][j])
			x=f[x][j],y=f[y][j];
	return f[x][0];
}
void dfs2(int u,int fa){
	for(int i=v[u].size();i--;)
		dfs2(v[u][i],u);
	if(d[g[fa][0]]>d[g[u][0]])
		g[fa][0]=g[u][0];
}
int ef(int x,int y,int z){
	int j,e=0;
	for(j=19;j>=0&&d[x]>d[y];j=j-1)
		if(d[g[x][j]]>d[y])
			x=g[x][j],e+=1<<j;
	if(d[g[x][0]]<=d[y]){
		ans[z]+=e;
		return x;
	}
	ans[z]=-1e9;
	return 0;
}
void ad(int x){
	if(!x)
		return;
	for(;x<=n;x+=x&-x)
		t[x]++;
}
int qu(int x){
	int y;
	for(y=0;x;x-=x&-x)
		y+=t[x];
	return y;
}
int main()
{
	int i,j,x,y,z;
	scanf("%d",&n);
	for(i=2;i<=n;i=i+1){
		scanf("%d",&x);
		v[x].push_back(i);
	}
	dfs1(1,0);
	for(j=1;j<20;j=j+1)
		for(i=1;i<=n;i=i+1)
			f[i][j]=f[f[i][j-1]][j-1];
	for(i=1;i<=n;i=i+1)
		g[i][0]=i;
	scanf("%d",&m);
	for(i=1;i<=m;i=i+1){
		scanf("%d%d",&x,&y);
		if(tin[x]>tin[y])
			swap(x,y);
		z=lca(x,y);
		if(d[g[x][0]]>d[z])
			g[x][0]=z;
		if(d[g[y][0]]>d[z])
			g[y][0]=z;;
		h[tin[x]].push_back(tin[y]);
	}
	dfs2(1,0);
	for(j=1;j<20;j=j+1)
		for(i=1;i<=n;i=i+1)
			g[i][j]=g[g[i][j-1]][j-1];
	scanf("%d",&q);
	for(i=1;i<=q;i=i+1){
		scanf("%d%d",&x,&y);
		if(tin[x]>tin[y])
			swap(x,y);
		z=lca(x,y);
		ans[i]=1;
		x=ef(x,z,i);
		y=ef(y,z,i);
		if(ans[i]>0){
			if(x!=z){
				r[tout[x]][1].push_back(make_pair(tout[y],i));
				r[tin[x]-1][0].push_back(make_pair(tout[y],i));
				r[tout[x]][0].push_back(make_pair(tin[y]-1,i));
				r[tin[x]-1][1].push_back(make_pair(tin[y]-1,i));
				ans[i]++;
			}
		}
		else
			ans[i]=-1;
	}
	for(i=1;i<=n;i=i+1){
		for(j=h[i].size();j--;)
			ad(h[i][j]);
		for(j=r[i][0].size();j--;)
			p[r[i][0][j].second]-=qu(r[i][0][j].first);
		for(j=r[i][1].size();j--;)
			p[r[i][1][j].second]+=qu(r[i][1][j].first);
	}
	for(i=1;i<=q;i=i+1){
		if(p[i])
			ans[i]--;
		printf("%d\n",ans[i]);
	}
	return 0;
}