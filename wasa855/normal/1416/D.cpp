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
#define N 500005
int a[N],fa[N],siz[N],n,m,Q;
int find(int u){return fa[u]==u?u:find(fa[u]);}
int r[N],t[N],vis[N],u[N],v[N];
int opt[N],x[N];
vector<int> tmp[N];
struct CMP
{
	bool operator () (const int &x,const int &y)const{return x>y;}
};
set<int,CMP> s[N];
pii merge(int u,int v)
{
	u=find(u),v=find(v);
	if(u==v) return {0,0};
	if(siz[u]<siz[v]) swap(u,v);
	fa[v]=u,siz[u]+=siz[v];
	for(int i:tmp[v]) tmp[u].pb(i);
	return {u,v};
}
signed main()
{
	cin>>n>>m>>Q;
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) u[i]=read(),v[i]=read();
	for(int i=1;i<=Q;i++)
	{
		opt[i]=read(),x[i]=read();
		if(opt[i]==2) vis[x[i]]=1;
	}
	for(int i=1;i<=n;i++) fa[i]=i,siz[i]=1,tmp[i].pb(i);
	for(int i=1;i<=m;i++) if(!vis[i]) merge(u[i],v[i]);
	for(int i=Q;i>=1;i--)
	{
		if(opt[i]==2)
		{
			auto [A,B]=merge(u[x[i]],v[x[i]]);
			r[i]=A,t[i]=B;
		}
		else x[i]=find(x[i]);
	}
	for(int i=1;i<=n;i++) s[find(i)].insert(a[i]);
	for(int i=1;i<=Q;i++)
	{
		if(opt[i]==1)
		{
			// int u=find(x[i])
			int u=x[i];
			if(!s[u].empty()) printf("%d\n",*s[u].begin()),s[u].erase(s[u].begin());
			else printf("0\n");
		}
		else if(r[i])
		{
			int u=r[i],V=t[i];
			for(int j:tmp[V])
			{
				if(s[u].find(a[j])!=s[u].end())
				{
					s[u].erase(a[j]);
					s[V].insert(a[j]);
				}
			}
		}
	}
	return 0;
}