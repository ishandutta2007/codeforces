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

int a[112345];

int main() {
	int i, j;
	rd(n);
	a[0] = 1;
	a[n + 1] = 1000000;
	for(i = 1; i <= n; i++) rd(a[i]);
	int ans = INT_MAX;
	for(i = 0; i <= n; i++)
		ans = min(ans, max(a[i] - a[0], a[n + 1] - a[i + 1]));
	printf("%d\n", ans);
}