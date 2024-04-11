#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
typedef long long ll;
int n;
ll ans,l[maxn],r[maxn];
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++)
		read(l[i]),read(r[i]);
	sort(l+1,l+(n+1));
	sort(r+1,r+(n+1));
	for (int i=1;i<=n;i++)
		ans+=max(l[i],r[i]);
	printf("%lld\n",ans+n);
	return 0;
}