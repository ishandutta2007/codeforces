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
const int N = 112345;
int a[N], f[N]; ll dp[N];

int main() {
	int i, j, n;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		f[a[i]]++;
	}
	for(i = 100000; i >= 0; i--)
		dp[i] = max(dp[i + 2] + ll(i)*ll(f[i]), dp[i + 1]);
	printf("%lld\n", dp[0]);
}