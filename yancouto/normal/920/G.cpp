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

// coprimes with x that are <= y
int count(const vector<int> &pos, const vector<int> &neg, int y) {
	int ans = 0;
	for(int x : pos) ans += y / x;
	for(int x : neg) ans -= y / x;
	return ans;
}

const int N = 1000009;

vector<int> ps[N], neg[N], pos[N];

int main() {
	int t, i, j;
	rd(t);
	for(i = 2; i < N; i++)
		if(ps[i].empty())
			for(j = i; j < N; j += i)
				ps[j].pb(i);
	for(i = 1; i < N; i++)
		for(j = 0; j < (1 << int(ps[i].size())); j++) {
			int x = 1;
			for(int k = 0; k < int(ps[i].size()); k++)
				if((j >> k) & 1)
					x *= ps[i][k];
			if(__builtin_popcount(j) & 1) neg[i].pb(x);
			else pos[i].pb(x);
		}
	int x, p, k;
	while(t--) {
		rd(x); rd(p); rd(k);
		k += count(pos[p], neg[p], x);
		int l = 0, r = 1e8;
		while(l < r) {
			int m = (l + r) / 2;
			if(count(pos[p], neg[p], m) >= k) r = m;
			else l = m + 1;
		}
		printf("%d\n", l);
	}
}