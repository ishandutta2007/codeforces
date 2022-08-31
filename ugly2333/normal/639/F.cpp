//CF639E
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
const int N = 333333;
int cnt,nn;
int R(int x){
	cnt%=nn;
	x=(x+cnt)%nn;
	if(!x)
		return nn;
	return x;
}
int n,m,q,vis[N],d[N],f[N],p[N],g[N][22],h[N];
int a[N],qx[N],qy[N];
vector<int> v[N],c,r,cc;
vector<pair<int,int> > e1,e2;
int fnd(int x){
	if(f[x]==x)
		return x;
	return f[x]=fnd(f[x]);
}
void dfs(int u,int fa){
	int i,x,o=1;
	vis[u]=1;
	d[u]=d[fa]+1;
	for(i=v[u].size();i--;){
		x=v[u][i];
		if(x==fa&&o){
			o=0;
			continue;
		}
		if(vis[x]){
			if(d[x]<d[u])
				f[u]++,f[x]--;
		}
		else{
			dfs(x,u);
			f[u]+=f[x];
		}
	}
	if(!fa)
		return;
	if(f[u])
		e1.push_back(make_pair(fa,u));
	else
		e2.push_back(make_pair(fa,u));
}
void dfs2(int u){
	int i,x;
	vis[u]=1;
	f[u]=++m;
	for(i=v[u].size();i--;){
		x=v[u][i];
		dfs2(x);
		g[f[x]][0]=f[u];
	}
}
int lca(int x,int y){
	int j;
	if(h[x]<h[y])
		swap(x,y);
	for(j=19;h[x]>h[y];j=j-1)
		if(h[g[x][j]]>=h[y])
			x=g[x][j];
	if(x==y)
		return x;
	for(j=19;g[x][0]!=g[y][0];j=j-1)
		if(g[x][j]!=g[y][j])
			x=g[x][j],y=g[y][j];
	return g[x][0];
}
void adv(int x,int y){
	if(!x||!y)
		return;
	v[x].push_back(y);
	v[y].push_back(x);
}
int main()
{
	int i,j,x,y,z,o,qq;
	scanf("%d%d%d",&n,&m,&q);
	nn=n;
	while(m--){
		scanf("%d%d",&x,&y);
		adv(x,y);
	}
	memset(vis,0,sizeof(vis));
	memset(d,0,sizeof(d));
	memset(f,0,sizeof(f));
	e1.clear(),e2.clear();
	for(i=1;i<=n;i=i+1)
		if(!vis[i])
			dfs(i,0);
	for(i=1;i<=n;i=i+1)
		f[i]=i,v[i].clear();
	for(i=e1.size();i--;)
		f[fnd(e1[i].first)]=fnd(e1[i].second);
	for(i=1;i<=n;i=i+1)
		p[i]=fnd(i);
	for(i=e2.size();i--;){
		x=p[e2[i].first],y=p[e2[i].second];
		v[x].push_back(y);
	}
	memset(vis,0,sizeof(vis));
	memset(f,0,sizeof(f));
	m=0;
	for(i=1;i<=n;i=i+1)
		if(p[i]==i&&!vis[i])
			dfs2(i);
	for(i=1;i<=n;i=i+1)
		p[i]=f[p[i]];
	for(i=1;i<=m;i=i+1)
		h[i]=h[g[i][0]]+1;
	for(j=1;j<=19;j=j+1)
		for(i=1;i<=m;i=i+1)
			g[i][j]=g[g[i][j-1]][j-1];
	for(i=1;i<=n;i=i+1)
		v[i].clear();
	for(qq=1;qq<=q;qq++){
		scanf("%d%d",&n,&m);
		c.clear();
		for(i=1;i<=n;i=i+1){
			scanf("%d",&x);
			a[i]=p[R(x)];
			c.push_back(a[i]);
		}
		for(i=1;i<=m;i=i+1){
			scanf("%d%d",&x,&y);
			qx[i]=p[R(x)],qy[i]=p[R(y)];
			c.push_back(qx[i]);
			c.push_back(qy[i]);
		}
		sort(c.begin(),c.end());
		c.resize(unique(c.begin(),c.end())-c.begin());
		r.clear();
		r.push_back(0);
		cc.clear();
		for(i=0;i<c.size();){
			o=c[i];
			x=r[r.size()-1];
			z=lca(o,x);
			if(z==x){
				r.push_back(o);
				i++;
			}
			else{
				y=r[r.size()-2];
				if(y<z){
					cc.push_back(z);
					adv(z,x);
					r[r.size()-1]=z;
					r.push_back(o);
					i++;
				}
				else{
					adv(y,x);
					r.pop_back();
				}
			}
		}
		for(i=0;i<cc.size();i=i+1)
			c.push_back(cc[i]);
		sort(c.begin(),c.end());
		c.resize(unique(c.begin(),c.end())-c.begin());
		for(i=1;i<r.size();i=i+1)
			adv(r[i-1],r[i]);
		for(i=1;i<=m;i=i+1)
			adv(qx[i],qy[i]);
		for(i=0;i<c.size();i=i+1)
			vis[c[i]]=0,d[c[i]]=0,f[c[i]]=0;
		e1.clear(),e2.clear();
		for(i=0;i<c.size();i=i+1)	
			if(!vis[c[i]])
				dfs(c[i],0);
		for(i=0;i<c.size();i=i+1)
			f[c[i]]=c[i],v[c[i]].clear();
		for(i=e1.size();i--;)
			f[fnd(e1[i].first)]=fnd(e1[i].second);
		o=fnd(a[1]);
		j=1;
		for(i=1;i<=n;i=i+1)
			if(fnd(a[i])!=o)
				j=0;
		if(j)
			cout<<"YES\n",cnt+=qq;
		else
			cout<<"NO\n";
	}
	return 0;
}