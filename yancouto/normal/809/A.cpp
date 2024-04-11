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

ll x[312345];

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(x[i]);
	sort(x, x + n);
	ll r = 0, r2 = 0, tot = 0;
	for(i = n - 1; i >= 0; i--) {
		tot = mod(tot + r - mod(r2 * x[i]) + modn);
		r2 = mod(2 * r2 + 1);
		r = mod(2 * r + x[i]);
	}
	printf("%lld\n", tot);
}