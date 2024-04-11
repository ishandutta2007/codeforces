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
const int N = 112345;
ll a[N];

void ok() {
	puts("YES");
	exit(0);
}

int main() {
	int i, j;
	rd(n);
	multiset<ll> L, R;
	for(i = 0; i < n; i++) rd(a[i]), R.insert(a[i]);
	ll all = accumulate(a, a + n, 0ll);
	ll cur = 0;
	if(((all - 2 * cur) & 1) == 0 && R.count((all - 2 * cur) / 2) > 0) ok();
	for(i = 0; i < n; i++) {
		R.erase(R.find(a[i]));
		L.insert(a[i]);
		cur += a[i];
		if(cur == all - cur) ok();
		if(cur > all - cur) {
			if(((cur - (all - cur)) & 1) == 0 && L.count((cur - (all - cur)) / 2) > 0) ok();
		} else {
			if(((all - 2 * cur) & 1) == 0 && R.count((all - 2 * cur) / 2) > 0) ok();
		}
	}
	puts("NO");
}