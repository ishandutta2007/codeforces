//CF1534F1
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
const int N = 444444;
int n,m,w,a[N],f[N];
char ch[N];
vector<int> b[N],c[N];
vector<int> v[N],r[N];
int tt,t[N],vis[N],g[N],h[N];
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void dfsr(int u){
	vis[u]=1;
	int i,x;
	for(i=0;i<r[u].size();i++){
		x=r[u][i];
		if(!vis[x])
			dfsr(x);
	}
	t[++tt]=u;
}
void dfsv(int u,int gg){
	g[u]=gg;
	int i,x;
	for(i=0;i<v[u].size();i++){
		x=v[u][i];
		if(!g[x])
			dfsv(x,gg);
	}
}
int main()
{
	int i,j,x,y;
	scanf("%d%d",&n,&m);
	for(i=0;i<=n+1;i++){
		b[i].resize(m+2);
		c[i].resize(m+2);
	}
	for(i=1;i<=n;i++){
		scanf("%s",ch+1);
		for(j=1;j<=m;j++)
			b[i][j]=(ch[j]=='#'),c[i][j]=0;
	}
	for(j=1;j<=m;j++)
		scanf("%d",a+j);
	x=0;
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j])
				c[i][j]=++x,f[x]=x;
	w=x;
	for(i=1;i<n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j]&&b[i+1][j])
				f[fnd(c[i][j])]=fnd(c[i+1][j]);
	for(i=1;i<=n;i++)
		for(j=1;j<m;j++)
			if(b[i][j]&&b[i][j+1])
				f[fnd(c[i][j])]=fnd(c[i][j+1]);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			if(b[i][j])
				c[i][j]=fnd(c[i][j]);
	for(j=1;j<=m;j++){
		x=0;
		for(i=1;i<=n;i++){
			y=c[i][j-1]|c[i][j];
			if(x==y||!y)
				continue;
			if(x){
				v[x].push_back(y);
				r[y].push_back(x);
			}
			x=y;
		}
	}
	for(i=1;i<=w;i++)
		if(fnd(i)!=i)
			f[i]=0;
	tt=0;
	for(i=1;i<=w;i++)
		if(f[i]==i&&!vis[i])
			dfsr(i);
	for(i=tt;i>=1;i--)
		if(!g[t[i]])
			dfsv(t[i],t[i]);
	for(i=1;i<=w;i++){
		for(j=0;j<v[i].size();j++){
			x=v[i][j];
			if(g[i]!=g[x])
				h[g[x]]++;
		}
	}
	x=0;
	for(i=1;i<=w;i++)
		if(g[i]==i&&!h[i])
			x++;
	printf("%d\n",x);
	return 0;
}