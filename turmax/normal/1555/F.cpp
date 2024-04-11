#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
const int maxn=3e5+5;
vector <pair<int,int> > a[maxn];
bool used[maxn];
int u[maxn][20];
int tin[maxn];
int tout[maxn];
int pr[maxn];
int timer=0;
set <pair<int,int> > d;
int t[4*maxn];
int c[maxn];
void pl(int node,int tl,int tr,int l,int r)
{
	if(tl>=r || tr<=l) return;
	if(tl>=l && tr<=r)
	{
		t[node]++;
		return;
	}
	int tm=(tl+tr)/2;
	pl(2*node+1,tl,tm,l,r);pl(2*node+2,tm,tr,l,r);
}
int get(int node,int tl,int tr,int pos)
{
	if(tl>pos || tr<=pos) return 0;
	if((tr-tl)==1) return t[node];
    int tm=(tl+tr)/2;
    if(tm>pos) return t[node]+get(2*node+1,tl,tm,pos);
    else return t[node]+get(2*node+2,tm,tr,pos);
}
int get1(int x) {return get(0,0,maxn,tin[x]);}
void pl1(int x) {pl(0,0,maxn,tin[x],tout[x]);}
void dfs(int x)
{
    used[x]=true;
	tin[x]=timer;
	++timer;
	for(int i=1;i<20;++i)
	{
		if(u[x][i-1]==(-1)) u[x][i]=(-1);
		else u[x][i]=u[u[x][i-1]][i-1];
	}
	for(auto o:a[x])
	{
		int v=o.first;int w=o.second;
		if(!used[v])
		{
			c[v]=c[x]^w;
			pr[v]=x;
			u[v][0]=x;
			dfs(v);
		}
	}
	tout[x]=timer;
}
bool pred(int x,int y)
{
	return ((x==(-1)) || (tin[x]<=tin[y] && tout[x]>=tout[y]));
}
int lca(int x,int y,int l=20)
{
	if(pred(x,y)) return x;
	if(pred(u[x][0],y)) return u[x][0];
	for(int i=1;i<l;++i)
	{
		if(pred(u[x][i],y))
		{
			return lca(u[x][i-1],y,i-1);
		}
	}
}
int parent[maxn];
int get(int x)
{
	if(parent[x]==(-1)) return x;
	int ans=get(parent[x]);
	parent[x]=ans;
	return ans;
}
void merg(int x,int y)
{
	x=get(x);y=get(y);
	if(x==y) return;
	parent[x]=y;
}
vector <vector <int> > z;
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	u[0][0]=(-1);pr[0]=(-1);
	for(int i=0;i<maxn;++i) parent[i]=(-1);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<m;++i)
	{
		int x,y,w;
		cin>>x>>y>>w;
		x--;y--;
		z.push_back({x,y,w});
	}
	for(int i=0;i<m;++i)
	{
		int x=z[i][0];int y=z[i][1];int w=z[i][2];
		if(get(x)!=get(y))
		{
			a[x].push_back({y,w});a[y].push_back({x,w});
			d.insert({x,y});d.insert({y,x});
			merg(x,y);
		}
	}
	for(int i=0;i<n;++i) if(!used[i]) {u[i][0]=(-1);pr[i]=(-1);dfs(i);}
	int sumv=0;
	for(auto h:z)
	{
		assert(sumv<=(3*n));
		int x=h[0];int y=h[1];int w=h[2];
		if(d.count({x,y}))
		{
			cout<<"YES"<<'\n';
			continue;
		}
		else
		{
			if(c[x]==(c[y]^w))
			{
				cout<<"NO"<<'\n';
				continue;
			}
			int o=lca(x,y);
			if(get1(x)+get1(y)==2*get1(o))
			{
				cout<<"YES"<<'\n';
				vector <int> v={x,y};
				int x1=x;
				while(x1!=o)
				{
					x1=pr[x1];
					v.push_back(x1);
				}
				int y1=y;
				while(y1!=o)
				{
					y1=pr[y1];
					v.push_back(y1);
				}
				for(auto h:v)
				{
					if(h!=o) pl1(h);
				}
				sumv+=v.size();
				continue;
			}
			else
			{
				cout<<"NO"<<'\n';
				continue;
			}
		}
	}
	return 0;
}