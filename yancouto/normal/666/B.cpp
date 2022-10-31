
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINEJUDGE
#	define LLD "%I64d"
#	define debug(...) fprintf(stderr, ...)
#else
#	define LLD "%lld"
#	define debug(...) {}
#endif
const int N = 3009;

int q[N];
int dist[N];
vector<int> adj[N];
vector<pii> adj2[N];
vector<pii> out[N], in[N];

void bfs(int u) {
	int a = 0, b = 0;
	memset(dist, -1, sizeof dist);
	dist[u] = 0;
	q[b++] = u;
	while(a < b) {
		int v = q[a++];
		for(int w : adj[v])
			if(dist[w] == -1) {
				dist[w] = dist[v] + 1;
				adj2[u].pb(pii(w, dist[w]));
				out[u].pb(pii(-dist[w], w));
				//if(out[u].size() > 3) out[u].erase(out[u].begin());
				in[w].pb(pii(-dist[w], u));
				//if(in[w].size() > 3) in[w].erase(in[w].begin());
				q[b++] = w;
			}
	}
}

int mrk[N], t;
bool ok(int u) {
	if(mrk[u] == t) return false;
	mrk[u] = t;
	return true;
}


int B[4];
int main() {
	int i, j, n, m, a, b;
	scanf("%d %d", &n, &m);
	for(i = 0; i < m; i++) {
		scanf("%d %d", &a, &b); a--; b--;
		if(a == b) continue;
		adj[a].pb(b);
	}
	for(i = 0; i < n; i++)
		bfs(i);
	for(i = 0; i < n; i++) {
		if(out[i].size() > 3) {
			nth_element(out[i].begin(), out[i].begin() + 2, out[i].end());
			out[i].erase(out[i].begin() + 3, out[i].end());
		}
		if(in[i].size() > 3) {
			nth_element(in[i].begin(), in[i].begin() + 2, in[i].end());
			in[i].erase(in[i].begin() + 3, in[i].end());
		}
		for(pii &p : out[i]) p.fst = -p.fst;
		for(pii &p : in[i]) p.fst = -p.fst;
	}
	int mx = 0;
	for(i = 0; i < n; i++)
		for(pii e : adj2[i])
			for(pii O : out[e.fst]) { 
				if(O.snd == i) continue;
				for(pii I : in[i]) {
					if(I.snd == e.fst || I.snd == O.snd || e.snd + I.fst + O.fst <= mx) continue;
					mx = e.snd + I.fst + O.fst;
					B[0] = I.snd; B[1] = i;
					B[2] = e.fst; B[3] = O.snd;
				}
			}
	for(i = 0; i < 4; i++)
		printf("%d%c", B[i] + 1, " \n"[i == 3]);
}