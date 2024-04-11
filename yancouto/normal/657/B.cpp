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
const int N = 512345;
ll a[N];
int p[N];

int main() {
	int i, n, k, j;
	scanf("%d %d", &n, &k);
	for(i = 0; i <= n; i++) {
		scanf("%d", &p[i]);
		a[i] += p[i];
	}
	for(i = 0; i < N ; i++) {
		if(i >= n && (a[i] == 0 || a[i] == 1 || a[i] == -1)) break;
		if(a[i] >= 0) {
			a[i + 1] += (a[i] >> 1);
			a[i] &= 1ll;
		} else {
			a[i] = -a[i];
			a[i + 1] -= (a[i] >> 1);
			a[i] &= 1ll;
			if(a[i]) a[i + 1]--;
		}
	}
	int sz = i;
	while(a[sz] == 0) sz--;
	bool neg = false;
	if(a[sz] == -1) {
		neg = true;
		a[sz] = 1;
		for(j = 0; !a[j]; j++);
		for(i = sz; i > j; i--)
			a[i] = !a[i];
		sz += 3;
		while(a[sz] == 0) sz--;
	}
	assert(a[sz] == 1);
	ll ans = 0;
	for(i = 0; a[i] == 0; i++);
	if(sz - i > 39) { puts("0"); return 0; }
	for(j = i; j <= sz; j++)
		ans = ans + (a[j] << ll(j - i));
	if(neg) ans = -ans;
	int tot = 0;
	for(j = i; j >= 0 && abs(ans) <= 10000000000ll; j--) {
		ll v = ll(p[j]) - ans;
		if(j < n && abs(v) <= ll(k)) tot++;
		if(j == n && abs(v) <= ll(k) && v) tot++;
		ans *= 2ll;
	}
	printf("%d\n", tot);
}