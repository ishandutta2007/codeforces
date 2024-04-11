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
	int i, j, n;
	scanf("%d", &n);
	int mx = (n / 7) * 2 + min(n % 7, 2);
	int mn = (n / 7) * 2 + max((n % 7) - 5, 0);
	printf("%d %d\n", mn, mx);
}