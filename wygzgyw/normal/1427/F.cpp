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
const int maxn=1210;
int n;
int fa[maxn],tot;
struct node {
	int a[3],cnt;
	void insert(int x) {
		a[cnt++]=x;
	}
} p[maxn];
int st[maxn],top,vis[maxn];
int col[maxn],mk[maxn],son[maxn];
int main() {
	read(n);
	for (int i=1;i<=n*3;i++) {
		int x; read(x); mk[x]=1;
	}
	for (int i=1;i<=n*6;i++) {
		if (top&&col[st[top]]==mk[i]) {
			p[st[top]].insert(i);
			if (p[st[top]].cnt==3) top--;
		} else {
			tot++;
			fa[tot]=st[top],son[fa[tot]]++;
			col[tot]=mk[i];
			p[tot].insert(i);
			st[++top]=tot;
		}
	}
	//for (int i=1;i<=tot;i++) printf("%d ",col[i]); puts("");
	//for (int i=1;i<=tot;i++) printf("%d %d %d\n",p[i].a[0],p[i].a[1],p[i].a[2]);
	for (int i=1;i<=n*2;i++) {
		int fd=0;
		for (int j=1;j<=tot;j++) if (!vis[j]&&col[j]==(i&1)&&!son[j]) {
			fd=j;
			if ((i&1)||fa[j]) break;
		}
		assert(fd);
		vis[fd]=1;
		printf("%d %d %d\n",p[fd].a[0],p[fd].a[1],p[fd].a[2]);
		son[fa[fd]]--;
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