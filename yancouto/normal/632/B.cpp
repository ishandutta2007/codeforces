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

ll p[512345];
char s[512345];

int main() {
	int i;
	rd(n);
	for(i = 0; i < n; i++) rd(p[i]);
	scanf(" %s", s);
	ll tot = 0, best;
	for(i = 0; i < n; i++)
		if(s[i] == 'B')
			tot += p[i];
	ll bk = tot;
	best = tot;
	for(i = 0; i < n; i++) {
		if(s[i] == 'A') tot += p[i];
		else tot -= p[i];
		best = max(best, tot);
	}
	tot = bk;
	for(i = n - 1; i >= 0; i--) {
		if(s[i] == 'A') tot += p[i];
		else tot -= p[i];
		best = max(best, tot);
	}
	printf("%lld\n", best);
}