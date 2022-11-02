#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

map<ll, ll> mp[3];
ll a[200009];
int main() {
	int i, j, n;
	ll k;
	scanf("%d %I64d", &n, &k);
	for(i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for(i = n - 1; i >= 0; i--) {
		for(j = 2; j > 0; j--)
			mp[j][a[i]] += mp[j - 1][k * a[i]];
		mp[0][a[i]]++;
	}
	ll tot = 0;
	for(auto &e : mp[2])
		tot += e.snd;
	printf("%I64d\n", tot);
}