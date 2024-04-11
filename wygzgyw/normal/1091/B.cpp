#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=1010;
int n,a[maxn],b[maxn],x[maxn],y[maxn],tot;
int cnt;
pair<int,int> d[maxn*maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),read(b[i]);
	for (int i=1;i<=n;i++) read(x[i]),read(y[i]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=n;j++)
		d[++tot]=make_pair(a[i]+x[j],b[i]+y[j]);
	sort(d+1,d+tot+1);
	for (int i=1;i<=tot;i++) {
		if (d[i]==d[i-1]) cnt++; else {
			if (cnt>=n) {
				printf("%d %d\n",d[i-1].first,d[i-1].second); return 0;
			}
			cnt=1;
		}
	}
	printf("%d %d\n",d[tot].first,d[tot].second);
	return 0;
}