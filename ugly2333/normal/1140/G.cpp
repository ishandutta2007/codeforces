//CF1140G
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
struct node{
	LL ab,ac,ad,bc,bd,cd;
	node(LL AB=0,LL CD=0,LL AC=0,LL BD=0){
		ab=AB;
		ac=min(AC,AB+BD+CD);
		ad=min(AB+BD,AC+CD);
		bc=min(AB+AC,BD+CD);
		bd=min(BD,AB+AC+CD);
		cd=CD;
	}
}f[N][20],p;
node operator+(node l,node r){
	node o;
	o.ab=l.ab;
	o.ac=min(l.ac+r.ac,l.ad+r.bc);
	o.ad=min(l.ac+r.ad,l.ad+r.bd);
	o.bc=min(l.bc+r.ac,l.bd+r.bc);
	o.bd=min(l.bc+r.ad,l.bd+r.bd);
	o.cd=r.cd;
	return o;
}
node rev(node o){
	swap(o.ab,o.cd);
	swap(o.ad,o.bc);
	return o;
}
int n,m,d[N],g[N][20];
LL w[N];
vector<int> v[N];
vector<LL> a[N],b[N];
priority_queue<pair<LL,int> > q;
void dfs(int u,int fa){
	d[u]=d[fa]+1;
	g[u][0]=fa;
	int i,x;
	for(i=v[u].size();i--;){
		x=v[u][i];
		if(x==fa)
			continue;
		dfs(x,u);
		f[x][0]=node(w[x],w[u],a[u][i],b[u][i]);
	}
}
int lca(int x,int y){
	int j;
	if(d[x]<d[y])
		swap(x,y);
	for(j=19;d[x]>d[y];j=j-1)
		if(d[g[x][j]]>=d[y])
			x=g[x][j];
	if(x==y)
		return x;
	for(j=19;g[x][0]!=g[y][0];j=j-1)
		if(g[x][j]!=g[y][j])
			x=g[x][j],y=g[y][j];
	return g[x][0];
}
node qu(int x,int y){
	int j,e=1;
	node o=node(w[x],w[x],0,0);
	for(j=19;d[x]>d[y];j=j-1)
		if(d[g[x][j]]>=d[y])
			o=o+f[x][j],x=g[x][j];
	return o;
}
int main()
{
	int i,j,x,y,t,e;
	LL z,o;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%lld",w+i);
	for(i=1;i<n;i=i+1){
		scanf("%d%d%lld%lld",&x,&y,&z,&o);
		v[x].push_back(y);
		v[y].push_back(x);
		a[x].push_back(z);
		a[y].push_back(z);
		b[x].push_back(o);
		b[y].push_back(o);
	}
	for(i=1;i<=n;i=i+1)
		q.push(make_pair(-w[i],i));
	while(!q.empty()){
		x=q.top().second;
		z=-q.top().first;
		q.pop();
		if(w[x]!=z)
			continue;
		for(i=v[x].size();i--;){
			y=v[x][i];
			o=z+a[x][i]+b[x][i];
			if(w[y]>o){
				w[y]=o;
				q.push(make_pair(-o,y));
			}
		}
	}
	dfs(1,0);
	for(j=1;j<=19;j=j+1)
		for(i=1;i<=n;i=i+1)
			g[i][j]=g[g[i][j-1]][j-1];
	for(j=1;j<=19;j=j+1)
		for(i=1;i<=n;i=i+1)
			if(g[i][j])
				f[i][j]=f[i][j-1]+f[g[i][j-1]][j-1];
	scanf("%d",&m);
	while(m--){
		scanf("%d%d",&x,&y);
		x++,y++;
		e=0;
		if(x&1)
			e+=2;
		if(y&1)
			e++;
		x/=2,y/=2;
		if(x==y){
			printf("%lld\n",w[x]);
			continue;
		}
		t=lca(x,y);
		if(x==t||y==t){
			if(y==t)
				p=qu(x,y);
			else
				p=rev(qu(y,x));
		}
		else
			p=qu(x,t)+rev(qu(y,t));
		if(e==0)
			printf("%lld\n",p.ac);
		if(e==1)
			printf("%lld\n",p.ad);
		if(e==2)
			printf("%lld\n",p.bc);
		if(e==3)
			printf("%lld\n",p.bd);
	}
	return 0;
}