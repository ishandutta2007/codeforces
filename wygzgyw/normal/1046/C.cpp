#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(2e5)+10;
int n,m,a[maxn],b[maxn],pos,ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	for (int i=1;i<=n;i++) read(b[i]);
	a[m]+=b[1];
	ans=m; pos=m-1;
	for (int i=2;i<=n&&pos;i++)
		if (b[i]+a[pos]<=a[m])
			ans--,pos--;
	printf("%d\n",ans);
	return 0;
}