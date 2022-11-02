#include <bits/stdc++.h>
using namespace std;
#define y1 first
#define y2 second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

pii p[100009];
int main() {
	int i, n; ll x1, x2, k, b;
	scanf("%d", &n);
	scanf("%I64d %I64d", &x1, &x2);

	for(i = 0; i < n; i++) {
		scanf("%I64d %I64d", &k, &b);
		p[i] = pii(k * x1 + b, k * x2 + b);
	}
	sort(p, p + n);
	for(i = 0; i < n - 1; i++)
		if(p[i + 1].y2 < p[i].y2) {
			puts("YES");
			return 0;
		}
	puts("NO");
}