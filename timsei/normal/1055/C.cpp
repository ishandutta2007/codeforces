#include <bits/stdc++.h>
using namespace std;

#define int long long

int ta, la, ra, tb, lb, rb, g;

int gcd(int x, int y) {
	return (!y) ? x : gcd(y, x % y);
}

int get(int a, int b, int c, int d) {
	a = max(a, c);
	b = min(b, d);
	if(a > b) return 0;
	return b - a + 1;
}

int getans(int x) {
	int L = x, R = ra - la + x;
	return get(L, R, lb, rb) + (!!(ta % tb != 0)) * get(L, R, lb + tb, rb + tb);
}

int solve(int x) {
	return max(max(getans((x - la) / g * g + la), getans((x - la + g) / g * g + la)), getans((x - la - g) / g * g + la));
}


main() {
	cin >> la >> ra >> ta;
	cin >> lb >> rb >> tb;
	if((ra - la) > (rb - lb)) {
		swap(la, lb);
		swap(ra, rb);
		swap(ta, tb);
	}
	g = gcd(ta, tb);
	// [lb, rb], [lb + tb, rb + tb]
	int ans = 0;
	ans = max(ans, solve(lb));
	ans = max(ans, solve(rb));
	ans = max(ans, solve(lb + tb));
	ans = max(ans, solve(rb + tb));
	ans = max(ans, solve(lb - (ra - la)));
	ans = max(ans, solve(rb - (ra - la)));
	ans = max(ans, solve(lb + tb - (ra - la)));
	ans = max(ans, solve(rb + tb - (ra - la)));
	cout << ans << endl;
}