#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,v,u) for(int i=H[u],v=to[i];i;i=nxt[i],v=to[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inf 1000000000
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
template<class T> inline void MAX(T&x,T y){if(x<y)x=y;}
template<class T> inline void MIN(T&x,T y){if(x>y)x=y;}
typedef long long ll;
typedef pair<int,int> pii;
const int N=5555;
//head
int f[N][N],g[N][N],m;
int c[N],d[N],n,sz[N];
int cnt,H[N],to[N*2],nxt[N*2];
void ins(int x,int y){
	to[++cnt]=y;nxt[cnt]=H[x];H[x]=cnt;
}
int h[N];
void dfs(int u){
	sz[u]=1;
	rep(i,0,n)f[u][i]=g[u][i]=1e9+5;
	f[u][1]=c[u]-d[u];
	g[u][0]=0;g[u][1]=c[u];
	For(_,v,u){
		dfs(v);
		rep(i,1,sz[u])h[i]=f[u][i];
		rep(i,1,sz[u])
			rep(j,1,sz[v])MIN(f[u][i+j],h[i]+min(f[v][j],g[v][j]));
		rep(i,0,sz[u])h[i]=g[u][i];
		rep(i,0,sz[u])
			rep(j,1,sz[v])MIN(g[u][i+j],h[i]+g[v][j]);
		sz[u]+=sz[v];
	}
}
int main() {
	read(n,m);
	rep(i,1,n){
		read(c[i],d[i]);
		if(i>1){
			int x;read(x);
			ins(x,i);
		}
	}
	dfs(1);
	int pos=0;
	rep(i,1,n)if(min(f[1][i],g[1][i])<=m)pos=i;
	printf("%d\n",pos);
	return 0;
}