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
#define N 400005
vector<int> G[N];
int n,Q;
vector<pii> ch[N];
int fa[N],dep[N],u[N],v[N],len[N];
char str[N];
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1,fa[u]=f;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs1(v,u);
	}
}
struct Edge{int v,nxt;};
Edge edge[N*30*4];
int fir[N*30],ss,cnt;
char s[N];
void add(int u,int v)
{
	edge[++ss]=(Edge){v,fir[u]};
	fir[u]=ss;
}
int nd[26];
/*
int fa[N];
int find(int u) {return fa[u]==u?u:fa[u]=find(fa[u]);}
void merge(int u,int v) {fa[find(u)]=find(v);}
vector<int> v[26];
*/
// bool cmp(pii x,pii y) {return x.sec<y.sec;}
int low[N*30],dfn[N*30],bel[N*30],st[N*30],tp,dfscnt,comcnt;
bitset<N*30> vis;
void tarjan(int u)
{
	low[u]=dfn[u]=++dfscnt;
	st[++tp]=u,vis[u]=1;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],low[v]);
	}
	if(low[u]==dfn[u])
	{
		comcnt++;
		while(1)
		{
			int nd=st[tp--]; vis[nd]=0;
			bel[nd]=comcnt;
			if(nd==u) break;
		}
	}
}
int fl[N],ans[N];
signed main()
{
	// cout<<sizeof(edge)/1024.0/1024.0<<endl;
	cin>>n>>Q; cnt=Q*2+1;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0);
	int m=0;
	for(int i=1;i<=Q;i++)
	{
		int u=read(),v=read();
		scanf("%s",s+1);
		int len=strlen(s+1);
		::u[i]=u,::v[i]=v,::len[i]=len;
		for(int j=1;j<=len;j++) str[++m]=s[j];
		int l1=1,r1=len,l2=1,r2=len;
		while(u!=v)
		{
			if(dep[u]>dep[v])
			{
				ch[u].eb(i*2,s[l1++]);
				ch[u].eb(i*2+1,s[r2--]);
				u=fa[u];
			}
			else
			{
				ch[v].eb(i*2,s[r1--]);
				ch[v].eb(i*2+1,s[l2++]);
				v=fa[v];
			}
		}
		ch[u].eb(i*2,s[l1]),ch[u].eb(i*2+1,s[l2]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<26;j++) nd[j]=++cnt;
		for(auto [id,c]:ch[i]) add(nd[c-'a'],id^1);
		for(auto [id,c]:ch[i])
		{
			for(int j=0;j<26;j++)
			{
				if(c-'a'==j) continue;
				add(id,nd[j]);
			}
		}
	}
	for(int i=1;i<=cnt;i++) if(!dfn[i]) tarjan(i);
	int pos=0;
	for(int i=1;i<=n;i++) ans[i]='c';
	for(int i=1;i<=Q;i++)
	{
		if(bel[i*2+1]==bel[i*2]) cout<<"NO\n",exit(0);
		if(bel[i*2]<bel[i*2+1])
		{
			int l=pos+1,r=pos+len[i]; pos+=len[i];
			int u=::u[i],v=::v[i];
			while(u!=v)
			{
				if(dep[u]>dep[v]) ans[u]=str[l++],u=fa[u];
				else ans[v]=str[r--],v=fa[v];
			}
			ans[u]=str[l];
		}
		else
		{
			int l=pos+1,r=pos+len[i]; pos+=len[i];
			int u=::u[i],v=::v[i];
			swap(u,v);
			while(u!=v)
			{
				if(dep[u]>dep[v]) ans[u]=str[l++],u=fa[u];
				else ans[v]=str[r--],v=fa[v];
			}
			ans[u]=str[l];
		}
	}
	printf("YES\n");
	for(int i=1;i<=n;i++) printf("%c",ans[i]);
	return 0;
}