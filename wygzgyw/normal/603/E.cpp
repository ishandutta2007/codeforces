#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(3e5)+10;
int n,m,ans[maxn],pos;
struct node { int x,y,z,id; } d[maxn];
bool cmp(node a,node b) { return a.z<b.z; }
vector<int> tr[maxn*4];
struct Node {
	int x,y,fax,szy,tot;
} A;
struct DSU {
	int tot,sz[maxn],fa[maxn];
	vector<Node> change;
	void init() {
		tot=n;
		change.clear();
		for (int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
	}
	void del(int len) {
		while (change.size()>len) {
			A=change.back();
			fa[A.x]=A.fax;
			sz[A.y]=A.szy;
			tot=A.tot;
			change.pop_back();
		}
	}
	int find(int x) {
		if (fa[x]==x) return x;
		return find(fa[x]);
	}
	void merge(int x,int y) {
		x=find(x); y=find(y);
		if (x==y) return;
		if (sz[x]>sz[y]) swap(x,y);
		A.x=x,A.y=y;
		A.fax=fa[x];
		A.szy=sz[y];
		A.tot=tot;
		change.push_back(A);
		fa[x]=y;
		tot-=(sz[x]&1)+(sz[y]&1);
		sz[y]+=sz[x];
		tot+=sz[y]&1;
	}
} T;
void update(int L,int R,int l,int r,int root,int delta) {
	if (L>R) return;
	if (L<=l&&r<=R) {
		tr[root].push_back(delta);
		return;
	}
	int mid=(l+r)/2;
	if (L<=mid) update(L,R,l,mid,root*2,delta);
	if (mid<R) update(L,R,mid+1,r,root*2+1,delta);
}
void solve(int l,int r,int root) {
	int len=T.change.size(),id;
	for (int i=0;i<tr[root].size();i++) T.merge(d[tr[root][i]].x,d[tr[root][i]].y);
	if (l==r) {
		while (pos<=m&&T.tot) {
			id=d[pos].id;
			if (id>r) { pos++; continue; }
			T.merge(d[pos].x,d[pos].y);
			update(id,r-1,1,m,1,pos);
			pos++;
		}
		if (T.tot) ans[l]=-1;
		else ans[l]=d[pos-1].z;
		T.del(len);
		return;
	}
	int mid=(l+r)/2;
	solve(mid+1,r,root*2+1);
	solve(l,mid,root*2);
	T.del(len);
}
int main() {
//	freopen("1.txt","r",stdin);
	read(n); read(m);
	if (n&1) {
		while (m--) printf("-1\n");
		return 0;
	}
	T.init();
	for (int i=1;i<=m;i++) {
		read(d[i].x),read(d[i].y),read(d[i].z);
		d[i].id=i;
	}
	sort(d+1,d+m+1,cmp);
	pos=1;
	solve(1,m,1);
	for (int i=1;i<=m;i++) printf("%d\n",ans[i]);
	return 0;
}
/*
  0. Enough array size? Enough array size? Enough array size? Interger overflow?
  
  1. Think TWICE, Code ONCE!
  Are there any counterexamples to your algo?
    
  2. Be careful about the BOUNDARIES!
  N=1? P=1? Something about 0?
    
  3. Do not make STUPID MISTAKES!
  Time complexity? Memory usage? Precision error?
*/