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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 600005
int u[N],v[N],w[N],n,m;
int cnt[N][3],vis[N];
struct Edge{int v,id,nxt;};
Edge edge[N];
int fir[N],ans[N],vis2[N],ss;
void add(int u,int v,int id)
{
	// printf("%d %d %d\n",u,v,id);
	edge[++ss]=(Edge){v,id,fir[u]}; fir[u]=ss;
	edge[++ss]=(Edge){u,-id,fir[v]}; fir[v]=ss;
}
void dfs(int u)
{
	vis2[u]=1;
	for(int i=fir[u];i!=0;i=fir[u])
	{
		while(ans[abs(edge[i].id)]) i=edge[i].nxt;
		fir[u]=i;
		if(!i) break;
		if(edge[i].id<0) ans[-edge[i].id]=2;
		else ans[edge[i].id]=1;
		// printf("^ %d\n",edge[i].id);
		dfs(edge[i].v);
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		u[i]=read(),v[i]=read(),w[i]=read();
		cnt[u[i]][w[i]]++,cnt[v[i]][w[i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(cnt[i][1]%2==1&&cnt[i][2]%2==1) vis[i]=0;
		else vis[i]=1;
	}
	for(int i=1;i<=m;i++)
	{
		if(w[i]==2) add(u[i]+n,v[i]+n,i);
		else
		{
			int A=u[i],B=v[i];
			if(!vis[u[i]]) A=u[i]+n,vis[u[i]]=1;
			if(!vis[v[i]]) B=v[i]+n,vis[v[i]]=1;
			add(A,B,i);
		}
	}
	int q=m;
	for(int i=1;i<=n;i++)
	{
		int r=cnt[i][1]%2+(cnt[i][2]%2)*2;
		if(r==1) add(i,n+n+1,++q);
		if(r==2) add(i+n,n+n+1,++q);
	}
	// return 0;
	// dfs(1);
	for(int i=1;i<=n+n+1;i++) if(!vis2[i]) dfs(i);
	int ans=0;
	for(int i=1;i<=n;i++) ans+=cnt[i][1]&1;
	cout<<ans<<endl;
	for(int i=1;i<=m;i++) printf("%d",::ans[i]);
	return 0;
}