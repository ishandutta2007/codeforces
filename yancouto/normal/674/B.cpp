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
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

int main() {
	int i, j, n, k, a, b, c, d;
	scanf("%d %d", &n, &k);
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(n == 4 || k <= n) { puts("-1"); return 0; }
	printf("%d %d", a, c);
	for(i = 1; i <= n; i++)
		if(i != a && i != b && i != c && i != d)
			printf(" %d", i);
	printf(" %d %d\n", d, b);
	printf("%d %d", c, a);
	for(i = 1; i <= n; i++)
		if(i != a && i != b && i != c && i != d)
			printf(" %d", i);
	printf(" %d %d\n", b, d);
}