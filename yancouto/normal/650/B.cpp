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
const int N = 500009;
char s[N];
ll r[N], l[N], c[N];

int main() {
	int i, n, a, b;
	ll T;
	scanf("%d %d %d %I64d", &n, &a, &b, &T);
	scanf("%s", s);
	for(i = 0; i < n; i++)
		c[i] = 1 + (s[i] == 'w') * b;
	int mx = 0;
	for(i = 0; i < n; i++) {
		r[i] = c[i];
		if(i > 0) r[i] += a + r[i - 1];
		if(r[i] <= T) mx = i + 1;
	}
	for(i = n - 1; i > 0; i--) {
		l[i] = c[i] + a;
		if(i < n - 1) l[i] += l[i + 1];
	}
	int j = 1;
	for(i = 0; i < n; i++) {
		ll cur = r[i] + ll(i) * ll(a);
		if(cur > T) break;
		for(j = max(j, i + 1); j < n && cur + l[j] > T; j++);
		mx = max(mx, i + 1 + (n - j));
	}
	j = n - 1;
	for(i = n - 1; i > 0; i--) {
		ll cur = l[i] + c[0] + ll(n - i) * ll(a);
		if(cur > T) break;
		for(j = min(j, i - 1); j > 0 && cur + r[j] - c[0] > T; j--);
		mx = max(mx, (n - i + 1) + j);
	}
	printf("%d\n", mx);
}