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
#define N 1000005
char s[N];
int ch[N][26],fa[N],len[N],fail[N],cnt,id[N],nd[N],a[N],dfn[N],siz[N],vis[N],dfscnt,n;
vector<int> G[N];
void build()
{
	queue<int> q;
	for(int i=0;i<26;i++) if(ch[0][i]) q.push(ch[0][i]);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<26;i++)
		{
			if(ch[u][i]) fail[ch[u][i]]=ch[fail[u]][i],q.push(ch[u][i]);
			else ch[u][i]=ch[fail[u]][i];
		}
	}
}
struct BIT
{
	int len,t[N];
	void init(int l){len=l,memset(t,0,sizeof(t));}
	inline int lowbit(int x){return x&(-x);}
	void update(int u,int v){for(int i=u;i<=len;i+=lowbit(i)) t[i]+=v;}
	int query(int u)
	{
		int ans=0;
		for(int i=u;i>0;i-=lowbit(i)) ans+=t[i];
		return ans;
	}
	int query(int l,int r) {return query(r)-query(l-1);}
}bit;
void dfs(int u)
{
	siz[u]=1,dfn[u]=++dfscnt;
	for(int v:G[u])
	{
		if(!id[v]) id[v]=id[u];
		dfs(v),siz[u]+=siz[v];
	}
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s+1);
		int m=strlen(s+1);
		int cur=0;
		for(int j=1;j<=m;j++)
		{
			if(!ch[cur][s[j]-'a']) ch[cur][s[j]-'a']=++cnt,fa[cnt]=cur,len[cnt]=len[cur]+1;
			cur=ch[cur][s[j]-'a'];
		}
		id[cur]=cur,nd[i]=cur;
	}
	build();
	for(int i=1;i<=cnt;i++) G[fail[i]].pb(i);
	dfs(0); bit.init(cnt+1);
	// for(int i=1;i<=cnt;i++) printf("%d%c",id[i]," \n"[i==cnt]);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int u=nd[i]; int cnt=0;
		while(u)
		{
			int ch=id[u==nd[i]?fail[u]:u];
			if(ch) a[++cnt]=ch;
			u=fa[u];
		}
		sort(a+1,a+cnt+1,[&](int x,int y){return len[x]!=len[y]?len[x]>len[y]:x>y;});
		cnt=unique(a+1,a+cnt+1)-a-1;
		// printf("- %d\n",i);
		// for(int i=1;i<=cnt;i++) printf("%d%c",a[i]," \n"[i==cnt]);
		for(int i=1;i<=cnt;i++) vis[a[i]]=1;
		int minn=inf;
		u=nd[i];
		while(u)
		{
			int ch=id[u==nd[i]?fail[u]:u];
			if(ch)
			{
				if(len[u]-len[ch]<minn) minn=len[u]-len[ch];
				else vis[ch]=0;
			}
			u=fa[u];
		}
		for(int i=1;i<=cnt;i++)
		{
			if(bit.query(dfn[a[i]],dfn[a[i]]+siz[a[i]]-1)) vis[a[i]]=0;
			bit.update(dfn[a[i]],1);
		}
		for(int i=1;i<=cnt;i++) if(vis[a[i]]) ans++;
		for(int i=1;i<=cnt;i++) bit.update(dfn[a[i]],-1);
	}
	cout<<ans<<endl;
	return 0;
}