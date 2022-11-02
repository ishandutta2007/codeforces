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
#	define debug(args...) ((void) 0)
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

const int N = 112345;
ll a[N];

int main() {
	int i, j;
	ll x, k;
	rd(n); rd(x); rd(k);
	for(i = 0; i < n; i++) rd(a[i]);
	sort(a, a + n);
	map<ll, ll> mp;
	ll tot = 0;
	for(i = n - 1; i >= 0;) {
		for(j = i; j >= 0 && a[j] == a[i]; j--)
			tot += mp[k + int((a[i] - 1) / x)];
		for(j = i; j >= 0 && a[j] == a[i]; j--)
			mp[int(a[i] / x)]++;
		ll ct = i - j;
		if((k == 0 && (a[i] % x)) || (k == 1 && !(a[i] % x)))
			tot += ct * ct;
		i = j;
	}
	printf("%lld\n", tot);
}