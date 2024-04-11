#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i ++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i ++)
#define MP make_pair
 
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL hC, dC, hM, dM, w, a;
int k;

void solve()
{
	scanf("%lld%lld%lld%lld%d%lld%lld", &hC, &dC, &hM, &dM, &k, &w, &a);
	bool ok = false;
	rep(i, k + 1) {
		LL HC = hC + i * 1LL * a;
		LL DC = dC + (k - i) * 1LL * w;
		LL x = (hM + DC - 1) / DC;
		LL y = (HC + dM - 1) / dM;
		if(x <= y) ok = true;
	}
	puts(ok ? "YES" : "NO");
}

int main()
{
	int T;
	scanf("%d", &T);
	while(T--) solve();
	return 0;
}