#include <cstdio>
#include <algorithm>
#define int long long
using namespace std;

const int MAXN=100005;

int n,L,S,res,dp[MAXN],f[MAXN][20],g[MAXN][20];

template <typename T>
inline void read(T &x){
	int fl=0,ch;
	while (ch=getchar(),ch<48 || 57<ch) fl^=!(ch^45); x=(ch&15);
	while (ch=getchar(),47<ch && ch<58) x=(x<<1)+(x<<3)+(ch&15);
	if (fl) x=-x;
}

struct Edge{
	Edge *nxt;
	int to;
} pool[MAXN<<1],*p=pool,*lnk[MAXN];

int dfs(int u){
	int mx=0;
	for (Edge *i=lnk[u];i;i=i->nxt)
		mx=max(mx,dfs(i->to));
	if (!mx){
		++res;
		mx=dp[u];
	}
	return mx-1;
}

#undef int
int main(){
#define int long long
	read(n),read(L),read(S);
	for (int i=1;i<=n;++i){read(g[i][0]);if (g[i][0]>S){puts("-1");return 0;}}
	for (int i=2;i<=n;++i){
		read(f[i][0]);
		*++p=(Edge){lnk[f[i][0]],i},lnk[f[i][0]]=p;
	}
	for (int j=1;j<20;++j)
		for (int i=1;i<=n;++i){
			f[i][j]=f[f[i][j-1]][j-1];
			g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1];
		}
	for (int _=1;_<=n;++_){
		int u=_,ste=0,sum=0;
		for (int i=19;i>=0;--i)
			if (ste+(1<<i)<=L && sum+g[u][i]<=S){
				ste+=(1<<i);
				sum+=g[u][i];
				u=f[u][i];
			}
		dp[_]=ste;
	}
	dfs(1);
	printf("%I64d\n",res);
	return 0;
}