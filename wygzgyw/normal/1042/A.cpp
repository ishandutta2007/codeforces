#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=100010;
int n,m,a[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+(n+1));
	int s=0,mx=0;
	for (int i=1;i<=n;i++) s+=a[i],mx=max(mx,a[i]);
	s+=m;
	if (s%n==0) s/=n; else s=s/n+1;
	printf("%d %d\n",max(s,mx),mx+m);
	return 0;
}