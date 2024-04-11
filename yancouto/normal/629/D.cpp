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
const int N = 100009;

ll r[N], h[N]; int p[N];
inline ll vol(int i) { return r[i] * r[i] * h[i]; }

bool less_(int i, int j) {
	if(vol(i) == vol(j)) return i > j;
	return vol(i) < vol(j);
}

ll bit[N];
ll add(int i, ll v) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] = max(bit[i], v);
}
ll get(int i) {
	ll v = LLONG_MIN;
	for(i += 2; i; i -= (i & -i))
		v = max(v, bit[i]);
	return v;
}

const double pi = acos(-1);
int p2[N];
int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%I64d %I64d", &r[i], &h[i]), p[i] = i;
	sort(p, p + n, less_);
	for(i = 0; i < n; i++)
		p2[p[i]] = i;
	ll ans = LLONG_MIN;
	for(i = 0; i < n; i++) {
		ll dp = vol(i) + get(p2[i]);
		add(p2[i], dp);
		ans = max(ans, dp);
	}
	printf("%.10f\n", pi * ans);
}