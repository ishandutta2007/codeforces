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

int main() {
	int i, j, n, x, y;
	scanf("%d", &n);
	map<int, ll> sx, sy;
	map<pii, ll> eq;
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x, &y);
		sx[x]++;
		sy[y]++;
		eq[pii(x, y)]++;
	}
	ll tot = 0;
	for(auto p : sx)
		tot += (p.snd * (p.snd - 1ll)) / 2ll;
	for(auto p : sy)
		tot += (p.snd * (p.snd - 1ll)) / 2ll;
	for(auto p : eq)
		tot -= (p.snd * (p.snd - 1ll)) / 2ll;
	printf("%I64d\n", tot);
}