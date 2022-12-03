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
const int maxn=(2e5)+10;
int n,q,rem[maxn],a[maxn],s[maxn],cnt[maxn];
map<int,int> lst[2];
int main() {
	read(n),read(q);
	for (int i=1;i<=n;i++) read(a[i]),s[i]=s[i-1]^a[i],cnt[i]=cnt[i-1]+(a[i]==0);
	for (int i=n;i>=1;i--) {
		lst[i&1][s[i]]=i;
		rem[i]=lst[i&1][s[i-1]];
	}
	while (q--) {
		int l,r; read(l),read(r);
		if (s[l-1]!=s[r]) { puts("-1"); continue; }
		if (cnt[l-1]+r-l+1==cnt[r]) { puts("0"); continue; }
		if ((r-l+1)%2==1) puts("1");
		else if (a[l]==0||a[r]==0) puts("1");
		else if (rem[l]&&rem[l]<=r) puts("2");
		else puts("-1");
	}
	return 0;
}