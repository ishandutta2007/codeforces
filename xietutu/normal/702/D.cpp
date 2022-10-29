#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL d, k, a, b, t, lmid, rmid;
LL F(LL x) {
	LL c = min(d, x * k);
	return c * a + (d - c) * b + max(0LL, x - 1) * t;
}
int main() {
	cin >> d >> k >> a >> b >> t;
	LL l = 0, r = (d + k - 1) / k;
	while(r - l > 2) {
		lmid = (l + l + r) / 3;
		rmid = (l + r + r) / 3;
		if(F(lmid) < F(rmid)) r = rmid;
		else l = lmid;
	}
	LL ret = 1000000000000000000LL;
	for(LL i = l; i <= r; ++i) 
		ret = min(ret, F(i));
	printf("%I64d\n", ret);
}