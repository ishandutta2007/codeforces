#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, x, t;

LL f1(LL n) { return n * 1LL * (n - 1) / 2; }
LL f2(LL n) { return n * 1LL * (n + 1) / 2; }

void solve()
{
	scanf("%d%d%d", &n, &x, &t);
	LL k = t / x;
	LL ans = f1(n) - f2(max(0LL, n - 1 - k));
	printf("%lld\n", ans);
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}