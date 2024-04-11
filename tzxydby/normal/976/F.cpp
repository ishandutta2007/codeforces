#include<bits/stdc++.h>
using namespace std;
class EK
{
public:
	EK(int n):n(n){f.assign(n,vector<int>(n,0));}
	int n;
	vector<vector<int>>f,a;
	void pre()
	{
		a.resize(n);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(f[i][j]||f[j][i])
					a[i].push_back(j);
	}
	int maxflow(int s,int t)
	{
		int c=0,d;
		vector<int>p(n);
		while((d=bfs(s,t,p)))
		{
			c+=d;
			int x=t;
			while(x!=s)
			{
				int y=p[x];
				f[y][x]-=d;
				f[x][y]+=d;
				x=y;
			}
		}
		return c;
	}
	int bfs(int s,int t,vector<int>&p)
	{
		fill(p.begin(),p.end(),-1);
		p[s]=-2;
		queue<pair<int,int>>q;
		q.emplace(s,INT_MAX);
		while(!q.empty())
		{
			int u,x;
			tie(u,x)=q.front();
			q.pop();
			for(auto v:a[u])
			{
				if(p[v]==-1&&f[u][v])
				{
					p[v]=u;
					int y=min(x,f[u][v]);
					if(v==t)
						return y;
					q.emplace(v,y);
				}
			}
		}
		return 0;
	}
};
int n1,n2,n,m;
int main()
{
	scanf("%d%d%d",&n1,&n2,&m);
	n=n1+n2+4;
	vector<pair<int,int>>e(m);
	vector<int>d(n1+n2,0);
	for(int i=0;i<m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		u--,v--,v+=n1;
		e[i]={u,v};
		d[u]++,d[v]++;
	}
	int mn=m;
	for(auto i:d)
		mn=min(mn,i);
	EK ek(n);
	auto calc=[&](int deg)
	{
		auto& f=ek.f;
		for(auto& x:e)
		{
			f[x.first][x.second]=0;
			f[x.second][x.first]=0;
		}
		for(auto& x:e)
			f[x.first][x.second]++;
		for(int u=0;u<n1;u++)
		{
			f[n-2][u]=deg;
			f[u][n-2]=0;
			f[n-4][u]=m;
			f[u][n-4]=0;
		}
		f[n-2][n-3]=deg*n2;
		f[n-3][n-2]=0;
		for(int v=n1;v<n1+n2;v++)
		{
			f[v][n-1]=deg;
			f[n-1][v]=0;
			f[v][n-3]=m;
			f[n-3][v]=0;
		}
		f[n-4][n-1]=deg*n1;
		f[n-1][n-4]=0;
		f[n-3][n-4]=1;
		f[n-4][n-3]=0;
	};
	calc(1);
	ek.pre();
	puts("0");
	for(int deg=1;deg<=mn;deg++)
	{
		int l=deg*max(n1,n2)-1,r=m;
		while(r-l>1)
		{
			int mid=l+r>>1;
			calc(deg);
			ek.f[n-3][n-4]=mid;
			int flow=ek.maxflow(n-2,n-1);
			if(flow==deg*(n1+n2))
				r=mid;
			else
				l=mid;
		}
		calc(deg);
		ek.f[n-3][n-4]=r;
		ek.maxflow(n-2,n-1);
		printf("%d ",r);
		for(int i=0;i<m;i++)
		{
			int u=e[i].first,v=e[i].second;
			if(ek.f[v][u]>0)
			{
				printf("%d ",i+1);
				ek.f[v][u]--;
			}
		}
		puts("");
	}
	return 0;
}