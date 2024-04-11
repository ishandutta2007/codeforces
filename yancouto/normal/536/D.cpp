#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<ll, ll> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;

const int N = 2123;
vector<pii> adj[N];
int s[2], vn[2], vec[2][N];
int seen[N];
ll p[N];

void go(int i) {
	priority_queue<pii> pq;
	pq.push(pii(0, s[i]));
	//printf("=== %d === (%d) \n", i, s[i] + 1);
	while(!pq.empty()) {
		pii x = pq.top(); pq.pop();
		if(seen[x.snd] == i + 1) continue;
		//printf("%lld(%lld) ", x.snd + 1, p[x.snd]);
		vec[i][++vn[i]] = x.snd;
		seen[x.snd] = i + 1;
		for(pii e : adj[x.snd])
			pq.push(pii(x.fst - e.snd, e.fst));
	}
	//putchar('\n');
}

bool used[2][N][N];
int nx[2][N][N];

void pre(int s) {
	memset(seen, 0, sizeof seen);
	for(int i = 0; i <= n; i++) {
		if(i) seen[vec[s][i]] = 1;
		nx[s][i][n] = n + 1;
		for(int j = n - 1; j >= 0; j--) {
			if(!seen[vec[!s][j + 1]]) nx[s][i][j] = j + 1;
			else nx[s][i][j] = nx[s][i][j + 1];
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			used[s][i][vec[s][j]] = 1;
}

ll memo[2][N][N];
ll acc[2][N][N];

int main() {
	int i, j;
	int m;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &s[0], &s[1]); s[0]--; s[1]--;
	for(i = 0; i < n; i++) scanf("%lld", &p[i]);
	for(i = 0; i < m; i++) {
		int u, v; ll w;
		scanf("%d %d %lld", &u, &v, &w); u--; v--;
		adj[u].pb(pii(v, w));
		adj[v].pb(pii(u, w));
	}
	go(0);
	go(1);
	pre(0);
	pre(1);

	for(int i = n; i >= 0; i--)
		for(int j = n; j >= 0; j--) {
			int mni = nx[1][j][i];
			//printf("(%d, %d) -> (%d, %d)\n", i, j, mni, j);
			assert(mni == n + 1 || !used[1][j][vec[0][mni]]);
			assert(mni > i);
			memo[0][i][j] = acc[1][mni][j];
			acc[0][i][j] = -p[vec[1][j]] * !used[0][i][vec[1][j]] + min(memo[0][i][j], acc[0][i][j + 1]);

			int mnj = nx[0][i][j];
			assert(mnj > j);
			assert(mnj == n + 1 || !used[0][i][vec[1][mnj]]);
			memo[1][i][j] = acc[0][i][mnj];
			acc[1][i][j] = p[vec[0][i]] * !used[1][j][vec[0][i]] + max(memo[1][i][j], acc[1][i + 1][j]);
		}
	if(memo[0][0][0] > 0) puts("Break a heart");
	else if(memo[0][0][0] == 0) puts("Flowers");
	else puts("Cry");
}