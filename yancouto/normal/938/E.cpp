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

const int N = 1123456;
ll fat[N], ifat[N], a[N];

ll choose(int n, int x) {
	return mod(fat[n] * mod(ifat[x] * ifat[n - x]));
}

inline ll fexp(ll x, ll p) {
	ll r = 1;
	for(; p; p >>= 1, x = mod(x * x))
		if(p & 1)
			r = mod(r * x);
	return r;
}

int main() {
	int i, j;
	fat[0] = 1;
	for(i = 1; i < N; i++)
		fat[i] = mod(fat[i - 1] * ll(i));
	ifat[N - 1] = fexp(fat[N - 1], modn - 2);
	for(i = N - 2; i >= 0; i--)
		ifat[i] = mod(ifat[i + 1] * ll(i + 1));
	rd(n);
	for(i = 0; i < n; i++)
		rd(a[i]);
	sort(a, a + n);
	int lst = -1;
	ll ans = 0;
	for(i = 0; i < n; i++) {
		if(i && a[i - 1] < a[i])
			lst = i - 1;
		ll x = lst + 1;
		//printf("x %lld\n", x);
		ans = mod(ans + mod(a[i] * mod(mod(fat[x] * fat[n - x - 1]) * choose(n, x))));
	}
	ans = mod(ans - mod(a[n - 1] * fat[n]) + modn);
	printf("%lld\n", ans);
}