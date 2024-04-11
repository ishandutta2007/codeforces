#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
typedef long long ll;
#define N 100050
int head[N],to[N<<1],nxt[N<<1],cnt,n,m,K,S,w[N],tot,visp[N],Q[N],l,r,visc[N],dep[N];
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
ll bfs(int s) {
	ll re=0;
	int i,nowc=1; tot++;
	visp[s]=tot; visc[w[s]]=tot;
	l=r=0; Q[r++]=s; dep[s]=0;if(S==1)return 0;
	while(l<r) {
		int x=Q[l++];
		for(i=head[x];i;i=nxt[i]) {
			if(visp[to[i]]!=tot) {
				visp[to[i]]=tot;
				Q[r++]=to[i]; dep[to[i]]=dep[x]+1;
				if(visc[w[to[i]]]!=tot) {
					visc[w[to[i]]]=tot; re+=dep[to[i]]; nowc++; if(nowc==S) return re;
				}
			}
		}
	}
	return re;
}
int main() {
	scanf("%d%d%d%d",&n,&m,&K,&S);
	int i,x,y;
	for(i=1;i<=n;i++) scanf("%d",&w[i]);
	for(i=1;i<=m;i++) {
		scanf("%d%d",&x,&y); add(x,y); add(y,x);
	}
	for(i=1;i<=n;i++) {
		printf("%lld ",bfs(i));
	}
}