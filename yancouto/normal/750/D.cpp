#include <bits/stdc++.h>
using namespace std;
#define i first
#define j second
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

int di[8] = {-1,-1, 0, 1, 1, 1, 0,-1};
int dj[8] = { 0, 1, 1, 1, 0,-1,-1,-1};
int t[100];

set<pii> cover;
set<pii> memo[40][8];
void solve(int i, int d, pii pos) {
	if(i == n) return;
	if(memo[i][d].count(pos)) return;
	memo[i][d].insert(pos);
	cover.insert(pos);
	for(int g = 0; g < t[i] - 1; g++) {
		pos.i += di[d];
		pos.j += dj[d];
		cover.insert(pos);
	}
	int l = (d + 7) % 8, r = (d + 1) % 8;
	pii pl = pos;
	pl.i += di[l];
	pl.j += dj[l];
	solve(i + 1, l, pl);
	pii pr = pos;
	pr.i += di[r];
	pr.j += dj[r];
	solve(i + 1, r, pr);
}

int main() {
	int i;
	rd(n);
	for(i = 0; i < n; i++)
		rd(t[i]);
	solve(0, 0, pii(0, 0));
	printf("%d\n", (int) cover.size());
}