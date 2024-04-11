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

const int N = 212345;
vector<int> adj[N];
int seen[N][2];

bool can_draw(int u) {
	seen[u][0] = 1;
	for(int v : adj[u])
		if(seen[v][0] == 1)
			return true;
		else if(!seen[v][0] && can_draw(v))
			return true;
	seen[u][0] = 2;
	return false;
}

vector<int> path;

bool can_win(int u, bool p) {
	if(adj[u].empty()) return p;
	seen[u][p] = 1;
	for(int v : adj[u])
		if(!seen[v][!p] && can_win(v, !p)) {
			path.pb(v + 1);
			return true;
		}
	return false;
}

int main() {
	int m , k, s;
	int i, j;
	rd(n); rd(m);
	for(i = 0; i < n; i++) {
		rd(k);
		while(k--) {
			rd(j); j--;
			adj[i].pb(j);
		}
	}
	rd(s); s--;
	if(can_win(s, 0)) {
		puts("Win");
		printf("%d", s + 1);
		while(!path.empty()) {
			printf(" %d", path.back());
			path.pop_back();
		}
		putchar('\n');
	} else {
		memset(seen, 0, sizeof seen);
		if(can_draw(s))
			puts("Draw");
		else
			puts("Lose");
	}
}