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

int a[100009], b[100009];
int main() {
	int i, n, k;
	scanf("%d %d", &n, &k);
	int tot = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		tot += a[i] / 10;
		b[i] = ((a[i] + 9) / 10) * 10 - a[i];
	}
	sort(b, b + n);
	for(i = 0; i < n; i++)
		if(b[i] && k >= b[i]) {
			k -= b[i];
			tot++;
		}
	tot += k / 10;
	printf("%d\n", min(tot, 10 * n));
}