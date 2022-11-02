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
int h[N], qt[N];

int main() {
	int i;
	rd(n);
	qt[0] = 1;
	for(i = 2; i <= n; i++) {
		int p;
		rd(p);
		h[i] = h[p] + 1;
		qt[h[i]] ^= 1;
	}
	printf("%d\n", accumulate(qt, qt + n + 2, 0));
}