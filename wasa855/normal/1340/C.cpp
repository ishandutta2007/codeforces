#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define fir first
#define sec second
#define mod 998244353
#define ll long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
inline int min(int x,int y,int z){return min(x,min(y,z));}
inline int max(int x,int y,int z){return max(x,max(y,z));}
inline int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
inline int add(int x,int y,int z){return add(add(x,y),z);}
inline int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
inline int mul(int x,int y){return 1LL*x*y%mod;}
inline int mul(int x,int y,int z){return mul(mul(x,y),z);}
int dis[10005][1005];
bool vis[10005][1005];
int a[10005];
signed main()
{
	int n,m; cin>>n>>m;
	for(int i=1;i<=m;i++) a[i]=read(); sort(a+1,a+m+1);
	int g,r; cin>>g>>r;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<g;j++) dis[i][j]=inf;
	}
	dis[1][0]=0; vis[1][0]=1;
	deque<pii> q; q.push_back(mp(1,0));
	while(!q.empty())
	{
		pii u=q.front(); q.pop_front();
		if(!q.empty())
		{
			pii R=q.back(); q.pop_back();
			if(dis[u.fir][u.sec]>dis[R.fir][R.sec]) swap(u,R);
			q.push_back(R);
		}
		if(u.fir!=1)
		{
			pii v=mp(u.fir-1,u.sec+a[u.fir]-a[u.fir-1]);
			if(v.sec<g)
			{
				if(dis[v.fir][v.sec]>dis[u.fir][u.sec]+a[u.fir]-a[u.fir-1])
				{
					dis[v.fir][v.sec]=dis[u.fir][u.sec]+a[u.fir]-a[u.fir-1];
					q.push_back(v);
				}
			}
			if(v.sec==g)
			{
				if(dis[v.fir][0]>dis[u.fir][u.sec]+a[u.fir]-a[u.fir-1]+r)
				{
					dis[v.fir][0]=dis[u.fir][u.sec]+a[u.fir]-a[u.fir-1]+r;
					q.push_back(mp(v.fir,0));
				}
			}
		}
		if(u.fir!=m)
		{
			pii v=mp(u.fir+1,u.sec+a[u.fir+1]-a[u.fir]);
			if(v.sec<g)
			{
				if(dis[v.fir][v.sec]>dis[u.fir][u.sec]+a[u.fir+1]-a[u.fir])
				{
					dis[v.fir][v.sec]=dis[u.fir][u.sec]+a[u.fir+1]-a[u.fir];
					q.push_back(v);
				}
			}
			if(v.sec==g)
			{
				int w=a[u.fir+1]-a[u.fir];
				if(v.fir!=m) w+=r;
				if(dis[v.fir][0]>dis[u.fir][u.sec]+w)
				{
					dis[v.fir][0]=dis[u.fir][u.sec]+w;
					q.push_back(mp(v.fir,0));
				}
			}
		}
	}
	int ans=inf;
	for(int i=0;i<g;i++) if(dis[m][i]<ans) ans=dis[m][i];
	if(ans!=inf) cout<<ans<<endl;
	else cout<<-1<<endl;
	return 0;
}