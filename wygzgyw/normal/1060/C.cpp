#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll INF=1LL<<50;
const int maxn=2010;
int n,m;
ll a[maxn],b[maxn],x;
ll s[maxn],t[maxn],ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n); read(m);
	for (int i=1;i<=n;i++)
		read(a[i]),a[i]+=a[i-1],s[i]=INF;
	for (int i=1;i<=m;i++)
		read(b[i]),b[i]+=b[i-1],t[i]=INF;
	read(x);
	for (int i=1;i<=n;i++)
	for (int j=i;j<=n;j++)
		s[j-i+1]=min(s[j-i+1],a[j]-a[i-1]);
	for (int i=1;i<=m;i++)
	for (int j=i;j<=m;j++)
		t[j-i+1]=min(t[j-i+1],b[j]-b[i-1]);
	for (int i=1;i<=n;i++)
	for (int j=1;j<=m;j++)
		if (s[i]*t[j]<=x) ans=max(ans,(ll)i*j);
	printf("%lld\n",ans);
	return 0;
}