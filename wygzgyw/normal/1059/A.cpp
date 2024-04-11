#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
const int maxn=(1e5)+10;
typedef long long ll;
int n,a,t[maxn],l[maxn],L;
ll ans;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);read(L);read(a);
	for (int i=1;i<=n;i++)
		read(t[i]),read(l[i]);
	for (int i=1;i<=n;i++)
		ans+=(t[i]-t[i-1]-l[i-1])/a;
	ans+=(L-t[n]-l[n])/a;
	printf("%lld\n",ans);
	return 0;
}