#include<bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("-funroll-loops")
#pragma GCC target("avx,sse4")

#define mms(a,n) memset(a,0,sizeof((a)[0])*(n))
#define mmp(a,b,n) memcpy(a,b,sizeof((b)[0])*(n))
#define lowbit(x) ((x)&-(x))
#define pb push_back
#define fi first
#define se second
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define fo(i,l,r) for(register int i=l,_lim_=r;i<=_lim_;i++)
#define fd(i,r,l) for(register int i=r,_lim_=l;i>=_lim_;i--)
#define fos(i,l,r,d) for(register int i=l,_lim_=r;i<=r;i+=d)
#define fol(i,l,r) for(register ll i=l,_lim_=r;i<=_lim_;i++)
#define fdl(i,r,l) for(register ll i=r,_lim_=l;i>=_lim_;i--)
#define fosl(i,l,r,d) for(register ll i=l,_lim_=r;i<=r;i+=d)
#define Clear(a) memset(a,0,sizeof(a))
#define Copy(a,b) memcpy(a,b,sizeof(b))
#define ALL(v) v.begin(),v.end()
#define SZ(v) ((int)v.size())

using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ldb;
typedef double db;
typedef pair<int,int> pi;


namespace io{
	const int L=(1<<21)+1;
	char ibuf[L],*iS,*iT,obuf[L],*oS=obuf,*oT=obuf+L-1,c,st[55];int f,tp;
	#ifdef whzzt
		#define gc() getchar()
	#else
		#define gc() (iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,L,stdin),(iS==iT?EOF:*iS++)):*iS++)
	#endif
	inline void flush(){fwrite(obuf,1,oS-obuf,stdout);oS=obuf;}
	inline void putc(char x){*oS++=x;if(oS==oT)flush();}
	template<class I>
	inline void gi(I&x){
		for(f=1,c=gc();c<'0'||c>'9';c=gc())if(c=='-')f=-1;
		for(x=0;c<='9'&&c>='0';c=gc())x=x*10+(c&15);x*=f;
	}
	template<class I>
	inline void print(I x){
		if(!x)putc('0');if(x<0)putc('-'),x=-x;
		while(x)st[++tp]=x%10+'0',x/=10;
		while(tp)putc(st[tp--]);
	}
	inline void gs(char*s,int&l){
		for(c=gc();c<'a'||c>'z';c=gc());
		for(l=0;c<='z'&&c>='a';c=gc())s[l++]=c;
	}
	inline void ps(const char*s){
		fo(i,0,strlen(s)-1)putc(s[i]);
	}
};
using io::putc;
using io::gi;
using io::gs;
using io::print;

namespace T{
	struct node{
		node*c[2],*pre,*suf;
		int k,sz;
		ll b;
		node();
		void pushup(){sz=c[0]->sz+c[1]->sz+1;}
		ll get(ll x){return k*x+b;}
	}Tnull,*null=&Tnull;
	node::node(){c[0]=c[1]=pre=suf=null,k=b=0;}
	bool lneq(node*x,node*y){return x->k>y->k||x->k==y->k&&x->b<y->b;}
	bool rneq(node*x,node*y){return x->k<y->k||x->k==y->k&&x->b>y->b;}
	void rot(node*&x,bool f){
		node*y=x->c[f];
		x->c[f]=y->c[f^1];
		y->c[f^1]=x;x=y;
		x->pushup();
	}
	void insert(node*&x,node*i){
		if(x==null)return (i->c[0]=i->c[1]=null,(x=i)->pushup());
		bool f=lneq(x,i); 
		insert(x->c[f],i);x->pushup();
		if(x->c[f]->sz>x->sz*.75)rot(x,f);
	}
	node*find(node*x,node*i){
		if(x==null)return null;
		if(rneq(x,i))return find(x->c[0],i);
		node*t=find(x->c[1],i);
		return t==null?x:t;
	}
	void erase(node*&x,node*i){
		if(x==i){
			if(x->c[0]==null)return void(x=x->c[1]);
			if(x->c[1]==null)return void(x=x->c[0]);
			node*y=find(x->c[0],i);
			erase(x->c[0],y);
			y->c[0]=x->c[0];
			y->c[1]=x->c[1];
			(x=y)->pushup();
			return;
		}
		erase(x->c[lneq(x,i)],i);
		x->pushup();
	}
	ll query(node*x,int val){
		if(x==null)return 1E10;
		ll cur=x->get(val);
		if(x->c[0]==null)return min(query(x->c[1],val),cur);
		ll pcur=x->pre->get(val);
		if(pcur<cur)return query(x->c[0],val);
		return min(cur,query(x->c[1],val));
	}
	void del(node*&root,node*i){
		if(i->pre!=null)i->pre->suf=i->suf;
		if(i->suf!=null)i->suf->pre=i->pre;
		erase(root,i);
	}
	bool fix(node*y){
		node*x=y->pre,*z=y->suf;
		if(x==null||z==null)return false;
		return (db)(y->b-x->b)*(y->k-z->k)>=(db)(z->b-y->b)*(x->k-y->k);
	}
	void ins(node*&root,node*i){
		i->c[0]=i->c[1]=i->pre=i->suf=null,i->sz=1;
		node*p=find(root,i);
		if(p!=null&&p->k==i->k)return;
		if(p->suf!=null&&p->suf->k==i->k)del(root,p->suf),p=find(root,i);
		if(p!=null){
			node*q=p->suf;
			i->pre=p;i->suf=q;
			if(fix(i))return;
			if(p!=null)p->suf=i;
			if(q!=null)q->pre=i;
		}else{
			p=root;while(p->c[0]!=null)p=p->c[0];
			i->pre=null;i->suf=p;
			if(fix(i))return;
			if(p!=null)p->pre=i;
		}
		insert(root,i);
		while(i->pre!=null&&fix(i->pre))del(root,i->pre);
		while(i->suf!=null&&fix(i->suf))del(root,i->suf);
	}
}
using namespace T;

const int N=100005;
node t[N],*q[N],*pq[N];
int n,fa[N],a[N],b[N],ql,sz[N];
ll dp[N];
vector<int>e[N];
void dfs(node*x){if(x==null)return;dfs(x->c[0]),q[++ql]=x,dfs(x->c[1]);}
node*explore(node*x,node*y){
	if(x==null)return y;if(y==null)return x;
	if(x->sz<y->sz)swap(x,y);
	ql=0;dfs(y);fo(i,1,ql)ins(x,q[i]);
	return x;
}
bool compare(const int&x,const int&y){return sz[x]<sz[y];}
void dfs(int u){
	node*ret=null;sz[u]=1;
	for(int v:e[u])if(v!=fa[u])fa[v]=u,dfs(v),sz[u]+=sz[v];
	sort(ALL(e[u]),compare);
	for(int v:e[u])if(v!=fa[u])ret=explore(ret,pq[v]);
	if(ret!=null)dp[u]=query(ret,a[u]);
	t[u].k=b[u];t[u].b=dp[u];ins(ret,t+u);pq[u]=ret;
}

int main(){
    gi(n);
	fo(i,1,n)gi(a[i]);
	fo(i,1,n)gi(b[i]);
	fo(i,2,n){
		int u,v;gi(u);gi(v);
		e[u].pb(v);e[v].pb(u);
	}
	dfs(1);
	fo(i,1,n)print(dp[i]),putc(" \n"[i==n]);
	io::flush();
	return 0;
}