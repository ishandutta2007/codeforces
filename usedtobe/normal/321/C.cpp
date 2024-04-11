#include<algorithm>
#include<cstdio>
#include<cstring>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define pb push_back
#define clr(x) memset(x,0,sizeof x)
#define N 200005
#define INF 0x7ffffff
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x);read(y);read(z);}
//head
bool vis[N];
int ans[N];
int cnt=0,son[N],f[N],dep[N],d[N];
int H[N],to[N],nxt[N],rt,sum,n;
void ins(int x,int y) {to[++cnt]=y;nxt[cnt]=H[x];H[x]=cnt;}
void getroot(int u,int fa) {
	son[u]=1;f[u]=0;int v;
	For(i,u) {
		if ((v=to[i])==fa||vis[v])continue;
		getroot(v,u);son[u]+=son[v];
		f[u]=max(f[u],son[v]);
	}
	f[u]=max(f[u],sum-son[u]);if(f[u]<f[rt])rt=u;
}
void work(int u,int col) {
	if (col>25) {puts("Impossible");exit(0);}
	ans[u]=col;vis[u]=1;int v;
	For(i,u) {
		if (vis[v=to[i]]) continue;
		sum=son[v];
		getroot(v,rt=0);
		work(rt,col+1);
	}
}
int main() {
	read(n);
	int u,v,w;sum=n;
	rep(i,1,n-1) read(u,v),ins(u,v),ins(v,u);f[0]=INF;
	getroot(1,0);
	work(rt,0);
	rep(i,1,n)printf("%c ",char('A'+ans[i]));
	return 0;
}