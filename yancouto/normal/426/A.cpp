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

int a[112];
int main() {
	int i, j, n, s;
	scanf("%d %d", &n, &s);
	for(i = 0; i < n; i++) scanf("%d", &a[i]);
	if(accumulate(a, a + n, 0) - *max_element(a, a + n) <= s) puts("YES");
	else puts("NO");
}