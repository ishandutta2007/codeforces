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
	ll n;
	scanf("%I64d", &n); n--;
	ll l = 0, r = 100000000;
	while(l < r) {
		ll m = (l + r + 1) / 2;
		if((m * (m + 1)) / 2 <= n) l = m;
		else r = m - 1;
	}
	printf("%I64d\n", (n - (l * (l + 1)) / 2) + 1);
}