#include<bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 900005
char s[N];
int n,Q,l[N],r[N],id[N],ans[N],v[N],sum[N],siz[N],cnt;
int st[N],fa[N],tp;
vector<int> G[N];
int ind[N],oud[N],dfscnt;
tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> T[N];
void dfs(int u)
{
	int s=G[u].size();
	v[u]=s*(s-1)/2+1;
	ind[u]=++dfscnt;
	for(int i=0;i<(int)G[u].size();i++)
	{
		int v=G[u][i];
		dfs(v),ans[u]+=ans[v];
		// fa[v]=u;
	}
	oud[u]=dfscnt;
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
	int qry(int l,int r) {return query(r)-query(l-1);}
}bit;
signed main()
{
	cin>>n>>Q;
	for(int i=1;i<=n;i++) s[i]='(';
	scanf("%s",s+n+1);
	for(int i=1;i<=n;i++) s[n+n+i]=')';
	n*=3;
	// printf("%s\n",s+1);
	// s[1]='(',s[n+2]=')';
	for(int i=1;i<=n;i++)
	{
		if(s[i]==')')
		{
			if(tp)
			{
				int u=id[st[tp]];
				r[u]=i,id[i]=u;
				tp--;
				if(tp) G[id[st[tp]]].pb(u),fa[u]=id[st[tp]];
			}
		}
		else
		{
			st[++tp]=i;
			int u=++cnt; l[u]=i,id[i]=u;
		}
	}
	// for(int i=1;i<=n;i++) printf("%d%c",id[i]," \n"[i==n]);
	// for(int i=1;i<=cnt;i++) printf("%d %d\n",l[i],r[i]);
	// for(int i=1;i<=cnt;i++) printf("%d : ",i),print(G[i]);
	for(int i=1;i<=cnt;i++) if(!fa[i]) dfs(i);
	for(int i=1;i<=cnt;i++) sum[i]=sum[i-1]+v[i];
	bit.init(cnt);
	for(int i=1;i<=cnt;i++) bit.update(i,v[i]);
	for(int i=1;i<=cnt;i++) for(int v:G[i]) T[i].insert(v),siz[i]++;
	while(Q--)
	{
		int op=read(),l=read()+n/3,r=read()+n/3;
		if(op==2)
		{
			int u=id[l],v=id[r];
			// printf("^ %d %d\n",u,v);
			// int ans=sum[oud[v]]-sum[ind[u]-1];
			int ans=bit.qry(ind[u],oud[v]);
			if(fa[u])
			{
				// int lid=lower_bound(G[fa[u]].begin(),G[fa[u]].end(),u)-G[fa[u]].begin(),rid=lower_bound(G[fa[u]].begin(),G[fa[u]].end(),v)-G[fa[u]].begin();
				// (int)T.order_of_key(x) + 1
				int lid=T[fa[u]].order_of_key(u),rid=T[fa[u]].order_of_key(v);
				// printf("%d %d\n",lid,rid);
				int s=rid-lid+1;
				ans+=s*(s-1)/2;
			}
			printf("%lld\n",ans);
		}
		else
		{
			int u=id[l];
			bit.update(ind[u],-1);
			if(fa[u])
			{
				int f=fa[u];
				T[f].erase(T[f].lower_bound(u));
				bit.update(ind[f],-siz[f]*(siz[f]-1)/2);
				siz[f]--;
				bit.update(ind[f],siz[f]*(siz[f]-1)/2);
			}
		}
	}
	return 0;
}