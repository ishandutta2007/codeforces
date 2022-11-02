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
#define pf push_front

int main() {
	int i, n;
	scanf("%d", &n);
	deque<int> dp, di;
	dp.pb(0);
	for(i = 2; i < n; i += 2)
		dp.pb(i), dp.pf(i);
	for(i = 1; i < n; i += 2)
		di.pb(i), di.pf(i);
	di.pb(0);
	di.insert(di.end(), dp.begin(), dp.end());
	for(i = 0; i < 2*n; i++)
		printf("%d ", n - di[i]);
	putchar('\n');
}