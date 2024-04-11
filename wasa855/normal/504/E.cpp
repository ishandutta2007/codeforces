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
inline int add(int x,int y,int md){return x+y>=md?x+y-md:x+y;}
inline int add(int x,int y,int z,int md){return add(add(x,y,md),z,md);}
inline int sub(int x,int y,int md){return x-y<0?x-y+md:x-y;}
inline int mul(int x,int y,int md){return 1LL*x*y%md;}
inline int mul(int x,int y,int z,int md){return mul(mul(x,y,md),z,md);}
int qpow(int x,int y,int md)
{
	int ans=1;
	while(y)
	{
		if(y&1) ans=mul(ans,x,md);
		x=mul(x,x,md);
		y>>=1;
	}
	return ans;
}
mt19937 rng(time(NULL));
#define N 600005
char str[N];
int mod1,mod2,B1,B2;
int pw1[N],pw2[N],ipw1[N],ipw2[N];
vector<int> G[N],s[N],t[N];
int fa[N][21],lg[N],st[N*2][21],dfn[N],cnt;
int n,dep[N],maxd[N],son[N],top[N];
int ha1[N],ha2[N],hb1[N],hb2[N]; // a up->down , b down -> up
bool prime(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0; return 1;
}
void init()
{
	while(mod1<10000000||!prime(mod1)) mod1=rng()%1000000000;
	while(mod2<10000000||!prime(mod2)) mod2=rng()%1000000000;
	while(B1%2==0||B1<10) B1=rng()%mod1;
	while(B2%2==0||B2<10) B2=rng()%mod2;
	// mod1=998244353,B1=3;
	pw1[0]=1; for(int i=1;i<N;i++) pw1[i]=mul(pw1[i-1],B1,mod1);
	pw2[0]=1; for(int i=1;i<N;i++) pw2[i]=mul(pw2[i-1],B2,mod2);
	ipw1[0]=1,ipw1[1]=qpow(B1,mod1-2,mod1); for(int i=2;i<N;i++) ipw1[i]=mul(ipw1[i-1],ipw1[1],mod1);
	ipw2[0]=1,ipw2[1]=qpow(B2,mod2-2,mod2); for(int i=2;i<N;i++) ipw2[i]=mul(ipw2[i-1],ipw2[1],mod2);
	for(int i=2;i<N;i++) lg[i]=lg[i>>1]+1;
}
void dfs1(int u,int Fa)
{
	fa[u][0]=Fa; st[++cnt][0]=u; dfn[u]=cnt;
	maxd[u]=dep[u]=dep[fa[u][0]]+1;
	ha1[u]=add(mul(ha1[fa[u][0]],B1,mod1),str[u],mod1);
	ha2[u]=add(mul(ha2[fa[u][0]],B2,mod2),str[u],mod2);
	hb1[u]=add(hb1[fa[u][0]],mul(str[u],pw1[dep[u]-1],mod1),mod1);
	hb2[u]=add(hb2[fa[u][0]],mul(str[u],pw2[dep[u]-1],mod2),mod2);
	for(int v:G[u])
	{
		if(v==Fa) continue;
		dfs1(v,u);
		if(maxd[v]>maxd[u]) maxd[u]=maxd[v],son[u]=v;
		st[++cnt][0]=u;
	}
}
void dfs2(int u,int topf)
{
	top[u]=topf;
	if(u==topf)
	{
		int tmp=u;
		s[u].resize(maxd[u]-dep[u]+1); t[u].resize(maxd[u]-dep[u]+1);
		for(int i=0;i<=maxd[u]-dep[u];i++) s[u][i]=tmp,tmp=fa[tmp][0];
		tmp=u;
		for(int i=0;i<=maxd[u]-dep[u];i++) t[u][i]=tmp,tmp=son[tmp];
	}
	if(!son[u]) return ;
	dfs2(son[u],topf);
	for(int v:G[u]) if(v!=son[u]&&v!=fa[u][0]) dfs2(v,v);
}
int jump(int u,int k)
{
	if(k==0) return u;
	u=fa[u][lg[k]];
	k^=(1<<lg[k]);
	k-=dep[u]-dep[top[u]];
	u=top[u];
	return k>=0?s[u][k]:t[u][-k];
}
int lca(int u,int v)
{
	u=dfn[u],v=dfn[v];
	if(u>v) swap(u,v);
	int qaq=lg[v-u+1];
	int U=st[u][qaq],V=st[v-(1<<qaq)+1][qaq];
	return dep[U]>dep[V]?V:U;
}
int gethash(int ha[],int hb[],int pw[],int ipw[],int B,int md,int a,int b,int l,int mid)
{
	int pre=dep[a]-dep[l];
	if(pre>=mid)
	{
		int u=jump(a,mid);
		return sub(ha[a],mul(ha[u],pw[mid],md),md);
	}
	int u=jump(a,pre);
	int X=sub(ha[a],mul(ha[u],pw[pre],md),md);
	int suf=mid-pre,tot=dep[b]-dep[l]+1;
	u=jump(b,tot-suf);
	int Y=sub(hb[u],hb[fa[l][0]],md);
	Y=mul(Y,ipw[dep[l]-1],md);
	return add(X,mul(Y,pw[pre],md),md);
}
bool judge(int ha[],int hb[],int pw[],int ipw[],int B,int md,int a,int b,int c,int d,int l1,int l2,int mid)
{
	// int X=gethash(ha,hb,pw,ipw,B,md,a,b,l1,mid);
	// printf("%d %d %d %d\n",a,b,mid,X);
	// X=gethash(ha,hb,pw,ipw,B,md,c,d,l2,mid);
	// printf("%d %d %d %d\n",c,d,mid,X);
	return gethash(ha,hb,pw,ipw,B,md,a,b,l1,mid)==gethash(ha,hb,pw,ipw,B,md,c,d,l2,mid);
}
signed main()
{
	init();
	cin>>n; scanf("%s",str+1);
	for(int i=1;i<n;i++)
	{
		int u=read(),v=read();
		G[u].pb(v),G[v].pb(u);
	}
	dfs1(1,0),dfs2(1,1);
	// for(int i=1;i<=n;i++) printf("%d ",ha1[i]); cout<<"\n";
	// for(int i=1;i<=n;i++) printf("%d ",hb1[i]); cout<<"\n";
	for(int i=1;i<=19;i++)
	{
		for(int j=1;j<=n;j++) fa[j][i]=fa[fa[j][i-1]][i-1];
	}
	for(int i=1;i<=20;i++)
	{
		for(int j=1;j+(1<<i)-1<=cnt;j++)
		{
			int u=st[j][i-1],v=st[j+(1<<(i-1))][i-1];
			st[j][i]=dep[u]>dep[v]?v:u;
		}
	}
	// for(int i=1;i<=cnt;i++) printf("%d ",st[i][0]); cout<<"\n";
	// for(int i =1;i<=n;i++) printf("%d ",dfn[i]); cout<<"\n";
	// for(int j=0;j<=3;j++)
	// {
		// for(int i=1;i<=cnt;i++) printf("%d ",st[i][j]); cout<<"\n";
	// }
	int Q=read();
	while(Q--)
	{
		int a=read(),b=read(),c=read(),d=read();
		int l1=lca(a,b),l2=lca(c,d);
		// printf("%d %d %d ; %d %d %d\n",a,b,l1,c,d,l2);
		int l=1,r=min(dep[a]+dep[b]-dep[l1]-dep[l1]+1,dep[c]+dep[d]-dep[l2]-dep[l2]+1),ans=0;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(!judge(ha1,hb1,pw1,ipw1,B1,mod1,a,b,c,d,l1,l2,mid))
			{
				r=mid-1; continue;
			}
			if(!judge(ha2,hb2,pw2,ipw2,B2,mod2,a,b,c,d,l1,l2,mid))
			{
				r=mid-1; continue;
			}
			l=mid+1,ans=mid;
		}
		printf("%d\n",ans);
	}
	return 0;
}