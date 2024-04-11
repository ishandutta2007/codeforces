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
const int maxn=1010;
int n,deg[maxn];
int col[maxn];
int tot,T;
int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		for (int i=1;i<=n;i++) scanf("%d",&deg[i]),col[i]=0;
		tot=0;
		while (1) {
			int x=0;
			for (int i=1;i<=n;i++) if (!col[i]&&deg[i]>=deg[x]) x=i;
			if (!x) break;
			int cnt=0,y,fd=0;
			vector<int> vec; vec.push_back(x);
			while (cnt<deg[x]) {
				printf("? %d\n",x); fflush(stdout);
				cnt++;
				scanf("%d",&y);
				if (col[y]) { fd=y; break; }
				vec.push_back(y);
			}
			if (!fd) { tot++; for (int &x : vec) col[x]=tot; }
			else for (int &x : vec) col[x]=col[fd];
		}
		printf("! "); for (int i=1;i<=n;i++) printf("%d ",col[i]); puts(""); fflush(stdout);
	}
	return 0;
}