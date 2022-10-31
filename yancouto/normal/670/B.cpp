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

int a[112345];
int main() {
	int i, j, n, k;
	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	for(i = 1; ; i++) {
		if(k > i) k -= i;
		else { printf("%d\n", a[k - 1]); break; }
	}
}