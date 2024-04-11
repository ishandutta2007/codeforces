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
const int N=511111;
//head
int Cnt,H[N],nxt[N],to[N];
int sz[N],cnt[N],col[N];
bool big[N];
int dep[N];
void ins(int x,int y){to[++Cnt]=y;nxt[Cnt]=H[x];H[x]=Cnt;}
void getsz(int u,int fa){
	sz[u]=1;int v;
	For(i,u)if((v=to[i])!=fa){
		dep[v]=dep[u]+1;
		getsz(v,u);
		sz[u]+=sz[v];
	}
}
int sum[N][27];
void add(int u,int fa,int x){
	sum[dep[u]][col[u]]^=1;
	if(sum[dep[u]][col[u]])++cnt[dep[u]];
	else --cnt[dep[u]];
	For(i,u){
		int v=to[i];
		if(v!=fa&&!big[v])add(v,u,x);
	}
}
bool ans[N];
vector<pii> Q[N];
void dfs(int u,int fa,bool keep){
	int mx=-1,son=-1,v;
	For(i,u)if((v=to[i])!=fa&&mx<sz[v])son=v,mx=sz[v];
	For(i,u)if((v=to[i])!=fa&&v!=son)dfs(v,u,0);
	if(~son)dfs(son,u,1),big[son]=1;
	add(u,fa,1);
	re(i,0,Q[u].size())ans[Q[u][i].Y]=(cnt[Q[u][i].X]<=1);
	if(~son)big[son]=0;
	if(!keep)add(u,fa,-1);
}
int n,m;
char s[N];
int main() {
	read(n,m);rep(i,2,n){
		int x;read(x);
		ins(x,i);
	}
	scanf("%s",s+1);
	rep(i,1,n)col[i]=s[i]-'a'+1;
	rep(i,1,m){
		int v,h;read(v,h);
		Q[v].pb(mp(h,i));
	}
	dep[1]=1;getsz(1,0);
	dfs(1,0,0);
	rep(i,1,m)puts(ans[i]?"Yes":"No");
	return 0;
}