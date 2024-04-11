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
#	define lld I64d
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n;
vector<int> ap[312345];

int main() {
	int i, j, op, x, q;
	scanf("%d %d", &n, &q);
	set<int> all;
	int en = 0;
	for(i = 0; i < q; i++) {
		scanf("%d %d", &op, &x);
		if(op == 1) {
			ap[x].pb(en);
			all.insert(en++);
		} else if(op == 2) {
			for(int o : ap[x])
				all.erase(o);
			ap[x].clear();
		} else {
			while(!all.empty() && *all.begin() < x)
				all.erase(all.begin());
		}
		printf("%d\n", (int)all.size());
	}
}