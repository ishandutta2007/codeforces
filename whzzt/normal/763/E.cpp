#include"bits/stdc++.h"
using namespace std;

namespace IO{
	#define gch getchar()
	template<class mi>inline void readi(mi&x){
		x=0;int f=1;char ch=gch;while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=gch;}
		while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=gch;x*=f;
	}
} ;
using namespace IO;

const int N=100005,M=600005;
struct Edge {bool k;int u,v,id;} e[M];
bool operator <(const Edge&a,const Edge&b){
	if(a.v==b.v){
		if(a.k==b.k) return a.u<b.u; 
		return a.k<b.k;
	}
	return a.v < b.v;
}
int n,m,q,parent[N],ans[N];

int getfa (int x){return x==parent[x] ? x : parent[x]=getfa(parent[x]);}
void merge (int x,int y){ x=getfa(x),y=getfa(y); parent[x]=y;}

struct node{
	node *c[2],*fa; bool rev;
	int minval,val; node();
	void pushup(); void pushdown();
} Tnull,*null=&Tnull,t[N+M];
node::node(){
	c[0]=c[1]=fa=null;
	minval=val=0;
	rev=false;
}
void node:: pushup(){
	minval = val;
	if (c[0]!=null) if(e[c[0]->minval].u < e[minval].u) minval = c[0]->minval;
	if (c[1]!=null) if(e[c[1]->minval].u < e[minval].u) minval = c[1]->minval;
}
void node:: pushdown(){
	if (rev){
		if(c[0]!=null) c[0]->rev^=1;
		if(c[1]!=null) c[1]->rev^=1;
		swap(c[0],c[1]); rev^=1;
	}
}

int k;

node*st[N];int tp;
#define isroot(x) ((x)->fa->c[0]!=(x) && (x)->fa->c[1]!=(x))
void rotate (node *x){
	node *y=x->fa, *z=y->fa; int l=y->c[1]==x, r=l^1;
	if(z->c[0]==y) z->c[0]=x; if(z->c[1]==y) z->c[1]=x;
	x->fa=z; y->fa=x; if(x->c[r]!=null) x->c[r]->fa=y;
	y->c[l]=x->c[r]; x->c[r]=y; y->pushup();
}
void splay (node *x){
	st[++tp]=x; for (node *y=x; !isroot(y); y=y->fa) st[++tp]=y->fa;
	while (tp) st[tp]->pushdown(),st[tp--]=null;
	while (!isroot(x)){
		node *y=x->fa, *z=y->fa;
		if (!isroot(y)){
			if (z->c[0]==y^y->c[0]==x) rotate(x);
			else rotate(y);
		}
		rotate(x);
	}
	x->pushup();
}
void access (node *x){
	for (node *y=null; x!=null; y=x,x=x->fa)
		splay(x),x->c[1]=y,x->pushup();
}
void makeroot (node *x){
	access(x); splay(x);
	x->rev^=1;
}
namespace BIT{
    int data[N],n;
    void init(int _n){
        memset(data,0,sizeof(data));
        n=_n;
    }
    int lowbit(int x){
        return x&(-x);
    }
    void add(int pos,int val){
        while(pos<=n){
            data[pos]+=val;
            pos+=lowbit(pos);
        }
    }
    int sum(int pos){
        int ret=0;
        while(pos){
            ret+=data[pos];
            pos-=lowbit(pos);
        }
        return ret;
	}
}
void link(node *x,node *y){ makeroot(x); x->fa=y;}
void cut(node *x,node *y){ makeroot(x),access(y),splay(y); y->c[0]=x->fa=null; y->pushup();}
int relink(int id){
	node *x=t+e[id].u, *y=t+e[id].v;
	makeroot(x),access(y),splay(y);int p=y->minval;
	if (e[p].u > e[id].u) return 0;
	BIT::add(e[p].u,-1);BIT::add(e[id].u,1);
	cut(t+e[p].u,t+p+n);cut(t+e[p].v,t+p+n);
	t[id+n].val=t[id+n].minval=id;
	link(t+id+n,x);link(t+id+n,y);
	return 1;
}
int getid(node *x,node *y){
	makeroot(x),access(y),splay(y);
	return y->minval;
}

int main(){
	e[0].u = e[0].v = N; 
	readi(n),readi(k),readi(m);
	BIT::init(n);
	for (int i=1;i<=m;i++) {
		readi(e[i].u),readi(e[i].v);
		if(e[i].u>e[i].v) swap(e[i].u,e[i].v);
		e[i].k=0, e[i].id=i;
	}
	readi(q);
	for (int i=1;i<=q;i++) {
		readi(e[i+m].u),readi(e[i+m].v);
		if(e[i+m].u>e[i+m].v) swap(e[i+m].u,e[i+m].v);
		e[i+m].k=1, e[i+m].id=i;
	}
	sort(e+1, e+m+q+1);
	for (int i=1;i<=n;i++) parent[i]=i;
	int last = 1;
	for (int i=1; i<=q+m; i++){
		if (e[i].k == 0){
			if (getfa(e[i].u)!=getfa(e[i].v)){ 
				merge(e[i].u,e[i].v),t[i+n].minval=t[i+n].val=i;
				BIT::add(e[i].u,1);link(t+i+n,t+e[i].u),link(t+i+n,t+e[i].v);
			} else if(e[i].u!=e[i].v) relink(i);
		} else ans[e[i].id]=(e[i].v-e[i].u+1)-BIT::sum(e[i].v)+BIT::sum(e[i].u-1);
	}
	for (int i=1; i<=q; i++) printf("%d\n",ans[i]);
	return 0;
}