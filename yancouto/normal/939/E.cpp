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

const int N = 512345;
ll a[N], acc[N];


int main() {
	int q;
	rd(q);
	int n = 0;
	while(q--) {
		int t;
		rd(t);
		if(t == 1) {
			rd(a[n]);
			acc[n] = a[n] + (n? acc[n - 1] : 0);
			n++;
		} else {
			if(n == 1) { puts("0"); continue; }
			int l = 0, r = n - 1;
			while(l < r) {
				int m = (l + r + 1) / 2;
				ll sum = acc[m] + a[n - 1];
				if(a[m] * ll(m + 2) <= sum) l = m;
				else r = m - 1;
			}
			printf("%.10f\n", a[n - 1] - double(acc[l] + a[n - 1]) / double(l + 2));
		}
	}
}