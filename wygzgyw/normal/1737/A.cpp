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
const int maxn=210;
int T,n,k;
char s[maxn];
int cnt[30];
int main() {
	read(T);
	while (T--) {
		read(n),read(k);
		scanf("%s",s+1);
		memset(cnt,0,sizeof(cnt));
		for (int i=1;i<=n;i++) cnt[s[i]-'a']++;
		for (int i=1;i<=k;i++) {
			int fd;
			for (int j=0;j<=n/k;j++) if (j==n/k||!cnt[j]) { fd=j; break; }
			printf("%c",'a'+fd);
			for (int j=0;j<fd;j++) cnt[j]--;
		}
		puts("");
	}
	return 0;
}