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
#define N 200005
int maxd[N],top[N],dep[N],len[N],fa[N],son[N],id[N],c[N],n,k;
vector<int> G[N];
void dfs1(int u,int f)
{
	fa[u]=f,dep[u]=dep[f]+1;
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs1(v,u),maxd[u]=max(maxd[u],maxd[v]+1);
		if(!son[u]||maxd[v]>maxd[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int tp,int l)
{
	len[u]=l,top[u]=tp;
	if(!son[u]) return ;
	len[u]=dep[u]-n-1;
	dfs2(son[u],tp,l+1);
	for(int v:G[u])
	{
		if(v==fa[u]||v==son[u]) continue;
		dfs2(v,v,0);
	}
}
int w,b,r,siz[N];
void dfs3(int u,int f)
{
	siz[u]=c[u];
	for(int v:G[u])
	{
		if(v==f) continue;
		dfs3(v,u),siz[u]+=siz[v];
	}
	if(c[u]==0)
	{
		if(siz[u]) w++;
		else b++;
	}
}
signed main()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0),dfs2(1,1,0);
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y) {return len[x]>len[y];});
	for(int i=1;i<=k;i++)
	{
		if(len[id[i]]>=0) c[id[i]]=1,r++;
	}
	// for(int i=1;i<=n;i++) printf("%d%c",len[i]," \n"[i==n]);
	dfs3(1,0);
	// printf("%d %d %d\n",w,b,r);
	while(r<k)
	{
		ll cw=1LL*w*(r-b);
		w--,r++;
		ll tw=1LL*w*(r-b);
		if(tw>=cw) continue;
		else
		{
			w++,r--;
			break;
		}
	}
	int rest=0;
	for(int i=1;i<=k;i++) if(len[i]>=0&&c[i]==0) rest++;
	// printf("%d %d %d\n",w,b,r);
	while(b)
	{
		ll cw=1LL*w*(r-b);
		b--,w++;
		ll tw=1LL*w*(r-b);
		if(tw<=cw) continue;
		else
		{
			b++,w--;
			break;
		}
	}
	// printf("%d %d %d\n",w,b,r);
	cout<<1LL*w*(r-b)<<endl;
	return 0;
}