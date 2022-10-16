#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define mod 1000000007
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int dis0[maxn+5],dis1[maxn+5],dis2[maxn+5],bel[maxn+5],di[maxn+5];
vi f[maxn+5],p[maxn+5],buf;
vector<ll> ps[maxn+5];


int farv,fard;

void dfs(int now,int fa,int id,int dis[])
{
	buf.pb(now);
	bel[now]=id;
	if(dis[now]>fard) farv=now,fard=dis[now];
	for(auto v: e[now]) if(v!=fa)
	{
		dis[v]=dis[now]+1;
		dfs(v,now,id,dis);
	}
}

int main()
{
	int n,m,Q; scanf("%d%d%d",&n,&m,&Q);
	rep(i,1,m) 
	{
		int x,y; scanf("%d%d",&x,&y);
		e[x].pb(y); e[y].pb(x);
	}
	rep(now,1,n) if(bel[now]==0)
	{
		farv=now; fard=0;
		dfs(now,0,now,dis0);
		fard=0;
		dfs(farv,0,now,dis1);
		di[now]=fard;
		buf.clear();
		dfs(farv,0,now,dis2);

		int N=buf.size();
		f[now].resize(N,0);
		p[now].resize(N,0);
		ps[now].resize(N,0);
		for(auto x: buf) f[now][max(dis1[x],dis2[x])]++;
		p[now][0]=f[now][0];
		rep(i,1,N-1) p[now][i]=p[now][i-1]+f[now][i];
		rep(i,1,N-1) ps[now][i]=ps[now][i-1]+1ll*i*f[now][i];
	}
	map<pii,db> MP;
	while(Q--)
	{
		int x,y; scanf("%d%d",&x,&y);
		if(bel[x]==bel[y]) puts("-1");
		else
		{
			x=bel[x]; y=bel[y];
			if(f[x].size()>f[y].size()) swap(x,y);
			if(MP.find(mp(x,y))!=MP.end()) printf("%.10f\n",MP[mp(x,y)]);
			else
			{
				ll ans=0;
				int D=max(di[x],di[y]);
				int N=f[x].size(),M=f[y].size();
				rep(i,0,N-1)
				{
					int j=D-i-1; j=min(j,M-1);
					if(j<0) ans+=1ll*f[x][i]*(ps[y][M-1]+1ll*p[y][M-1]*(i+1));
					else ans+=1ll*f[x][i]*(1ll*p[y][j]*D+ps[y][M-1]-ps[y][j]+1ll*(p[y][M-1]-p[y][j])*(i+1));
				}
				MP[mp(x,y)]=(db)ans/(1ll*N*M);
				printf("%.10f\n",MP[mp(x,y)]);
			}
			
		}
	}
	
	return 0;
}