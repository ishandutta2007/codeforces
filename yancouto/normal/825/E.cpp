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

const int N = 112345;

int seen[N];
vector<int> adj[N];

int p[N], inv[N], deg[N];

int tn;
int main() {
	int i, j, n, m, a, b;
	rd(n); rd(m);
	for(i = 0; i < m; i++) {
		rd(a); rd(b);
		adj[b].pb(a);
		deg[a]++;
	}
	priority_queue<int> pq;
	for(i = 1; i <= n; i++)
		if(deg[i] == 0)
			pq.push(i);
	while(!pq.empty()) {
		a = pq.top(); pq.pop();
		p[++tn] = a;
		for(int v : adj[a])
			if(--deg[v] == 0)
				pq.push(v);
	}
	reverse(p + 1, p + n + 1);
	for(i = 1; i <= n; i++)
		inv[p[i]] = i;
	for(i = 1; i <= n; i++)
		printf("%d%c", inv[i], " \n"[i == n]);
}