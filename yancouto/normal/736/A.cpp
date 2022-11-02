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

ll n;

int main() {
	int i, j;
	scanf("%lld", &n);
	if(n == 2) { puts("1"); return 0; }
	if(n == 3) { puts("2"); return 0; }
	ll p2 = 1, p1 = 2;
	int ct = 1;
	while(true) {
		ct++;
		ll x = p1 + p2;
		p2 = p1;
		p1 = x;
		if(x > n) { printf("%d\n", ct - 1); return 0; }
	}
}