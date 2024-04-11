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
ll k;
const int N = 212345;
ll a[N];
map<ll, int> mp;

ll go(ll al) {
	ll p = 1;
	ll tot = 0;
	while(abs<ll>(p) <= 1e15) {
		tot += mp[al + p];
		p *= k;
		if(k == 1) return tot;
		if(k == -1 && p == 1) return tot;
	}
	return tot;
}

int main() {
	int i, j;
	rd(n); rd(k);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = 1; i < n; i++) a[i] += a[i - 1];
	for(i = 0; i < n; i++) mp[a[i]]++;
	ll tot = 0;
	tot += go(0);
	for(i = 0; i < n; i++) {
		mp[a[i]]--;
		tot += go(a[i]);
	}
	printf("%lld\n", tot);
}