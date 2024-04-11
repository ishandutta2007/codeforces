#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N;
ll D[1000100];
ll po[1000100];

int main () {
	scanf("%d",&N);
	po[0] = 1;
	for (int i=1;i<=N;i++) {
		po[i] = po[i-1]*2%MOD;
		for (int j=i;j<=N;j+=i) D[j]++;
	}
	ll ans = 0;
	for (int a=0;a<N;a++) {
		ans += (a?po[a-1]:1)*D[N-a]%MOD;
	}
	printf("%lld\n",ans%MOD);

	return 0;
}