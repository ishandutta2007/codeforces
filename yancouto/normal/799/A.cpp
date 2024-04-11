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

int main() {
	int i, j;
	int n, t, k, d;
	rd(n); rd(t); rd(k); rd(d);
	int nr = ((n + k - 1) / k) * t;
	if(n <= k) { puts("NO"); return 0; }
	int ct = 0;
	while(n >= 0) {
		n -= k;
		ct += t;
		if(n > 0 && ct >= d) {
			if(ct == d && n > k) { puts("YES"); return 0; }
			else if(ct > d) { puts("YES"); return 0; }
			break;
		}
	}
	puts("NO");

}