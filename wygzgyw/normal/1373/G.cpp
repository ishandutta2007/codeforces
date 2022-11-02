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
const int maxn=(4e5)+10;
int n,m,k,N;
map<pair<int,int>,int> M;
int tr[maxn*4],lazy[maxn*4];
multiset<int> s;
void pushup(int root) {
	tr[root]=max(tr[root<<1],tr[root<<1|1]);
}
void build(int l,int r,int root) {
	if (l==r) { tr[root]=l; return; }
	int mid=(l+r)>>1;
	build(l,mid,root<<1),build(mid+1,r,root<<1|1);
	pushup(root);
}
void puttag(int root,int delta) {
	tr[root]+=delta,lazy[root]+=delta;
}
void pushdown(int root) {
	if (lazy[root]) puttag(root<<1,lazy[root]),puttag(root<<1|1,lazy[root]),lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,int delta) {
	if (L<=l&&r<=R) { puttag(root,delta); return; }
	int mid=(l+r)>>1; pushdown(root);
	if (L<=mid) add(L,R,l,mid,root<<1,delta);
	if (mid<R) add(L,R,mid+1,r,root<<1|1,delta);
	pushup(root);
}
int query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	int mid=(l+r)>>1,res=0;
	pushdown(root);
	if (L<=mid) res=query(L,R,l,mid,root<<1);
	if (mid<R) res=max(res,query(L,R,mid+1,r,root<<1|1));
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n),read(k),read(m); int x,y;
	N=n*2;
	build(1,N,1);
	while (m--) {
		read(x),read(y);
		int delta=1;
		int t=abs(x-k)+y;
		if (M.count(MP(x,y))) delta=-1,M.erase(MP(x,y)),s.erase(s.find(t));
		else M[MP(x,y)]=1,s.insert(t);
		add(1,t,1,N,1,delta);
		//printf("t=%d\n",t);
		if (s.empty()) printf("0\n");
		else {
			int mx=*--s.end();
			printf("%d\n",max(0,query(1,mx,1,N,1)-n-1));
		}
	}
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