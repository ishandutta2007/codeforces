#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do { (t*=10)+=ch-'0'; ch=getchar(); } while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
int T,n; ll ans,a[310];

int main() {
	read(T);
	while (T--) {
		read(n);
		for (int i=1;i<=n;i++) read(a[i]); ans=3e9;
		for (int i=1;i<=n;i++) for (int j=1;j<=n;j++) for (int k=1;k<=n;k++)
			if (j!=i&&i!=k&&j!=k) ans=min(ans,abs(a[i]-a[j])+abs(a[i]-a[k]));
		printf("%lld\n",ans);
	}
	return 0;
}