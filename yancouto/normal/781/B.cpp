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

int n;

const int N = 1123;
vector<int> c[26][26];

char a[N], b[N], ans[N], bk[N][3];

char A[30], B[30];
int ch[30];

vector<pii> adj[30];
int seen[30], d[30];
int fst;

void dfs(int u) {
	seen[u] = 2;
	int cur = 0;
	for(pii e : adj[u]) {
		int v = e.fst;
		if(seen[v]) continue;
		assert(cur++ == 0);
		ans[e.snd] = u + 'A';
		dfs(v);
	}
	if(cur == 0) {
		reverse(adj[u].begin(), adj[u].end());
		for(pii e : adj[u]) {
			int v = e.fst;
			if(v == fst) {
				ans[e.snd] = u + 'A';
				return;
			}
		}
	}
}

int main() {
	int i, j;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%s %s", A, B);
		c[A[0] - 'A'][A[1] - 'A'].pb(i);
		a[i] = A[2];
		b[i] = B[0];
		bk[i][0] = A[0]; bk[i][1] = A[1];
	}
	for(int x = 0; x < 26; x++)
		for(int y = 0; y < 26; y++) {
			if(c[x][y].empty()) continue;
			for(i = 0; i < 26; i++) adj[i].clear(), d[i] = 0, seen[i] = 0, ch[i] = 0;
			for(int i : c[x][y])
				for(int j : c[x][y])
					if(i != j && a[i] == a[j])
						ans[i] = b[i], ch[b[i] - 'A']++;
			while(true) {
				int ct = 0;
				for(int i : c[x][y]) {
					if(ans[i]) continue;
					if(ch[a[i] - 'A']) {
						ch[b[i] - 'A']++;
						ans[i] = b[i];
						ct++;
					}
				}
				if(ct == 0) break;
			}
			for(int i : c[x][y]) {
				if(ans[i]) continue;
				ans[i] = a[i];
				ch[a[i] - 'A']++;
			}
			for(int i : c[x][y])
				for(int j : c[x][y])
					if(i != j && ans[i] == ans[j]) {
						puts("NO");
						return 0;
					}
		}
	puts("YES");
	for(i = 0; i < n; i++)
		printf("%s%c\n", bk[i], ans[i]);

}