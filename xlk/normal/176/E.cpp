#include<stdio.h>
#include<iostream>
#include<vector>
#include<set>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef long long ll;
typedef pair<int,int>ii;
int d[100020],f[100020][17],p[100020],r[100020];
int n,m,x,y,w,cnt,q;
vector<ii>a[100020];
ll z,g[100020];
set<int>s;
set<int>::iterator it,L,R;
char o;
int lca(int x,int y)
{
	if(d[x]<d[y])
		swap(x,y);
	int w=d[x]-d[y];
	for(int i=0;i<17;i++)
		if(w>>i&1)
			x=f[x][i];
	if(x==y)
		return x;
	for(int i=17;i--;)
		if(f[x][i]!=f[y][i])
			x=f[x][i],y=f[y][i];
	return f[x][0];
}
void dfs(int x,int y,ll w)
{
	d[x]=d[y]+1;
	g[x]=w;
	f[x][0]=y;
	p[r[x]=++cnt]=x;
	for(int i=1;i<17;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	fe(i,a[x])
		if(i->X!=y)
			dfs(i->X,x,w+i->Y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		a[x].push_back(ii(y,w));
		a[y].push_back(ii(x,w));
	}
	dfs(1,0,0);
	for(scanf("%d",&q);q--;)
	{
		scanf(" %c",&o);
		if(o=='?')
			cout<<z<<endl;
		else
		{
			scanf("%d",&x);
			it=s.insert(r[x]).first,L=it,R=it;
			if(L--==s.begin())
				L=--s.end();
			if(++R==s.end())
				R=s.begin();
			ll l=g[x]+g[lca(p[*L],p[*R])]-g[lca(x,p[*L])]-g[lca(x,p[*R])];
			if(o=='+')
				z+=l;
			else
				z-=l,s.erase(r[x]);
		}
	}
}