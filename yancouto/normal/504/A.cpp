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
#ifdef ONLINE_JUDGE
#	define LLD "%I64d"
#	define debug(args...) {}
#else
#	define LLD "%lld"
#	define debug(args...) fprintf(stderr, args)
#endif

int deg[112345], s[112345];
set<int> adj[112345];
int main() {
	int i, j, n;
	scanf("%d", &n);
	int tot = n;
	vector<int> d;
	for(i = 0; i < n; i++) {
		scanf("%d %d", &deg[i], &s[i]);
		if(deg[i] == 1) d.pb(i);
		if(deg[i] == 0) tot--;
	}
	int ar = accumulate(deg, deg + n, 0) / 2;
	while(tot) {
		int x = d.back(); d.pop_back(); tot--;
		adj[x].insert(s[x]);
		adj[s[x]].insert(x);
		if(deg[s[x]] > 1) {
			s[s[x]] ^= x;
			if(--deg[s[x]] == 1) d.pb(s[x]);
		}
	}
	printf("%d\n", ar);
	for(i = 0; i < n; i++)
		for(int v : adj[i])
			if(v > i)
				printf("%d %d\n", i, v);
}