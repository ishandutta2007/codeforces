#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int m, d;
char s[2009];
ll memo[2009][2][2009];
ll solve(int i, bool pre, int k) {
	if(!s[i]) return k == 0;
	ll &r = memo[i][pre][k];
	if(r != -1) return r;
	r = 0;
	if(i & 1) {
		if(!pre || s[i] - '0' >= d)
			r = solve(i + 1, pre && s[i] - '0' == d, (k * 10 + d) % m);
	}
	else
		for(int d = !i; d <= 9; d++) {
			if(pre && s[i] - '0' < d) break;
			if(d == ::d) continue;
			r += solve(i + 1, pre && s[i] - '0' == d, (k * 10 + d) % m);
		}
	return r = mod(r);
}


bool val() {
	int k = 0;
	for(int i = 0; s[i]; i++) {
		k = (k * 10 + s[i] - '0') % m;
		if((i & 1) && s[i] != d + '0')
			return false;
		if(!(i & 1) && s[i] == d + '0')
			return false;
	}
	return k == 0;
}

int main() {
	scanf("%d %d", &m, &d);
	scanf("%s", s);
	memset(memo, -1, sizeof memo);
	ll tot = solve(0, true, 0);
	if(val()) tot--;
	scanf("%s", s);
	memset(memo, -1, sizeof memo);
	tot = mod(solve(0, true, 0) - tot + 2ll*modn);
	printf("%I64d\n", tot);
}