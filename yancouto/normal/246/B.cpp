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

int main() {
	int i, j, n, x;
	scanf("%d", &n);
	int tot = 0;
	for(i = 0; i < n; i++) scanf("%d", &x), tot += x;
	if(tot % n) printf("%d\n", n-1);
	else printf("%d\n", n);
}