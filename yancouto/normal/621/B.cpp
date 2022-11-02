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

bool g[1002][1002];
int main() {
	int i, j, n, x, y;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d %d", &x, &y); x--; y--;
		g[x][y] = 1;
	}
	ll tot = 0;
	for(i = 0; i <= 2000; i++) {
		ll b = 0;
		for(j = 0; j < 1000; j++)
			if(i - j >= 0 && i - j < 1000 && g[i - j][j])
				b++;
		tot += (b * (b - 1)) / 2;
	}
	for(i = -1000; i <= 1000; i++) {
		ll b = 0;
		for(j = 0; j < 1000; j++)
			if(i + j >= 0 && i + j < 1000 && g[i + j][j])
				b++;
		tot += (b * (b - 1)) / 2;
	}
	printf("%I64d\n", tot);
}