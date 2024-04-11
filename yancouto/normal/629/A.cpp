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

char g[200][200];
int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			scanf(" %c", &g[i][j]);
	int tot = 0;
	for(i = 0; i < n; i++) {
		int ct = 0;
		for(j = 0; j < n; j++)
			ct += (g[j][i] == 'C');
		tot += (ct * (ct - 1)) / 2;
	}
	for(i = 0; i < n; i++) {
		int ct = 0;
		for(j = 0; j < n; j++)
			ct += (g[i][j] == 'C');
		tot += (ct * (ct - 1)) / 2;
	}
	printf("%d\n", tot);
}