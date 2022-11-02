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
const int N = 1000009;
int a[N], t[N];

int gcd(int a, int b) {
	if(b == 0) return a;
	return gcd(b, a % b);
}

int A, B, n;
ll memo[N][2][2];
ll solve(int i, bool on, bool fst) {
	if(i == n) return (fst && on)? 100000000000000000ll : 0ll;
	if(!on && t[i] == 2) return 100000000000000000ll;
	ll &r = memo[i][on][fst];
	if(r != -1) return r;
	if(on) r = min(solve(i, false, fst), solve(i + 1, true, fst) + A);
	else r = solve(i + 1, false, fst) + (t[i] == 1? B : 0ll);
	return r;
}

void add_ps(set<int> &p, int x) {
	for(int i = 2; i * i <= x; i++) {
		if(!(x % i)) p.insert(i);
		while(!(x % i)) x /= i;
	}
	if(x > 1) p.insert(x);
}

int main() {
	int i;
	scanf("%d %d %d", &n, &A, &B);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	set<int> p;
	for(i = -1; i <= 1; i++)
		add_ps(p, a[0] + i),
		add_ps(p, a[n - 1] + i);
	ll ans = LLONG_MAX;
	for(int x : p) {
		for(i = 0; i < n; i++)
			if((a[i] % x) == 0) t[i] = 0;
			else if(!((a[i] + 1) % x) || !((a[i] - 1) % x)) t[i] = 1;
			else t[i] = 2;
		memset(memo, -1, sizeof memo);
		ll cur = 0;
		for(i = 0; i < n; i++) {
			ans = min(ans, cur + solve(i, true, !i));
			if(t[i] == 1) cur += B;
			else if(t[i] == 2) break;
		}
	}
	printf("%I64d\n", ans);
}