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

template<class num> inline void read(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

const int N = 2e5+7;
const int M = 1e5;

int n;
ll r;
ll is[N], it[N];
ll s, i, t, fr;
vector<ll> prn;

void nope () {
	printf("-1\n");
	exit(0);
}

int main() {
	scanf("%d %lld", &n, &r);
	
	for (int j = 0; j < n; j++)
		scanf("%lld", &is[j]);
	for (int j = 0; j < n; j++)
		scanf("%lld", &it[j]);

	ll res = 0;

	i = 0;
	s = is[i];
	t = it[i];
	fr = 0;
	
	ll ts = 0;

	while (i < n) {
		ll v = min(fr, s);
		fr -= v;
		s -= v;
		t -= v;
		ts += v;

		if (s == 0) {
			i++;
			s = is[i];
			t = it[i];
		} else {
			ll d = min(s, t-s);
			
			if (d < 0) nope();
			if (d == 0) {
				if (res > M+7) {
					ll q = (s+r-1)/r;
					fr += q*r;
					res += q;
				} else {
					res++;
					prn.push_back(ts);
					fr += r;
				}
			} else {
				s -= d;
				t -= d+d;
				ts += d+d;
			}
		}
	}

	printf("%lld\n", res);
	if (res <= M) {
		for (ll i : prn)
			printf("%lld ", i);
		printf("\n");
	}
}