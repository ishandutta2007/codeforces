#include<bits/stdc++.h>

#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())
#define sqr(x) ((x)*(x))
#define GCD __gcd

using namespace std;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;
typedef vector<int> VI;
typedef vector<VI> VII;

namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#ifdef whzzt
		#define gc() getchar()
	#else
		#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	#endif
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c<'a'||c>'z';c=gc());
		for(l=0;c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void ps(const char*s){
		fo(i,0,strlen(s)-1)putc(s[i]);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::ps;
using io::print;

const int N=200005;

int n,m,h[N],nxt[N<<1],to[N<<1],ec=1,dfn[N],low[N],dfc,id[N],bcc,deg[N],dis[N],route_sum,leaf_sum,block;
vector<int>e[N];
bool cut[N<<1],vi[N];
void adde(int u,int v){
	to[++ec]=v;nxt[ec]=h[u];h[u]=ec;
	to[++ec]=u;nxt[ec]=h[v];h[v]=ec;
}
void tarjan(int u,int eid){
	dfn[u]=low[u]=++dfc;
	for(int i=h[u],v;i;i=nxt[i]){
		v=to[i];
		if(!dfn[v]){
			tarjan(v,i^1),low[u]=min(low[u],low[v]);
			if(low[v]>dfn[u])cut[i]=cut[i^1]=true;
		}else if(dfn[v]<dfn[u]&&i!=eid)low[u]=min(low[u],dfn[v]);
	}
}
void dfs1(int u){
	id[u]=bcc;
	for(int i=h[u],v;i;i=nxt[i])if(!cut[i]&&!id[v=to[i]])dfs1(v);
}
int qu[N],qr,tag[N];
void dfs2(int u){
	qu[++qr]=u;vi[u]=true;
	for(int v:e[u])if(!vi[v])dfs2(v);
}
int bfs(int u){
	static int qu[N],ql,qr;
	dis[u]=0;
	for(qu[ql=qr=1]=u;ql<=qr;ql++){
		u=qu[ql];
		for(int v:e[u])if(tag[v]==block&&dis[v]==-1)dis[v]=dis[u]+1,qu[++qr]=v;
	}
	return qu[qr];
}
void ext(int u){
	block++;
	while(qr)qu[qr--]=0;
	dfs2(u);
	if(qr>2){
		int S=0,T;
		fo(i,1,qr){
			if(deg[qu[i]]>1)
				tag[qu[i]]=block,S=qu[i];
			else
				leaf_sum++;
		}
		fo(i,1,qr)if(deg[qu[i]]>1)dis[qu[i]]=-1;S=bfs(S);
		fo(i,1,qr)if(deg[qu[i]]>1)dis[qu[i]]=-1;T=bfs(S);
		route_sum+=dis[T]+1;
	}else{
		route_sum++;
		leaf_sum+=qr-1;
	}
}

int main(){
	gi(n);gi(m);int u,v;
	fo(i,1,m)gi(u),gi(v),adde(u,v);
	fo(i,1,n)if(!dfn[i])tarjan(i,0);
	fo(i,1,n)if(!id[i])++bcc,dfs1(i);
	fos(i,2,ec,2)if(cut[i]){
		int u=id[to[i]],v=id[to[i^1]];
		e[u].pb(v);e[v].pb(u);deg[u]++;deg[v]++;
	}
	fo(i,1,bcc)if(!vi[i])ext(i);
	int remain=leaf_sum+route_sum-block+1;
	printf("%d\n",n-remain);
	return 0;
}