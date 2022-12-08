#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,u) for(int i=H[u];i;i=nxt[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=211111;
//head
pii a[N];
vector<int> g[N];
int ans[N];
bool vis[N];
void dfs(int u,int d){
	ans[u]=d;vis[u]=1;
	re(i,0,g[u].size()){
		int v=g[u][i];
		if(vis[v])continue;
		dfs(v,d^1);
	}
}
int n;
int main() {
	read(n);rep(i,1,n){
		int &x=a[i].X,&y=a[i].Y;
		read(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	rep(i,1,n)g[i*2].pb(i*2-1),g[i*2-1].pb(i*2);
	rep(i,1,n*2)if(!vis[i])dfs(i,1);
	rep(i,1,n)printf("%d %d\n",ans[a[i].X]+1,ans[a[i].Y]+1);
	return 0;
}