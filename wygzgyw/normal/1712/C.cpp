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
int T,n,a[maxn],lst[maxn],nxt[maxn];
int ans,pre[maxn],mx[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		for (int i=1;i<=n;i++) lst[i]=0;
		for (int i=n;i>=1;i--) {
			nxt[i]=lst[a[i]],lst[a[i]]=i;
		}
		for (int i=1;i<=n;i++) lst[i]=0;
		for (int i=1;i<=n;i++) {
			pre[i]=pre[i-1]+(lst[a[i]]==0);
			lst[a[i]]=1;
		}
		int bad=0;
		for (int i=n;i>=1;i--) {
			if (a[i-1]>a[i]) { bad=i; break; }
		}
		if (!bad) { puts("0"); continue; }
		ans=pre[n];
		for (int i=1;i<=n;i++) mx[i]=max(mx[i-1],nxt[i]);
		for (int i=bad;i<=n;i++) {
			if (mx[i-1]<i) ans=min(ans,pre[i-1]);
		}
		printf("%d\n",ans);
	}
	return 0;
}