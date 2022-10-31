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
const int N = 212345;

ll ba[N], bb[N];
ll get(ll bit[], int i) {
	ll sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}
inline ll get(ll bit[], int i, int j) { return get(bit, j) - get(bit, i - 1); }

ll add(ll bit[], int i, ll val) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += val;
}

int main() {
	int i, n, k, a, b, q, op, d, o;
	scanf("%d %d %d %d %d", &n, &k, &a, &b, &q);
	for(i = 0; i < q; i++) {
		scanf("%d %d", &op, &d);
		if(op == 1) {
			scanf("%d", &o);
			add(ba, d, o);
			int g = get(ba, d, d);
			if(g > a) add(ba, d, a - g);
			add(bb, d, o);
			g = get(bb, d, d);
			if(g > b) add(bb, d, b - g);
		} else {
			ll tot = get(bb, 0, d - 1) + get(ba, d + k, 200001);
			printf("%I64d\n", tot);
		}
	}
}