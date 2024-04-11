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
const int N = 1123456;
ll s1[N], e1[N], v1[N], s2[N], e2[N], v2[N];
int a[N];

ll all(int i) {
	return mod((e1[i] - s1[i] + 1ll) * v1[i] + (e2[i] - s2[i] + 1ll) * v2[i]);
}

ll inter(ll s, ll e, ll v, ll r) {
	if(s > e || s < 2 || r < s) return 0;
	return mod(v * ll(min(r, e) - s + 1ll));
}

int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
	s1[n - 1] = 2; e1[n - 1] = a[n-1]; v1[n-1] = 1;
	s2[n - 1] = 0; e2[n - 1] = -1; v2[n-1] = 0;
	for(i = n - 2; i >= 0; i--) {
		if(a[i] >= a[i + 1]) {
			s1[i] = a[i + 1] + 1; e1[i] = a[i]; v1[i] = 1;
			s2[i] = 2; e2[i] = a[i + 1]; v2[i] = mod(all(i + 1) + 1ll);
		} else {
			s1[i] = 2; e1[i] = a[i];
			v1[i] = inter(s1[i+1], e1[i+1], v1[i+1], a[i]) + inter(s2[i+1], e2[i+1], v2[i+1], a[i]);
			v1[i] = mod(v1[i] + 1ll);
			s2[i] = 0; e2[i] = -1; v2[i] = 0;
		}
	}
	ll tot = 0;
	for(i = 0; i < n; i++)
		tot += all(i);
	printf("%d\n", (int) mod(tot));
}