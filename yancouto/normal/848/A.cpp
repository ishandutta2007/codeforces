#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n;

ll dp[112345];

int main() {
	ll i, j;
	dp[1] = 0;
	//for(ll i = 2; i <= 100000; i++) {
	//	dp[i] = LLONG_MAX;
	//	for(ll j = 1; j < i; j++)
	//		dp[i] = min(dp[i], j * (i - j) + dp[j] + dp[i - j]);
	//	//printf("dp[%d] = %d\n", i, dp[i]);
	//	ll m = (i / 2);
	//	ll g = m * (i - m) + dp[m] + dp[i - m];
	//	if(g != dp[i]) printf("%d: %lld vs %lld\n", i, g, dp[i]);
	//	assert(g == dp[i]);
	//	assert(dp[i] == (i * (i - 1)) / 2);
	//}
	ll k;
	rd(k);
	putchar('a');
	int ct = 1;
	while(k > 0) {
		for(i = 1; i * (i - 1) / 2 <= k; i++);
		i--;
		k -= (i * (i - 1)) / 2;
		while(i--) putchar('a' + ct);
		ct++;
	}
	putchar('\n');
}