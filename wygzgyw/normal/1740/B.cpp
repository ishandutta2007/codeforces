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
typedef long long ll;
const int maxn=(1e6)+10;
int T,n,tot; ll ans;
int a[maxn],b[maxn];
pair<int,int> d[maxn];
ll now;
int A[maxn],B[maxn];
int main() {
	read(T);
	while (T--) {
		read(n);
		tot=0; ans=1e18;
		for (int i=1;i<=n;i++) {
			read(a[i]),read(b[i]);
			A[i]=a[i],B[i]=b[i];
			d[++tot]=MP(a[i],i),d[++tot]=MP(b[i],-i);
			a[i]=b[i]=-1;
		}
		sort(d+1,d+tot+1); now=0; int cnt=n;
		for (int i=1;i<=tot;i++) {
			int x=abs(d[i].second);
			if (d[i].second>0) {
				a[x]=d[i].first;
				if (b[x]==-1) cnt--,now+=B[x];
				else now-=A[x],now+=min(A[x],B[x]);
			} else {
				b[x]=d[i].first;
				if (a[x]==-1) cnt--,now+=A[x];
				else now-=B[x],now+=min(A[x],B[x]);
			}
			if (!cnt) ans=min(ans,2*(now+d[i].first));
		}
		printf("%lld\n",ans);
	}
	return 0;
}