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
#define inf 10000000
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=511111,Z=22;
//head
int to[N],cnt,nxt[N],H[N];
int st[N],ed[N],ver[N],sz[N],Ti;
int a[N],h[N],big[N];
int dep[1<<Z];
void ins(int x,int y){to[++cnt]=y;nxt[cnt]=H[x];H[x]=cnt;}
void pre_dfs(int u){
	st[u]=++Ti;ver[Ti]=u;
	sz[u]=1;big[u]=-1;
	For(i,v,u){
		a[v]^=a[u];
		h[v]=h[u]+1;
		pre_dfs(v);
		sz[u]+=sz[v];
		if(big[u]==-1||sz[big[u]]<sz[v])big[u]=v;
	}
	ed[u]=Ti;
}
void Max(int &x,int y){if(x<y)x=y;}
int ans[N],cur;
void dfs(int u,bool cl=0){
	For(i,v,u)
		if(v!=big[u])dfs(v,1),Max(ans[u],ans[v]);
	if(~big[u])dfs(big[u]),Max(ans[u],ans[big[u]]);
	For(i,v,u)if(v!=big[u]){
		rep(p,st[v],ed[v]){
			int x=ver[p];
			Max(cur,h[x]+dep[a[x]]-2*h[u]);
			re(_,0,Z)Max(cur,h[x]+dep[a[x]^(1<<_)]-2*h[u]);
		}
		rep(p,st[v],ed[v])Max(dep[a[ver[p]]],h[ver[p]]);
	}
	Max(cur,dep[a[u]]-h[u]);
	re(_,0,Z)Max(cur,dep[a[u]^(1<<_)]-h[u]);
	Max(dep[a[u]],h[u]);
	Max(ans[u],cur);
	if(cl){
		rep(p,st[u],ed[u])dep[a[ver[p]]]=-inf;
		cur=0;
	}
}
int n;
int main() {
	read(n);rep(i,2,n){
		int x;char ch[5];
		read(x);scanf("%s",ch);
		ins(x,i);
		a[i]=1<<(ch[0]-'a');
	}
	re(_,0,1<<Z)dep[_]=-inf;
	pre_dfs(1);
	dfs(1);
	rep(i,1,n)printf("%d ",ans[i]);
	return 0;
}