#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
const int M=2000005;
int axiba=0;
namespace Tarjin{
	int dfn[M],low[M],be[M];
	int stk[M],inq[M];
	vector<int> e[M];
	void add(int x,int y){
		++axiba;
		e[x].PB(y);
	}
	void tarjan(int x){
		dfn[x]=low[x]=++*dfn;
		stk[++*stk]=x; inq[x]=1;
		for (auto i:e[x])
			if (!dfn[i]){
				tarjan(i);
				low[x]=min(low[x],low[i]);
			}
			else if (inq[i])
				low[x]=min(low[x],dfn[i]);
		if (low[x]==dfn[x]){
			int y=19260817; ++*be;
			for (;y!=x;){
				y=stk[(*stk)--];
				be[y]=*be; inq[y]=0;
			}
		}
	}
	void tar(int limit){
		For(i,1,limit)
			if (!dfn[i]) tarjan(i);
	}
}
int n,m,ndd,fa[N];
int rt[N],ls[M],rs[M];
int Tag[M],nd;
pii t[M];
vector<int> e[N];
vector<int> v[N];
void dfs(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dfs(i);
		}
}
pii get_info(int x,int tg){
	if (!tg) return pii(0,0);
	if (tg==1) return pii(x*2-1,x*2);
	if (tg==2) return pii(x*2,x*2-1);
	int t1=++ndd,t2=++ndd;
	Tarjin::add(x*2-1,t1);
	Tarjin::add(x*2,t1);
	Tarjin::add(t2,x*2-1);
	Tarjin::add(t2,x*2);
	return pii(t1,t2);
}
void pushup(int k){
	pii vl=t[ls[k]],vr=t[rs[k]];
	if (vl==pii(0,0)) t[k]=vr;
	else if (vr==pii(0,0)) t[k]=vl;
	else{
		int t1=++ndd,t2=++ndd;
		Tarjin::add(vl.fi,vr.se);
		Tarjin::add(vr.fi,vl.se);
		Tarjin::add(vl.fi,t1);
		Tarjin::add(vr.fi,t1);
		Tarjin::add(t2,vl.se);
		Tarjin::add(t2,vr.se);
		t[k]=pii(t1,t2);
	}
}
void insert(int &k,int l,int r,int x){
	if (!k) k=++nd;
	if (l==r){
		Tag[k]^=(x&1?1:2);
		t[k]=get_info(l,Tag[k]);
		return;
	}
	int mid=(l+r)/2;
	if (x<=2*mid) insert(ls[k],l,mid,x);
	else insert(rs[k],mid+1,r,x);
}
int Merge(int x,int y,int l,int r){
	if (!x||!y) return x+y;
	if (l==r){
		Tag[x]^=Tag[y];
		t[x]=get_info(l,Tag[x]);
		return x;
	}
	int mid=(l+r)/2,k=++nd;
	ls[k]=Merge(ls[x],ls[y],l,mid);
	rs[k]=Merge(rs[x],rs[y],mid+1,r);
	return k;
}
void pushup(int k,int l,int r,int p){
	if (!k||k<=p||l==r) return;
	int mid=(l+r)/2;
	pushup(ls[k],l,mid,p);
	pushup(rs[k],mid+1,r,p);
	pushup(k);
}
void build(int x){
	for (auto i:e[x])
		if (i!=fa[x])
			build(i);
	int p=nd;
	for (auto i:v[x])
		insert(rt[x],1,m,i);
	for (auto i:e[x])
		if (i!=fa[x])
			rt[x]=Merge(rt[x],rt[i],1,m);
	pushup(rt[x],1,m,p);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1);
	scanf("%d",&m); ndd=2*m;
	For(i,1,2*m){
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].PB(i); v[y].PB(i);
	}
	build(1);
	Tarjin::tar(2*m);
	For(i,1,m)
		if (Tarjin::be[i*2-1]==Tarjin::be[i*2])
			return puts("NO"),0;
	puts("YES");
	For(i,1,m)
		printf("%d\n",Tarjin::be[i*2-1]<Tarjin::be[i*2]?1:2);
}