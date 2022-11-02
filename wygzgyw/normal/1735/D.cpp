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
const int maxn=1010;
int n,k;
ll ans,deg[maxn];
ll mi[30];
int d[maxn][20];
map<ll,int> M;
int main() {
	read(n),read(k);
	mi[0]=1; for (int i=1;i<=k;i++) mi[i]=mi[i-1]*3;
	for (int i=1;i<=n;i++) {
		ll t=0;
		for (int j=0;j<k;j++) read(d[i][j]),t+=d[i][j]*mi[j];
		M[t]=i;
	}
	for (int i=1;i<=n;i++) for (int j=i+1;j<=n;j++) {
		ll t=0;
		for (int v=0;v<k;v++) {
			int a=d[i][v],b=d[j][v];
			int c=(a==b?a:3-a-b);
			t+=c*mi[v];
		}
		if (M.count(t)) {
			int a=i,b=j,c=M[t];
			deg[a]++,deg[b]++,deg[c]++;
		}
	}
	for (int i=1;i<=n;i++) {
		deg[i]/=3;
		ans+=deg[i]*(deg[i]-1)/2;
	}
	printf("%lld\n",ans);
	return 0;
}