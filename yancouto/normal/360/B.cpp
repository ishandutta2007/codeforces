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

int memo[2002], a[2002];
int diff, n;
int solve(int i) {
	if(i >= n) return 0;
	int &r = memo[i];
	if(r != -1) return r;
	r = INT_MAX;
	if(!i || abs(a[i] - a[i - 1]) <= diff) r = solve(i + 1);
	for(int j = i; j < n; j++) {
		if(i == 0 || j == n - 1) r = min(r, (j - i + 1) + solve(j + 2));
		else if((abs(a[j + 1] - a[i - 1]) + j - i + 1) / (j - i + 2) <= diff) r = min(r, (j - i + 1) + solve(j + 2));
	}
	return r;
}

int main() {
	int k, i;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	diff = 1;
	ll l = 0, r = INT_MAX;
	while(l < r) {
		ll m = (l + r) / 2;
		memset(memo, -1, sizeof memo);
		diff = int(m);
		if(solve(0) <= k) r = m;
		else l = m + 1;
	}
	printf("%d\n", int(l));
}