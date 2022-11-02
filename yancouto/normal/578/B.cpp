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
ll a[200009], b[200009], c[200009];
ll x;
int main() {
	int i, n, k;
	scanf("%d %d %I64d", &n, &k, &x);
	for(i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	b[0] = a[0];
	for(i = 1; i < n; i++)
		b[i] |= b[i - 1] | a[i];
	for(i = n - 1; i >= 0; i--)
		c[i] |= c[i + 1] | a[i];
	ll y = x;
	for(i = 1; i < k; i++)
		x *= y;
	ll mx = (a[0] * x) | c[1];
	for(i = 1; i < n; i++)
		mx = max(mx, b[i - 1] | (a[i] * x) | c[i + 1]);
	printf("%I64d\n", mx);
}