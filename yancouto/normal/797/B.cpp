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
int a[112345];

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) rd(a[i]);
	int ans = 0, co = 0, mo = INT_MAX;
	for(i = 0; i < n; i++) {
		if(a[i] < 0) continue;
		ans += a[i];
		if(a[i] % 2) co++;
		if(a[i] % 2) mo = min(mo, a[i]);
	}
	for(i = 0; i < n; i++)
		if(a[i] < 0 && (a[i] % 2) && -a[i] < mo)
			mo = -a[i];
	if(co == 0) {
		printf("%d\n", ans - mo);
	} else if(co % 2) {
		printf("%d\n", ans);
	} else {
		printf("%d\n", ans - mo);
	}
}