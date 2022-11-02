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

int f(int x) {
	int ans = 1;
	while(x) {
		int y = (x % 10);
		if(y) ans *= y;
		x /= 10;
	}
	return ans;
}

const int N = 1123456;
int g[N];
vector<int> v[20];

int main() {
	int i, q;
	rd(q);
	for(i = 0; i < 10; i++) g[i] = i;
	for(i = 10; i < N; i++)
		g[i] = g[f(i)];
	for(i = 1; i < N; i++)
		v[g[i]].pb(i);
	while(q--) {
		int l, r, k;
		rd(l); rd(r); rd(k);
		printf("%d\n", int(upper_bound(v[k].begin(), v[k].end(), r) - lower_bound(v[k].begin(), v[k].end(), l)));
	}

}