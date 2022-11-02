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

int n, t;
char s[100];

int main() {
	int i, j;
	rd(n);
	const int north = 20000, south = 0;
	int cur = north;
	for(i = 0; i < n; i++) {
		rd(t); scanf(" %s", s); string dir = s;
		if(cur == north && dir != "South") break;
		if(cur == south && dir != "North") break;
		if(dir == "North") cur += t;
		else if(dir == "South") cur -= t;
		if(cur < south || cur > north) break;
	}
	if(i == n && cur == north) puts("YES");
	else puts("NO");
}