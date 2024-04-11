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
const int maxn=(3e5)+10;
int T,n,k,a[maxn];
vector<int> g[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=0;i<=n+1;i++) g[i].clear();
		for (int i=1;i<=n;i++) read(a[i]),g[a[i]].push_back(i);
		k=0;
		for (int i=1;i<=n;i++) {
			if (a[i]>i) k=i;
		}
		printf("%d\n",k);
		int fst=((int)g[0].size()?0:n+1);
		while (1) {
			int y=0;
			for (int &x : g[fst]) {
				if ((int)g[x].size()) y=x;
				else printf("%d ",x);
			}
			if (!y) break;
			printf("%d ",y);
			fst=y;
		}
		puts("");
	}
	return 0;
}