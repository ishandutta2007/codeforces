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

vector<pii> adj[112];
int memo[112][112][30];
int solve(int i, int j, int l) {
	int &r = memo[i][j][l];
	if(r != -1) return r;
	r = 0;
	for(pii e : adj[i])
		if(e.snd >= l && !solve(j, e.fst, e.snd))
			r = 1;
	return r;
}

int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		int a, b; char c;
		scanf("%d %d %c", &a, &b, &c); a--; b--;
		adj[a].pb(pii(b, c - 'a'));
	}
	memset(memo, -1, sizeof memo);
	for(i = 0; i < n; i++) {
		for(j = 0; j < n; j++)
			putchar(solve(i, j, 0)? 'A' : 'B');
		putchar('\n');
	}
}