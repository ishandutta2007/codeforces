#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <iostream>
#include <bitset>
using namespace std;
const int N=300005;
#define ls ch[rt][0]
#define rs ch[rt][1]
// int rd(){int x;scanf("%d",&x);return x;}
#define nc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
char buf[100000],*p1,*p2;
inline int rd()
{
	register int x=0;register char c=nc();
	while(c<48)c=nc();
	while(c>47)x=((x+(x<<2))<<1)+(c^48),c=nc();
	return x;
}
#define ll long long
int head[N],to[N<<1],nxt[N<<1],n,T;
ll ans[N],cov[N],C[N];
int dfn[N],dep[N],mx[N][2],ch[N][2],mn[N][2],root,now,son[N],cnt;
inline void add(int u,int v) {
	to[++cnt]=v; nxt[cnt]=head[u]; head[u]=cnt;
}
struct Point {
	int p[2];
	friend bool operator < (const Point &x,const Point &y) {
		return x.p[now]==y.p[now]?x.p[!now]<y.p[!now]:x.p[now]<y.p[now];
	}
}a[N],b[N];
void pushup(int rt,int x) {
	int i;
	for(i=0;i<2;i++) mx[rt][i]=max(mx[rt][i],mx[x][i]),mn[rt][i]=min(mn[rt][i],mn[x][i]);
}
int build(int l,int r,int type) {
	int rt=(l+r)>>1; now=type;
	nth_element(a+l,a+rt,a+r+1);
	int i;
	for(i=0;i<2;i++) mx[rt][i]=mn[rt][i]=a[rt].p[i];
	if(l<rt) ch[rt][0]=build(l,rt-1,!type),pushup(rt,ch[rt][0]);
	if(r>rt) ch[rt][1]=build(rt+1,r,!type),pushup(rt,ch[rt][1]);
	return rt;
}
#define judge(t1,t2,t3,t4)( (t1<t3||t1>t4)&&(t2<t3||t2>t4))
void update(int x,int y,int z,int w,int rt,int c) {
	if(mn[rt][0]>=x&&mx[rt][0]<=z&&mn[rt][1]>=y&&mx[rt][1]<=w) {cov[rt]+=c; return ;}
	if(mx[rt][0]<x||mn[rt][0]>z||mx[rt][1]<y||mn[rt][1]>w) return ;
	if(a[rt].p[0]>=x&&a[rt].p[0]<=z&&a[rt].p[1]>=y&&a[rt].p[1]<=w) C[rt]+=c;
	if(ls) update(x,y,z,w,ls,c);
	if(rs) update(x,y,z,w,rs,c);
}
ll query(int x) {
	int rt=root;
	now=0;
	while(1) {
		if(b[x]<a[rt]) rt=ls;
		else if(a[rt]<b[x]) rt=rs;
		else return C[rt];
		now=!now;
	}
}
void dfs(int x,int y) {
	int i;
	dfn[x]=++dfn[0];
	dep[x]=dep[y]+1;
	for(i=head[x];i;i=nxt[i]) {
		if(to[i]!=y) dfs(to[i],x);
	}
	son[x]=dfn[0];
}
void DFS(int rt) {
	if(!rt) return ;
	C[rt]+=cov[rt];
	cov[ls]+=cov[rt];
	cov[rs]+=cov[rt];
	DFS(ls); DFS(rs);
}
int main() {
	int Q;
	n=rd();
	int i,x,y;
	for(i=2;i<=n;i++) {
		x=rd(); y=rd(); add(x,y); add(y,x);
	}
	Q=rd();
	dfs(1,0);
	for(i=1;i<=n;i++) a[i].p[0]=dfn[i],a[i].p[1]=dep[i],b[i]=a[i];
	root=build(1,n,0);
	int z;

	for(i=1;i<=Q;i++) {
		x=rd(); y=rd(); z=rd();
		update(dfn[x],dep[x],son[x],dep[x]+y,root,z);
	}
	DFS(root);
	for(i=1;i<=n;i++) printf("%lld ",query(i));
}