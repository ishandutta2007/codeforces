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
const int maxn=110;
int T,n,cnt[maxn];

int main() {
	read(T);
	while (T--) {
		int c;
		read(n); read(c);
		memset(cnt,0,sizeof(cnt));
		int x; for (int i=1;i<=n;i++) read(x),cnt[x]++;
		int ans=0;
		for (int i=1;i<=100;i++) ans+=min(c,cnt[i]);
		printf("%d\n",ans);
	}
	return 0;
}