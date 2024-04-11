#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
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
#define N 200005
vector<int> G[N];
int dgr[N],dep[N];
void work()
{
	int n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		G[u].pb(v); dgr[v]++;
	}
	vector<int> ans; queue<int> q;
	for(int i=1;i<=n;i++) if(!dgr[i]) q.push(i),dep[i]=1;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		if(dep[u]==3) ans.pb(u);
		int id=dep[u]+1;
		if(dep[u]==3) id=1; 
		for(int v:G[u])
		{
			if(dep[v]<id) dep[v]=id;
			dgr[v]--;
			if(!dgr[v]) q.push(v);
		}
	}
	cout<<ans.size()<<endl;
	for(int i:ans) printf("%d ",i); puts("");
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<=n;i++) dep[i]=0;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}