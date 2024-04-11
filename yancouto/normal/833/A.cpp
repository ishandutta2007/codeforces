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

int n;

const int N = sqrt(1.01e9) + 1;
int cp[N];

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

int main() {
	int i, j;
	vector<ll> ps;
	for(i = 2; i < N; i++)
		if(!cp[i]) {
			ps.pb(i);
			for(j = i; j < N; j += i)
				cp[i] = 1;
		}
	rd(n);
	while(n--) {
		ll a, b;
		rd(a); rd(b);
		ll ab = a * b;
		ll l = 0, r = 1000001;
		while(l < r) {
			ll m = (l + r) / 2;
			if(m * m * m >= ab) r = m;
			else l = m + 1;
		}
		bool bad = false;
		if(l * l * l != ab || (a % l) || (b % l)) bad = true;
		if(bad) puts("No");
		else puts("Yes");
	}
}