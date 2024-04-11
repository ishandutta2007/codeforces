#include <bits/stdc++.h>
using namespace std;
template <typename T> void read(T &t) {
	t=0; char ch=getchar(); int f=1;
	while ('0'>ch||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	do {(t*=10)+=ch-'0'; ch=getchar();} while ('0'<=ch&&ch<='9');t*=f;
}
typedef long long ll;
const ll mod=(1e9)+7;
const int maxn=510;
int n,cnt[maxn];
ll ans,mi[maxn];
int main() {
	read(n);
	for (int i=1;i<=n;i++) {
		int x; read(x);
		if (x!=-1) cnt[x]++;
	}
	mi[0]=1;
	for (int i=1;i<=n;i++)
		mi[i]=mi[i-1]*2%mod;
	ans=mi[n-1]-1; ans=(ans+mod)%mod;
	for (int i=1;i<=n;i++)
		ans-=mi[cnt[i]]-1,ans=(ans+mod)%mod;
	printf("%lld\n",ans);
	return 0;
}