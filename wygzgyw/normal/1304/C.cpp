#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=110;
int T,n,t,tot;
bool flag;
int lst,l,r,x,y;
struct node { int t,l,r; } d[maxn],e[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		lst=0;
		read(l); r=l;
		flag=1;
		for (int i=1;i<=n;i++)
			read(d[i].t),read(d[i].l),read(d[i].r);
		tot=0;
		for (int i=1;i<=n;i++) {
			if (!tot||e[tot].t!=d[i].t) e[++tot]=d[i];
			else {
				e[tot].l=max(d[i].l,e[tot].l);
				e[tot].r=min(d[i].r,e[tot].r);
				if (e[tot].l>e[tot].r) { flag=0; break; }
			}
		}
		if (!flag) { printf("NO\n"); continue; }
		for (int i=1;i<=tot;i++) {
			t=e[i].t,x=e[i].l,y=e[i].r;
			
			t-=lst;
			//printf("%d %d\n",l,r);
			if (l<=x&&y<=r) l=x,r=y;
			else if (x<=l&&r<=y) {
				l=max(x,l-t);
				r=min(y,r+t);
			} else if (r<=x) {
				if (r+t<x) { flag=0; break; }
				r=min(y,r+t);
				l=x;
			} else if (l>=y) {
				if (l-t>y) { flag=0; break; }
				r=y;
				l=max(x,l-t);
			} else if (l<=x) {
				r=min(y,r+t);
				l=x;
			} else {
				r=y;
				l=max(x,l-t);
			}
			lst=e[i].t;
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
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