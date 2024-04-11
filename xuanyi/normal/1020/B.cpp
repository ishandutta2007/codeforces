#include <cstdio>
#include <cstring>

#define MAXN 1005

int n,son[MAXN];
bool vis[MAXN];

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

inline void dfs(int u){
	if (vis[u]){ printf("%d ",u); return; }
	vis[u]=1;
	dfs(son[u]);
}

int main(){
	read(n);
	for (int i=1;i<=n;i++) read(son[i]);
	for (int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		dfs(i);
	}
	return 0;
}