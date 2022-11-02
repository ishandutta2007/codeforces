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
	int n, b, p;
	scanf("%d %d %d", &n, &b, &p);
	int t2 = p * n;
	int t1 = 0;
	while(n > 1) {
		int p2 = 1 << (31 - __builtin_clz(n));
		t1 += p2 * b + (p2 / 2);
		n = n - p2 + (p2 / 2);
	}
	printf("%d %d\n", t1, t2);
}