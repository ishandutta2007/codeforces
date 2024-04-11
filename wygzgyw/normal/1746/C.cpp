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
int T,n,a[maxn];
pair<int,int> d[maxn];
int tot,ans[maxn];

int main() {
//	freopen("1.txt","r",stdin);
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]);
		tot=0; for (int i=2;i<=n;i++) if (a[i-1]>a[i]) d[++tot]=MP(a[i-1]-a[i],i);
		sort(d+1,d+tot+1),reverse(d+1,d+tot+1);
		int now=n;
		for (int i=1;i<=n;i++) ans[i]=1;
		for (int i=1;i<=tot;i++) {
			ans[now]=d[i].second; now--;
		}
		for (int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
	}
	return 0;
}