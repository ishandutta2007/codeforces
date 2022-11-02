#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,c[maxn],a[maxn];
int d[maxn],ans;
int main() {
	read(n);
	for (int i=1;i<=n;i++) read(c[i]);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) {
		int x=i;
		while (!d[x]) d[x]=i,x=a[x];
		if (d[x]!=i) continue;
		int y=x,t=c[x];
		while (a[x]!=y) x=a[x],t=min(t,c[x]);
		ans+=t;
	}
	printf("%d\n",ans);
	return 0;
}