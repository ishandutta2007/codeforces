#include <cstdio>
typedef long long ll;

const int MAXN=200005;

int n,sz[MAXN],cnt[2];
ll ans;

template <typename T>
inline void read(T &x){
	int ch,fl=0;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

struct Edge{
	Edge *nxt;
	int to;	
} pool[MAXN<<1],*p=pool,*lnk[MAXN];

void dfs(int u,int fa,int wd){
	sz[u]=1; ++cnt[wd];
	for (Edge *i=lnk[u];i;i=i->nxt)
		if (i->to!=fa){
			dfs(i->to,u,wd^1);
			sz[u]+=sz[i->to];
		}
	ans+=(ll)sz[u]*(n-sz[u]);
}

template <typename T>
inline void print(T x){
	if (x<0) x=-x,putchar('-');
	if (x>9) print(x/10);
	putchar(x%10+48);
}

int main(){
	read(n);
	for (int i=1,u,v;i<n;++i){
		read(u),read(v);
		*++p=(Edge){lnk[u],v},lnk[u]=p;
		*++p=(Edge){lnk[v],u},lnk[v]=p;
	}
	dfs(1,1,0);
	print(ans+(ll)cnt[0]*cnt[1]>>1);
	return 0;	
}