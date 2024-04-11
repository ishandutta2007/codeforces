#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 100009;
vector<int> f_inv[N];
int a[N];
int main() {
	int n, m, x, i;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%d", &x);
		f_inv[x].pb(i + 1);
	}
	bool imp = false, amb = false;
	for(i = 0; !imp && i < m; i++) {
		scanf("%d", &x);
		if(f_inv[x].empty()) imp = true;
		else if(f_inv[x].size() > 1) amb = true;
		else a[i] = f_inv[x].back();
	}
	if(imp) puts("Impossible");
	else if(amb) puts("Ambiguity");
	else {
		puts("Possible");
		for(i = 0; i < m; i++)
			printf("%d ", a[i]);
		putchar('\n');
	}
}