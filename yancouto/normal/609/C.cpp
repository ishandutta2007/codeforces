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

int a[100009];
int main() {
	int i, n;
	scanf("%d", &n);
	ll tot = 0;
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		tot += a[i];
	}
	sort(a, a + n);
	reverse(a, a + n);
	ll all = 0;
	for(i = 0; i < (tot % n); i++)
		if(a[i] > (tot / n) + 1)
			all += a[i] - ((tot / n) + 1);
	for(i = (tot % n); i < n; i++)
		if(a[i] > (tot / n))
			all += a[i] - (tot / n);
	printf("%I64d\n", all);
}