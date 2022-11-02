#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int p(int n) {
	if(n < 7) return 1;
	return p(n / 7) + 1;
}

int a[100], n, m, pn, pm, sn;
bool ok() {
	int N = 0, M = 0;
	for(int i = 0; i < pn; i++)
		N = 7 * N + a[i];
	for(int i = pn; i < pn + pm; i++)
		M = 7 * M + a[i];
	return N < n && M < m;
}

int main() {
	int i, j;
	scanf("%d %d", &n, &m);
	pn = p(n-1), pm = p(m - 1);
	if(pn + pm > 7) { puts("0"); return 0; }
	int tot = 0;
	for(i = 0; i < (1 << 7); i++) {
		if(__builtin_popcount(i) != pn + pm) continue;
		sn = 0;
		for(j = 0; j < 7; j++)
			if((i >> j) & 1)
				a[sn++] = j;
		do {
			if(ok()) tot++;
		} while(next_permutation(a, a + pn + pm));
	}
	printf("%d\n", tot);
}