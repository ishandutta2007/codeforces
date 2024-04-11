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
ll a[N], b[N];

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]);
	for(i = 0; i < n - 1; i++) b[i] = abs(a[i + 1] - a[i]);
	ll mx = 0; ll cur = 0;
	for(i = n - 2; i >= 0; i -= 2) {
		cur -= b[i + 1];
		if(cur < 0) cur = 0;
		mx = max(mx, cur);
		cur += b[i];
		if(cur < 0) cur = 0;
		mx = max(mx, cur);
	}
	cur = 0;
	for(i = n - 3; i >= 0; i -= 2) {
		cur -= b[i + 1];
		if(cur < 0) cur = 0;
		mx = max(mx, cur);
		cur += b[i];
		if(cur < 0) cur = 0;
		mx = max(mx, cur);
	}
	printf("%lld\n", mx);
}