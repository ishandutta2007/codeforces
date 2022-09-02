#include<bits/stdc++.h>
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#define DD(...) D(#__VA_ARGS__ "="),debug_helper::debug(__VA_ARGS__),D("\n")
#include"/home/xay5421/debug.hpp"
#else
#define D(...) ((void)0)
#define DD(...) ((void)0)
#endif
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
using namespace std;
using LL=long long;
using ULL=unsigned long long;
const int N=500005;
int n;
vector<pair<int,int> >edges;

bool ban[N];

namespace LCT{
	const int N=::N<<1;
	int fa[N],ch[N][2],rev[N],who[N];
	
	bool isroot(int u){return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;}
	int dir(int u){return ch[fa[u]][1]==u;}
	
	void update(int u){
		who[u]=u<=n?-1:ban[u-n-1]?-1:u-n-1;
		if(ch[u][0]&&who[u]==-1)who[u]=who[ch[u][0]];
		if(ch[u][1]&&who[u]==-1)who[u]=who[ch[u][1]];
	}
	
	void pushtag(int u){
		swap(ch[u][0],ch[u][1]);
		rev[u]^=1;
	}
	void pushdown(int u){
		if(rev[u]){
			pushtag(ch[u][0]);
			pushtag(ch[u][1]);
			rev[u]^=1;
		}
	}
	
	void rotate(int u){
		int fu=fa[u],x=dir(u);
		if(!isroot(fu))ch[fa[fu]][dir(fu)]=u;
		fa[u]=fa[fu];
		if((ch[fu][x]=ch[u][x^1]))fa[ch[u][x^1]]=fu;
		ch[u][x^1]=fu,fa[fu]=u;
		update(fu),update(u);
	}
	
	
	int st[N],top;
	void splay(int u){
		st[top=1]=u;
		for(int i=u;!isroot(i);i=fa[i]){
			st[++top]=fa[i];
		}
		per(i,top,1)pushdown(st[i]);
		for(;!isroot(u);rotate(u))if(!isroot(fa[u]))
			rotate(dir(u)==dir(fa[u])?fa[u]:u);
	}
	
	void access(int u){
		for(int i=0;u;i=u,u=fa[u]){
			splay(u);
			ch[u][1]=i;
			update(u);
		}
	}
	
	void makeroot(int u){
		access(u);
		splay(u);
		pushtag(u);
	}
	
	void link(int u,int v){
		// D("link %d %d\n",u,v);
		makeroot(u);
		fa[u]=v;
	}
	
	void cut(int u,int v){
		// D("cut %d %d\n",u,v);
		makeroot(u);
		access(v);
		splay(v);
		assert(ch[v][0]==u);
		assert(fa[u]==v);
		assert(!ch[u][1]);
		ch[v][0]=fa[u]=0;
		update(v);
	}
	
	void solve(int u,int v){
		makeroot(u);
		access(v);
		splay(v);
		int i=who[v];
		assert(i!=-1);
		int x,y;
		tie(x,y)=edges[i];
		printf("%d %d ",x,y);
		cut(x,i+n+1);
		cut(y,i+n+1);
		
		ban[i]=1;
		update(i+n+1);
		LCT::link(u,i+n+1);
		LCT::link(v,i+n+1);
	}
}

int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n);
	rep(i,0,n-2){
		int x,y;
		rd(x),rd(y);
		edges.pb(minmax(x,y));
	}
	sort(edges.begin(),edges.end());
	vector<pair<int,int> >todo;
	rep(i,1,n-1){
		int x,y;
		rd(x),rd(y);
		pair<int,int>tmp=minmax(x,y);
		auto it=lower_bound(edges.begin(),edges.end(),tmp);
		if(it==edges.end()||*it!=tmp){
			todo.pb(minmax(x,y));
		}else{
			ban[it-edges.begin()]=1;
		}
	}
	rep(i,0,n-2){
		int x,y;
		tie(x,y)=edges[i];
		LCT::update(i+n+1);
		LCT::link(x,i+n+1);
		LCT::link(y,i+n+1);
	}
	printf("%d\n",SZ(todo));
	rep(i,0,SZ(todo)-1){
		int u,v;
		tie(u,v)=todo[i];
		LCT::solve(u,v);
		printf("%d %d\n",u,v);
	}
	return 0;
}