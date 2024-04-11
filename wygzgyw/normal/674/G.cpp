#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=150010;
int n,m,p,K,len[maxn*4],lazy[maxn*4];
struct Node { int x,v; };
int tmp;
struct node {
	Node a[7];
	int tot;
	void init(int x,int y) {
		a[tot=1]=(Node){x,y};
	}
	void print() {
		printf("%d ",tot);
		for (int i=1;i<=tot;i++) printf("%d ",a[i].x);
		printf("\n");
	}
	friend node operator + (node t1,node t2) {
		node res=t2;
		bool flag;
		int mn,pos;
		for (int i=1;i<=t1.tot;i++) {
			flag=0;
			for (int j=1;j<=res.tot;j++)
				if (res.a[j].x==t1.a[i].x) {
					flag=1;
					res.a[j].v+=t1.a[i].v;
					break;
				}
			if (flag) continue;
			if (res.tot<K) {
				res.a[++res.tot]=t1.a[i];
				continue;
			}
			mn=maxn+1,pos=0;
			for (int j=1;j<=res.tot;j++)
				if (mn>res.a[j].v) mn=res.a[j].v,pos=j;
			if (t1.a[i].v<mn) {
				for (int j=1;j<=res.tot;j++)
					res.a[j].v-=t1.a[i].v;
			} else {
				tmp=res.a[pos].v;
				res.a[pos]=t1.a[i];
				for (int j=1;j<=res.tot;j++)
					res.a[j].v-=tmp;
			}
			pos=0;
			for (int j=1;j<=res.tot;j++)
				if (res.a[j].v>0)
					res.a[++pos]=res.a[j];
			res.tot=pos;
		}
		return res;
	}
} tr[maxn*4],A;
void build(int l,int r,int root) {
	len[root]=r-l+1;
	if (l==r) {
		int x; read(x);
		tr[root].init(x,1);
		return;
	}
	int mid=(l+r)/2;
	build(l,mid,root*2);
	build(mid+1,r,root*2+1);
	tr[root]=tr[root*2]+tr[root*2+1];
}
void pushdown(int root) {
	if (!lazy[root]) return;
	lazy[root*2]=lazy[root*2+1]=lazy[root];
	tr[root*2].init(lazy[root],len[root*2]);
	tr[root*2+1].init(lazy[root],len[root*2+1]);
	lazy[root]=0;
}
void add(int L,int R,int l,int r,int root,int z) {
	if (L<=l&&r<=R) {
		tr[root].init(z,r-l+1);
		lazy[root]=z;
		return;
	}
	pushdown(root);
	int mid=(l+r)/2;
	if (L<=mid) add(L,R,l,mid,root*2,z);
	if (mid<R) add(L,R,mid+1,r,root*2+1,z);
	tr[root]=tr[root*2]+tr[root*2+1];
}
node query(int L,int R,int l,int r,int root) {
	if (L<=l&&r<=R) return tr[root];
	pushdown(root);
	int mid=(l+r)/2;
	node res; res.tot=0;
	if (L<=mid) res=query(L,R,l,mid,root*2);
	if (mid<R) res=res+query(L,R,mid+1,r,root*2+1);
	return res;
}
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m); read(p);
	K=100/p;
	build(1,n,1);
	int op,l,r,z;
	while (m--) {
		read(op); read(l); read(r);
		if (op==1) {
			read(z);
			add(l,r,1,n,1,z);
		} else {
			A=query(l,r,1,n,1);
			A.print();
		}
	}
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