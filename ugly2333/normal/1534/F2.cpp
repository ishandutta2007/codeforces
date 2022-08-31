//CF1534F
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
int o,p[N],fl[N],fr[N],d[N];
queue<int> q;
vector<int> v2[N];
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
	for(j=1;j<=m;j++)
		for(i=1;i<=n;i++)
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
			if(g[i]!=g[x]){
				v2[g[i]].push_back(g[x]);
				h[g[x]]++;
			}
		}
	}
	for(i=1;i<=w;i++)
		if(g[i]==i)
			fl[i]=N,fr[i]=-1;
	x=0;
	for(i=1;i<=w;i++)
		if(g[i]==i&&!h[i])
			x++,fl[i]=x,fr[i]=x,q.push(i);
	o=x;
	while(!q.empty()){
		x=q.front();
		q.pop();
		for(i=0;i<v2[x].size();i++){
			y=v2[x][i];
			h[y]--;
			fl[y]=min(fl[y],fl[x]);
			fr[y]=max(fr[y],fr[x]);
			if(!h[y])
				q.push(y);
		}
	}
	for(j=1;j<=m;j++){
		x=a[j];
		if(!x)
			continue;
		for(i=n;i>=1;i--){
			if(b[i][j]){
				x--;
				if(!x){
					p[j]=g[c[i][j]];
					break;
				}
			}
		}
	}
	for(i=1;i<=o;i++)
		d[i]=0;
	for(j=1;j<=m;j++)
		d[fr[p[j]]]=max(d[fr[p[j]]],fl[p[j]]);
	for(i=1;i<=o;i++)
		d[i]=max(d[i],d[i-1]);
	x=o;
	y=0;
	while(d[x]){
		y++;
		x=d[x]-1;
	}
	printf("%d\n",y);
	return 0;
}