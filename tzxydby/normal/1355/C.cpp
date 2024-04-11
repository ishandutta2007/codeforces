#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct flow
{
	static const int N=200005,INF=1e9;
	int n,s,t;
	struct edge
	{
		int v,w,f,c,nxt;
	}e[N];
	int head[N],cur[N],cnt;
	void addedge(int u,int v,int w,int f,int c)
	{
		cnt++;
		e[cnt].v=v,e[cnt].w=w,e[cnt].f=f,e[cnt].c=c;
		e[cnt].nxt=head[u];
		head[u]=cnt;
	}
	void add(int u,int v,int w,int c=0)
	{
		addedge(u,v,w,w,c);
		addedge(v,u,w,0,-c);
	}
	int dep[N],q[N];
	int bfs()
	{
		for(int i=1;i<=n;i++)
			dep[i]=-1,cur[i]=head[i];
		dep[s]=0;
		int l=0,r=1;
		q[0]=s;
		while(l<r)
		{
			int u=q[l++];
			for(int i=head[u];i;i=e[i].nxt)
			{
				if(dep[e[i].v]==-1&&e[i].f>0)
				{
					dep[e[i].v]=dep[u]+1;
					q[r++]=e[i].v;
				}
			}
		}
		return dep[t]!=-1;
	}
	int dfs(int u,int lim)
	{
		if(u==t||lim==0)
			return lim;
		int flow=0,f;
		for(int i=cur[u];i;i=e[i].nxt)
		{
			cur[u]=i;
			if(dep[e[i].v]==dep[u]+1&&(f=dfs(e[i].v,min(lim,e[i].f))))
			{
				flow+=f;
				lim-=f;
				e[i].f-=f;
				e[(i-1^1)+1].f+=f;
				if(!lim)
					break;
			}
		}
		return flow;
	}
	int max_flow()
	{
		int mf=0;
		while(bfs())
			mf+=dfs(s,INF);
		return mf;
	}
	int h[N],dis[N],pre[N],pu[N];
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	int min_cost(int f)
	{
		int res=0;
		for(int i=1;i<=cnt;i+=2)
			e[i].f=e[i].w;
		for(int i=2;i<=cnt;i+=2)
			e[i].f=0;
		while(f>0)
		{
			for(int i=1;i<=n;i++)
				dis[i]=INF;
			dis[s]=0;
			pq.emplace(0,s);
			while(!pq.empty())
			{
				auto p=pq.top();
				pq.pop();
				int u=p.second;
				if(dis[u]<p.first)
					continue;
				for(int i=head[u];i;i=e[i].nxt)
				{
					int v=e[i].v,c=e[i].c,f=e[i].f;
					if(f>0&&dis[v]>dis[u]+c+h[u]-h[v])
					{
						dis[v]=dis[u]+c+h[u]-h[v];
						pre[v]=i,pu[v]=u;
						pq.emplace(dis[v],v);
					}
				}
			}
			if(dis[t]==INF)
				return -1;
			for(int i=1;i<=n;i++)
				h[i]+=dis[i];
			int d=f;
			for(int u=t;u!=s;u=pu[u])
				d=min(d,e[pre[u]].f);
			f-=d;
			res+=d*h[t];
			for(int u=t;u!=s;u=pu[u])
			{
				e[pre[u]].f-=d;
				e[(pre[u]-1^1)+1].f+=d;
			}
		}
		return res;
	}
}g;
int main()
{
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (ll i = a; i <= b; i++)
    {
        ll x = i;
        ll y = max(c + 1 - x, b);
        if (y <= c)
        {
            int z = min(x + y - 1, d);
            if (z == d)
            {
                ans += (d - c + 1) * (c - y + 1);
            }
            else
            {

                ll l = z - c + 1;
                ll r = (c - y) + l;
                if (r <= d - c + 1)
                {
                    ans += (1 + r) * r / 2;
                    ans -= (1 + l - 1) * (l - 1) / 2;
                }
                else
                {
                    ll num = r - (d - c + 1);
                    r = d - c + 1;
                    ans += (1 + r) * r / 2+num * (d - c + 1);
                    ans -= (1 + l - 1) * (l - 1) / 2;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}