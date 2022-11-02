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
const int maxn=(1e5)+10;
int n,m,q;
struct node {
	int x,y,z;
} E[maxn],Q[maxn];
int fa[maxn];
int ans[maxn],vis[maxn];
int find(int x) { if (fa[x]==x) return x; return fa[x]=find(fa[x]); }
void merge(int x,int y) { fa[find(x)]=find(y); }
int main() {
	read(n),read(m);
	for (int i=1;i<=m;i++) read(E[i].x),read(E[i].y),read(E[i].z);
	read(q);
	for (int i=1;i<=q;i++) read(Q[i].x),read(Q[i].y),ans[i]=2;
	for (int i=0;i<30;i++) {
		for (int j=1;j<=n;j++) fa[j]=j;
		for (int j=1;j<=m;j++) if (E[j].z>>i&1) merge(E[j].x,E[j].y);
		for (int j=1;j<=q;j++) if (find(Q[j].x)==find(Q[j].y)) ans[j]=0;
	}
	for (int i=1;i<30;i++) {
		for (int j=1;j<=n;j++) fa[j]=j,vis[j]=0;
		for (int j=1;j<=m;j++) if (E[j].z>>i&1) merge(E[j].x,E[j].y);
		for (int j=1;j<=m;j++) if (E[j].z%2==0) vis[find(E[j].x)]=vis[find(E[j].y)]=1;
		for (int j=1;j<=q;j++) if (ans[j]==2&&vis[find(Q[j].x)]) ans[j]=1;
	}
	for (int i=1;i<=q;i++) printf("%d\n",ans[i]);
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