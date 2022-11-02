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
const int N = 100009;
int x[N], y[N], p[N];
double val[N];
ll cross(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - y1 * x2;
}

ll cross(int a, int b, int c) {
	return cross(x[b] - x[a], y[b] - y[a], x[c] - x[a], y[c] - y[a]);
}
inline ll sq(ll x) { return x * x; }

int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x[i], &y[i]), p[i] = i;
		val[i] = atan2(y[i], x[i]);
	}
	sort(p, p + n, [](int i, int j) {
		if(cross(x[i], y[i], x[j], y[j])) return val[i] < val[j];
		return sq(x[i]) + sq(y[i]) < sq(x[j]) + sq(y[j]);
	});
	for(i = 0; i < n - 2; i++)
		if(cross(p[i], p[i + 1], p[i + 2])) {
			printf("%d %d %d\n", p[i] + 1, p[i + 1] + 1, p[i + 2] + 1);
			return 0;
		}
}