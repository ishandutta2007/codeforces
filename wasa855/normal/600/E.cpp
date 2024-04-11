#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
struct Edge
{
	int v,nxt;
};
Edge edge[N*2];
int fir[N];
int ss;
void add(int u,int v)
{
	ss++;
	edge[ss].v=v,edge[ss].nxt=fir[u];
	fir[u]=ss;
	ss++;
	edge[ss].v=u,edge[ss].nxt=fir[v];
	fir[v]=ss;
}
int cnt[N],ccnt[N],sum[N];
int ans[N];
int col[N];
int n;
int siz[N],son[N];
int maxn=0;
int Son;
void upd(int u,int fa)
{
	ccnt[cnt[col[u]]]--;
	sum[cnt[col[u]]]-=col[u];
	cnt[col[u]]++;
	if(cnt[col[u]]>maxn) maxn=cnt[col[u]];
	ccnt[cnt[col[u]]]++;
	sum[cnt[col[u]]]+=col[u];
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v==fa||v==Son) continue;
		upd(v,u);
	}
}
void del(int u,int fa)
{
	ccnt[cnt[col[u]]]--;
	sum[cnt[col[u]]]-=col[u];
	cnt[col[u]]--;
	ccnt[cnt[col[u]]]++;
	sum[cnt[col[u]]]+=col[u];
	if(ccnt[maxn]==0) maxn--;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v==fa) continue;
		del(v,u);
	}
}
void dfs1(int u,int fa)
{
	siz[u]=1;
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(fa==v) continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int fa,bool kep)
{
	for(int i=fir[u];i!=0;i=edge[i].nxt)
	{
		int v=edge[i].v;
		if(v==fa||v==son[u]) continue;
		dfs2(v,u,0);
	}
	if(son[u]) dfs2(son[u],u,1);
	Son=son[u];
	upd(u,fa);
	ans[u]=sum[maxn];
	if(!kep) del(u,fa);
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n;
	for(int i=1;i<=n;i++) col[i]=read();
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		add(u,v);
	}
	dfs1(1,0);
	dfs2(1,0,0);
	for(int i=1;i<=n;i++)
	{
		printf("%I64d ",ans[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}