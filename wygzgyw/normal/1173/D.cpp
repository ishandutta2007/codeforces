#include <bits/stdc++.h>
#define dbug(x) cout<<#x<<"="<<x<<endl
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0';ch=getchar();} while ('0'<=ch&&ch<='9'); t*=f;
}
typedef long long ll;
const ll mod=998244353;
int n,x,y,d[200010];
ll ans=1;
int main() {
	//freopen("1.txt","r",stdin);
	read(n);
	for (int i=1;i<n;i++) {
		read(x); read(y);
		d[x]++; d[y]++;
	}
	for (int i=1;i<=n;i++)
		for (int j=1;j<=d[i];j++) ans=ans*j%mod;
	printf("%lld\n",ans*n%mod);
	return 0;
}