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

int gcd(int a, int b) {
	if(!b) return a;
	return gcd(b, a % b);
}

int a[11234];

int main() {
	int i, j;
	rd(n);
	int g = 0;
	int ct1 = 0;
	for(i = 0; i < n; i++) { rd(a[i]); g = gcd(g, a[i]); ct1 += (a[i] == 1); }
	if(g != 1) { puts("-1"); return 0; }
	if(ct1) { printf("%d\n", n - ct1); return 0; }
	int mn = INT_MAX;
	for(int i = 0; i < n; i++) {
		int g = a[i];
		for(int j = i + 1; j < n; j++) {
			g = gcd(g, a[j]);
			if(g == 1) {
				mn = min(mn, (j - i) + n - 1);
				break;
			}
		}
	}
	printf("%d\n", mn);
}