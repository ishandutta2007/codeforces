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
const int N = 2000009;

ll ct[N], sum[N];

inline ll count(int l, int r) {
	if(r < l) return 0;
	return ct[r] - (l? ct[l - 1] : 0);
}

inline ll gsum(int l, int r) {
	if(r < l) return 0;
	return sum[r] - (l? sum[l - 1] : 0);
}

int cp[N];

int main() {
	int i, j;
	ll x, y;
	rd(n); rd(x); rd(y);
	for(i = 0; i < n; i++) {
		ll a;
		rd(a);
		ct[a]++;
		sum[a] += a;
	}
	for(i = 1; i < N; i++)
		ct[i] += ct[i - 1],
		sum[i] += sum[i - 1];
	ll mn = LLONG_MAX;
	ll k = (x / y) + 1;
	for(i = 2; i <= 1000000; i++) {
		if(cp[i] == 1) continue;
		//printf("at i %d\n", i);
		ll tot = 0;
		for(j = i; j < N; j += i) {
			cp[j] = 1;
			//printf("till %d\n", j);
			//printf("tot += (count(%d, %d) = %d) * %d\n", j - i + 1, j - k, count(j - i + 1, j - k), x);
			tot += count(j - i + 1, j - k) * x;
			//printf("tot += %d * (%d * %d - %d)\n", y, count(j - k + 1, j - 1), j, gsum(j - k + 1, j - 1));
			if(k > 1) tot += ll(count(max<ll>(j - i + 1, j - k + 1), j - 1) * ll(j) - gsum(max<ll>(j - i + 1, j - k + 1), j - 1)) * y;
		}
		//printf(">>>>>got %d\n", tot);
		mn = min(mn, tot);
	}
	printf("%lld\n", mn);
}