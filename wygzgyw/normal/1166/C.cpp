#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const int maxn=(2e5)+10;
ll ans;
int n,a[maxn],pos;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<=n;i++) read(a[i]),a[i]=abs(a[i]);
	sort(a+1,a+n+1); pos=n;
	for (int i=n;i>=1;i--) {
		while (a[pos]>2*a[i]) pos--;
		ans+=pos-i;
	} printf("%lld\n",ans);
	return 0;
}