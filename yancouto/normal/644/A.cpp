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

int g[200][200];

int main() {
	int i, j, n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	int mx = ((a + 1) / 2) * ((b + 1) / 2) + (a / 2) * (b / 2);
	int mn = a * b - mx;
	if(((n + 1) / 2) > mx || (n / 2) > mn) { puts("-1"); return 0; }
	int p = 1;
	for(i = 0; i < a && p <= n; i++)
		for(j = (i & 1); j < b && p <= n; j += 2)
			g[i][j] = p, p += 2;
	p = 2;
	for(i = 0; i < a && p <= n; i++)
		for(j = !(i & 1); j < b && p <= n; j += 2)
			g[i][j] = p, p += 2;
	for(i = 0; i < a; i++) {
		for(j = 0; j < b; j++)
			printf("%d ", g[i][j]);
		putchar('\n');
	}
}