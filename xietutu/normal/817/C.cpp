#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n, s, ans;
LL Abs(LL x) {
	return x > 0 ? x : -x;
}
bool check(LL x) {
	int ret = 0;
	LL tmp = x;
	while (x) {
		ret += x % 10;
		x /= 10;
	}
	return Abs(ret - tmp) >= s;
}
int main() {
	cin >> n >> s;
	for (LL i = 1; i <= min(n, 100000LL); ++i) {
		if (check(i)) {
			++ans;
		}
	}
	
	if (n > 100000) {
		for (LL i = max(100001LL, s); i <= min(n, s + 100000); ++i) {
			if (check(i)) {
				++ans;
			}
		}
		if (n > s + 100000) ans += n - (s + 100000);
	}
	cout << ans << endl;
}