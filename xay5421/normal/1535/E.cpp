// author: xay5421
// created: Sat Jun  5 00:09:59 2021
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long LL;
const int N=300005;
int Q,a[N],c[N],good[N];
int mymax(int k1,int k2){
	if(!a[k1])return k2;
	if(!a[k2])return k1;
	if(c[k1]<c[k2])return k1;
	if(c[k2]<c[k1])return k2;
	return max(k1,k2);
}
namespace LCT{
	int ch[N][2],fa[N],rev[N];
	int get(int u){return ch[fa[u]][1]==u;}
	int isroot(int u){return ch[fa[u]][0]!=u&&ch[fa[u]][1]!=u;}
	void update(int u){
		good[u]=u;
		if(ch[u][1]){
			good[u]=mymax(good[u],good[ch[u][1]]);
		}
		if(ch[u][0]){
			good[u]=mymax(good[u],good[ch[u][0]]);
		}
	}
	void pushdown(int u){
		if(rev[u])std::swap(ch[u][0],ch[u][1]),rev[ch[u][0]]^=1,rev[ch[u][1]]^=1,rev[u]^=1;
	}
	void rotate(int u){
		int p=fa[u],gp=fa[p],x=get(u);
		if(!isroot(p))ch[gp][get(p)]=u;fa[u]=gp;
		ch[p][x]=ch[u][x^1],fa[ch[u][x^1]]=p;
		ch[u][x^1]=p,fa[p]=u;
		update(p),update(u);
	}
	int st[N];
	void splay(int u){
		st[*st=1]=u;
		for(int i=u;!isroot(i);i=fa[i])st[++*st]=fa[i];
		for(int i=*st;i>=1;--i)pushdown(st[i]);
		for(;!isroot(u);rotate(u))
		    if(!isroot(fa[u]))
		        rotate(get(u)==get(fa[u])?fa[u]:u);
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
		splay(u),rev[u]^=1; 
	}
	void link(int u,int v){
		makeroot(u),fa[u]=v;
	}
	int findroot(int u){
		access(u),splay(u);
		while(ch[u][0])u=ch[u][0];
		return splay(u),u;
	}
	void cut(int u,int v){
		makeroot(u),access(v),splay(v);
		if(ch[u][1]||fa[u]!=v)return;
		fa[u]=ch[v][0]=0;
	}
}
using namespace LCT;
LL rem,res1,res2;
void qry(int u){
	access(u);
	while(rem){
		splay(u);
		int k1=good[u];
		splay(k1);
		if(!a[k1])return;
		LL t=min((LL)a[k1],rem);
		res1+=t;
		res2+=t*c[k1];
		a[k1]-=t,rem-=t;
	}
}
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d%d%d",&Q,&a[1],&c[1]);
	good[1]=1;
	rep(_,2,Q+1){
		int t;
		scanf("%d",&t);
		if(t==1){
			good[_]=_;
			int _fa,_a,_c;
			scanf("%d%d%d",&_fa,&_a,&_c);
			fa[_]=_fa+1;
			a[_]=_a;
			c[_]=_c;
		}else{
			int v,w;
			scanf("%d%d",&v,&w);
			++v;
			res1=0,res2=0;
			rem=w;
			qry(v);
			printf("%lld %lld\n",res1,res2);
			fflush(stdout);
		}
	}
	return 0;
}