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

string s[100];

int main() {
	int i, j; ll p;
	rd(n); rd(p);
	for(i = 0; i < n; i++) cin >> s[i];
	ll cur = 0;
	ll tot = 0;
	for(i = n - 1; i >= 0; i--)
		if(s[i] == "half") {
			tot = tot + p * cur;
			cur = 2 * cur;
		} else {
			tot = tot + p * cur + p / 2;
			cur = 2 * cur + 1;
		}
	printf("%lld\n", tot);
}