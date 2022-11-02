#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
char str[200];
int n; 
ll memo[30][2][302];
ll solve(int dig, bool pre, int sum) {
	if(dig == n) return sum;
	ll &r = memo[dig][pre][sum];
	if(r != -1) return r;
	r = 0;
	for(int i = 0; i <= 9; i++) {
		if(pre && i > (str[dig] - '0')) break;
		r += solve(dig + 1, pre && (i == (str[dig] - '0')), sum + i);
	}
	return r;
}

int f(ll x) {
	int s = 0;
	while(x) {
		s += x % 10;
		x /= 10;
	}
	return s;
}

int main() {
	scanf("%I64d", &a);

	ll l = 1, r = 100000000000000000ll;
	ll s;
	while(l < r) {
		ll m = (l + r) / 2;
		sprintf(str, "%I64d", m); n = strlen(str);
		memset(memo, -1, sizeof memo);
		s = solve(0, true, 0);
		assert(s > 0);
		if(s >= a) r = m;
		else l = m + 1;
	}
	sprintf(str, "%I64d", l); n = strlen(str);
	memset(memo, -1, sizeof memo);
	s = solve(0, true, 0) % a;
	l = 1;
	while(s) {
		if(s > 0) s -= f(l++);
		else s += f(++r);
	}
	printf("%I64d %I64d\n", l, r);
	return 0;
}