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

int p[109];

int main() {
	int i, j, g, n, m, k, x;
	scanf("%d %d %d", &n, &m, &k);
	for(i = 1; i <= k; i++) {
		scanf("%d", &x);
		p[x] = i;
	}
	int tot = 0;
	for(i = 0; i < n; i++)
		for(j = 0; j < m; j++) {
			scanf("%d", &x);
			tot += p[x];
			for(g = 1; g <= k; g++)
				if(p[g] < p[x])
					p[g]++;
			p[x] = 1;
		}
	printf("%d\n", tot);
}