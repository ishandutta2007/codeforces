#include <bits/stdc++.h>
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORd(i, a, b) for(int i = (a) - 1; i >= (b); i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
#define EPS 1e-9
const int mod = 1000000007;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld PI = 2 * acos(0);

#define maxv 1010
#define maxe 1000010
struct HopcroftKarp {
	int nx, ny, E, adj[maxe], next[maxe], last[maxv], run[maxv], level[maxv], que[maxv], matx[maxv], maty[maxv];
	void init(int _nx, int _ny) {
		nx = _nx; ny = _ny;
		E = 0; memset(last, -1, sizeof(last));
		memset(matx, -1, sizeof(matx)); memset(maty, -1, sizeof(maty));
	}
	void add(int x, int y) {
		adj[E] = y; next[E] = last[x]; last[x] = E++;
	}
	bool bfs() {
		int qsize = 0;
		for (int x = 1; x <= nx; x++) if (matx[x] != -1) level[x] = -1;
		else {
			level[x] = 0;
			que[qsize++] = x;
		}
		bool found = false;
		for (int i = 0; i < qsize; i++) {
			for (int x = que[i], e = last[x]; e != -1; e = next[e]) {
				int y = adj[e];
				if (maty[y] == -1) found = true;
				else if (level[maty[y]] == -1) {
					level[maty[y]] = level[x] + 1;
					que[qsize++] = maty[y];
				}
			}
		}
		return found;
	}
	int dfs(int x) {
		for (int &e = run[x]; e != -1; e = next[e]) {
			int y = adj[e];
			if (maty[y] == -1 || (level[maty[y]] == level[x] + 1 && dfs(maty[y]))) {
				matx[x] = y;
				maty[y] = x;
				return 1;
			}
		}
		return 0;
	}
	int maxmat() {
		int total = 0;
		while (bfs()) {
			for (int x = 1; x <= nx; x++) run[x] = last[x];
			for (int x = 1; x <= nx; x++) if (matx[x] == -1) total += dfs(x);
		}
		return total;
	}
} hopkarp;

const int maxn = 10000010;
const int maxc = 2;
struct Node {
	Node* bfail;
	Node* parent;
	Node* child[2];
	Node* gfail;
	int key;
	char val;
	Node () {
		bfail = 0;
		key = -1;
	};
} node[maxn];

Node* alloc = node;
Node* q[maxn];
Node* root = alloc++;

Node* insert(Node* x, string s, int key) {
	for (int i = 0; i < sz(s); i++) {
		int c = s[i] - 'a';
		if (x->child[c] == 0) {
			x->child[c] = alloc++;
			x->child[c]->val = c;
			x->child[c]->parent = x;
		}
		x = x->child[c];
	}
	x->key = key;
	return x;
}

void pushlink(Node* root) {
	int b = 0, e = 0;
	q[e++] = root;
	while (b < e) {
		Node* x = q[b++];
		for (int i = 0; i < maxc; i++) {
			if (x->child[i]) q[e++] = x->child[i];
		}
		if (x == root || x->parent == root) {
			x->bfail = root;
			x->gfail = 0;
		}
		else {
			x->bfail = x->parent->bfail;
			while (x->bfail != root && !x->bfail->child[x->val]) x->bfail = x->bfail->bfail;
			if (x->bfail->child[x->val]) x->bfail = x->bfail->child[x->val];
			if (x->bfail->key != -1) x->gfail = x->bfail;
			else x->gfail = x->bfail->gfail;
		}
	}
}

int n;
string s[1000];
bool g[1000][1000];
vi adj[1000];
vi radj[1000];
bool vis[2][1000];
bool mark[2000];

void go(int k) {
	Node* cur = root;
	FOR(i, 0, sz(s[k])) {
		while (cur != root && !cur->child[s[k][i] - 'a']) cur = cur->bfail;
		if (cur->child[s[k][i] - 'a']) cur = cur->child[s[k][i] - 'a'];
		
		Node* tmp = cur;
		if (tmp->key == -1) tmp = tmp->gfail;
		while (tmp && !g[k][tmp->key]) {
			g[k][tmp->key] = 1;
			tmp = tmp->gfail;
		}
	}
}

void dfs(int u, bool flag) {
	vis[flag][u] = 1;
	if (flag) {
		mark[u] = 1;
		FOR(i, 0, sz(adj[u])) {
			int v = adj[u][i];
			if (!vis[!flag][v] && hopkarp.matx[u] != v) dfs(v, !flag);
		}
	}
	else {
		mark[u + n] = 1;
		FOR(i, 0, sz(radj[u])) {
			int v = radj[u][i];
			if (!vis[!flag][v] && hopkarp.maty[u] == v) dfs(v, !flag);
		}
	}
}

void solve() {
	cin>>n;
	FOR(i, 0, n) {cin>>s[i]; insert(root, s[i], i);}
	pushlink(root);
	FOR(i, 0, n) go(i);
	hopkarp.init(n, n);
	FOR(i, 0, n) FOR(j, 0, n) if (g[i][j] && i != j) {
		hopkarp.add(i + 1, j + 1);
		adj[i + 1].push_back(j + 1);
		radj[j + 1].push_back(i + 1);
	}
	hopkarp.maxmat();
	FOR(i, 1, n + 1) if (!vis[1][i] && hopkarp.matx[i] == -1) dfs(i, 1);
	vi ans;
	FOR(i, 1, n + 1) if (mark[i] && !mark[i + n]) ans.push_back(i);
	cout<<sz(ans)<<"\n";
	FOR(i, 0, sz(ans)) cout<<ans[i]<<" ";
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(NULL);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}