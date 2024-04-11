#pragma GCC optimize("no-stack-protector,unroll-loops")
#pragma GCC target("popcnt,abm,mmx,avx,avx2,fma,tune=native") 

#include<bits/stdc++.h>

#define lowbit(x) ((x)&(-(x)))
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
#define SZ(x) ((int)x.size())
#define mkpr std::make_pair
#define pb push_back

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int,int> pi;
typedef std::pair<ll,ll> pl;
using std::min;
using std::max;

const int inf=0x3f3f3f3f,Inf=0x7fffffff;
const ll INF=0x3f3f3f3f3f3f3f3f;

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());
template <typename _Tp>_Tp gcd(const _Tp &a,const _Tp &b){return (!b)?a:gcd(b,a%b);}
template <typename _Tp>inline _Tp abs(const _Tp &a){return a>=0?a:-a;}
template <typename _Tp>inline void chmax(_Tp &a,const _Tp &b){(a<b)&&(a=b);}
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){(b<a)&&(a=b);}
template <typename _Tp>inline void read(_Tp &x)
{
	char ch(getchar());bool f(false);while(!isdigit(ch)) f|=ch==45,ch=getchar();
	x=ch&15,ch=getchar();while(isdigit(ch)) x=(((x<<2)+x)<<1)+(ch&15),ch=getchar();
	f&&(x=-x);
}
template <typename _Tp,typename... Args>inline void read(_Tp &t,Args &...args){read(t);read(args...);}
inline int read_str(char *s)
{
	char ch(getchar());while(ch==' '||ch=='\r'||ch=='\n') ch=getchar();
	char *tar=s;*tar=ch,ch=getchar();while(ch!=' '&&ch!='\r'&&ch!='\n'&&ch!=EOF) *(++tar)=ch,ch=getchar();
	return tar-s+1;
}

const int N=50005;
struct edge{
	int v,nxt;
}c[N];
int front[N],edge_cnt;
inline void addedge(int u,int v)
{
	c[++edge_cnt]=(edge){v,front[u]};
	front[u]=edge_cnt;
}
int _a[N],a[N],dfn[N],rev[N],id,val[N],siz[N],_dep[N],dep[N];
void dfs(int x)
{
	dfn[x]=++id,rev[id]=x;
	a[id]=_a[x],siz[x]=1;
	dep[id]=_dep[x];
	for(int i=front[x];i;i=c[i].nxt)
	{
		int v=c[i].v;
		_dep[v]=_dep[x]+1;
		dfs(v);siz[x]+=siz[v];
	}
}
int main()
{
	int n,q;read(n,q);
	int x;
	for(int i=1;i<=n;++i) read(_a[i]);
	for(int i=2;i<=n;++i) read(x),addedge(x,i);
	dfs(1);
	for(int t=1;t<=q;++t)
	{
		read(x);
		int l=dfn[x],r=dfn[x]+siz[x]-1;
		int a1=0,a2=0;
		for(int i=l;i<=r;++i)
		{
			if(val[i]<=t)
			{
				val[i]=t+a[i];
				a1+=dep[i],++a2;
			}
		}
		printf("%d %d\n",a1-a2*_dep[x],a2);
	}
	return 0;
}