#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;

char s[N];
int ct[256];

int n, T, k;

long long calc(long long n) {
	if(n <= 4) return n;
	long long l = 0, r = 1e9, res = -1;
	while(l <= r) {
		long long mid = (l + r) >> 1;
		if(mid * mid <= n) {
			l = mid + 1; res = mid;
		} else r = mid - 1;
	}
	long long ans = res;
	long long a = ans - 1;
	long long b = a;
	for(; (a + 1) * (a + 2) <= n; ++ a);
	for(; (b + 1) * (b + 3) <= n; ++ b);
	return ans + a + b;
}

int main() {
	for(cin >> T; T --;) {
		long long l, r, ans;
		cin >> l >> r;
		cout << calc(r) - calc(l - 1) << endl;
	}
}