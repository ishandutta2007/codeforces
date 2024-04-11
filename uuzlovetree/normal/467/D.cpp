#include<bits/stdc++.h>
#define maxn 300005 
using namespace std;
typedef long long ll;
int m,n;
map<string,int> mp;
string s[maxn];
int cnt;
int Ans1[maxn],Ans2[maxn];
vector<int> g[maxn],g2[maxn],G[maxn];
bool vis[maxn];
int S[maxn],top,sccno[maxn],scc_cnt;
int minr[maxn],minlen[maxn];
void dfs1(int u)
{
	if(vis[u])return;
	vis[u]=1;
	for(int v:g[u])dfs1(v);
	S[++top]=u;
}
void dfs2(int u)
{
	if(sccno[u])return;
	sccno[u]=scc_cnt;
	for(int v:g2[u])dfs2(v);
}
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=1;
	for(int v:G[u])
	{
		dfs(v);
		if(minr[v]<minr[u])
		{
			minr[u]=minr[v];
			minlen[u]=minlen[v];
		}
		else if(minr[v]==minr[u])minlen[u]=min(minlen[v],minlen[u]);
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin>>m;
	for(int i=1;i<=m;++i)
	{
		cin>>s[i];
		int L=s[i].length();
		for(int j=0;j<L;++j)if(s[i][j]>='A'&&s[i][j]<='Z')s[i][j]=s[i][j]-'A'+'a';
		if(!mp.count(s[i]))
		{
			mp[s[i]]=++cnt;
			int len=s[i].length();
			for(int j=0;j<len;++j)
			{
				if(s[i][j]=='r')Ans1[cnt]++;
				Ans2[cnt]++;
			}
		}
	}
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		string x,y;
		cin>>x>>y;
		int Lx=x.length();
		for(int j=0;j<Lx;++j)if(x[j]>='A'&&x[j]<='Z')x[j]=x[j]-'A'+'a';
		int Ly=y.length();
		for(int j=0;j<Ly;++j)if(y[j]>='A'&&y[j]<='Z')y[j]=y[j]-'A'+'a';
		if(!mp.count(x))
		{
			mp[x]=++cnt;
			int len=x.length();
			for(int j=0;j<len;++j)
			{
				if(x[j]=='r')Ans1[cnt]++;
				Ans2[cnt]++;
			}
		}
		if(!mp.count(y))
		{
			mp[y]=++cnt;
			int len=y.length();
			for(int j=0;j<len;++j)
			{
				if(y[j]=='r')Ans1[cnt]++;
				Ans2[cnt]++;
			}
		}
		g[mp[x]].push_back(mp[y]);
		g2[mp[y]].push_back(mp[x]);
	}
	for(int i=1;i<=cnt;++i)dfs1(i);
	for(int i=top;i>=1;--i)if(!sccno[S[i]]){scc_cnt++;dfs2(S[i]);}
	for(int i=1;i<=scc_cnt;++i)minr[i]=1000000000,minlen[i]=1000000000;
	for(int i=1;i<=cnt;++i)
	{
		if(minr[sccno[i]]>Ans1[i])
		{
			minr[sccno[i]]=Ans1[i];
			minlen[sccno[i]]=Ans2[i];
		}
		else if(minr[sccno[i]]==Ans1[i]&&minlen[sccno[i]]>Ans2[i])
		{
			minlen[sccno[i]]=Ans2[i];
		}
	}
	for(int u=1;u<=cnt;++u)
	{
		for(int v:g[u])if(sccno[u]!=sccno[v])G[sccno[u]].push_back(sccno[v]);
	}
	ll ans1=0,ans2=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;++i)
	{
		int u=sccno[mp[s[i]]];
		dfs(u);
		ans1+=minr[u];
		ans2+=minlen[u];
	}
	cout<<ans1<<" "<<ans2<<endl;
}