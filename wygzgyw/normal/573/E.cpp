// wygzgyw
#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
template <typename T> void write(T t) {
	if (t<0) { putchar('-'); write(-t); return; }
	if (t>9) write(t/10);
	putchar('0'+t%10);
}
template <typename T> void writeln(T t) { write(t); puts(""); }
#define MP make_pair
typedef long long ll;
const int maxn=(1e5)+10;
int n;
ll a[maxn];
int sz[maxn],rd[maxn],rt,tot;
ll lazy1[maxn],lazy2[maxn],val[maxn];
int ls[maxn],rs[maxn];
void pushup(int root) { if (root) sz[root]=sz[ls[root]]+sz[rs[root]]+1; }
int GET() {
	return (rand()%10000)*10000+rand()%10000;
}
void puttag(int root,ll d1,ll d2) {
	if (root) {
		lazy1[root]+=d1,lazy2[root]+=d2,val[root]+=d1*(sz[ls[root]]+1)+d2;
	}
}
void pushdown(int root) {
	puttag(ls[root],lazy1[root],lazy2[root]);
	puttag(rs[root],lazy1[root],lazy2[root]+lazy1[root]*(sz[ls[root]]+1));
	lazy1[root]=lazy2[root]=0;
}
ll query(int root,int k) {
	pushdown(root);
	if (k<=sz[ls[root]]) return query(ls[root],k);
	if (k>sz[ls[root]]+1) return query(rs[root],k-sz[ls[root]]-1);
	return val[root];
}
int merge(int x,int y) {
	if (!x||!y) return x+y;
	pushdown(x),pushdown(y);
	if (rd[x]>rd[y]) {
		ls[y]=merge(x,ls[y]);
		pushup(y); return y;
	}
	rs[x]=merge(rs[x],y);
	pushup(x); return x;
}
void split(int rt,int k,int &x,int &y) {
	if (!rt) x=y=0;
	else {
		pushdown(rt);
		if (k>sz[ls[rt]]) x=rt,split(rs[rt],k-sz[ls[rt]]-1,rs[x],y),pushup(x);
		else y=rt,split(ls[rt],k,x,ls[y]),pushup(y);
	}
}
void insert(int k,ll delta) {
	int x,y;
	split(rt,k,x,y);
	tot++; val[tot]=delta,sz[tot]=1,rd[tot]=GET();
	rt=merge(x,merge(tot,y));
}
void update(int k,ll d1,ll d2) {
	int x,y;
	split(rt,k,x,y);
	puttag(y,d1,d2);
	rt=merge(x,y);
}
ll dfs(int rt) {
	if (!rt) return 0;
	pushdown(rt);
	return max(max(dfs(ls[rt]),dfs(rs[rt])),val[rt]);
}
int main() {
	srand(23333);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]);
	rt=tot=1,sz[1]=1;
	for (int i=1;i<=n;i++) {
		int l=0,r=i-1,res=i-1,mid;
		//for (int j=0;j<i;j++) printf("%lld ",query(rt,j+1)); puts("");
		while (l<=r) {
			mid=(l+r)>>1;
			if (query(rt,mid+1)+a[i]*(mid+1)>query(rt,mid+2)) res=mid,r=mid-1; else l=mid+1;
		}
		res++;
		//printf("res=%d\n",res);
		ll tmp=query(rt,res);
		insert(res,tmp);
		update(res,a[i],a[i]*(res-1));
	}
	printf("%lld\n",dfs(rt));
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Integer overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/