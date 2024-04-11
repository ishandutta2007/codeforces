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

int cr(int x1, int y1, int x2, int y2) {
	return x1 * y2 - y1 * x2;
}

int x[11234], y[11234];

int cross(int i, int j, int k) {
	return cr(x[j] - x[i], y[j] - y[i], x[k] - x[i], y[k] - y[i]);
}

int main() {
	int i, n;
	scanf("%d", &n);
	for(i = 0; i <= n; i++)
		scanf("%d %d", &x[i], &y[i]);
	int tot = 0;
	for(i = 0; i < n - 1; i++)
		if(cross(i, i + 1, i + 2) > 0)
			tot++;
	printf("%d\n", tot);
}