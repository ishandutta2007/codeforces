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
const int maxn=(1e4)+10;
const int flag=1;
int T,n,p[maxn],q[maxn],Q[maxn];
int query(int x) {
	printf("? %d\n",x); fflush(stdout);
	if (!flag) {
		int rem=q[x];
		for (int i=1;i<=n;i++) Q[i]=q[p[i]]; for (int i=1;i<=n;i++) q[i]=Q[i];
		return rem;
	}
	scanf("%d",&x);
	return x;
}
int d[maxn],tot;
int ans[maxn];
bool vis[maxn];
int main() {
	scanf("%d",&T); while (T--) {
		scanf("%d",&n);
		if (!flag) for (int i=1;i<=n;i++) scanf("%d",&p[i]);
		for (int i=1;i<=n;i++) q[i]=i,vis[i]=0;
		for (int i=1;i<=n;i++) if (!vis[i]) {
			int x=i; tot=0;
			while (1) {
				d[++tot]=query(i);
				x=d[tot]; if (tot>1&&d[tot]==d[1]) break;
			}
			for (int j=1;j<=tot;j++) vis[d[j]]=1;
			for (int j=1;j<tot;j++) ans[d[j]]=d[j+1];
		}
		printf("! ");
		for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts(""); fflush(stdout);
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