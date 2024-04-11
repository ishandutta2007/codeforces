#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<ll, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int k;
vector<pii> it[2];
int a[2][200009];
int day[2][200009];

ll cost(int d) {
	ll tot = 0;
	int p1 = 0, p2 = 0;
	int n1 = it[0].size(), n2 = it[1].size();
	ll a1 = a[0][d], a2 = a[1][d];
	for(int i = 0; i < k; i++) {
		if(p2 == n2 || (p1 != n1 && a1 * it[0][p1].fst < a2 * it[1][p2].fst))
			tot += a1 * it[0][p1++].fst;
		else tot += a2 * it[1][p2++].fst;
	}
	return tot;
}

void build(int d) {
	int p1 = 0, p2 = 0;
	int n1 = it[0].size(), n2 = it[1].size();
	ll a1 = a[0][d], a2 = a[1][d];
	for(int i = 0; i < k; i++) {
		if(p2 == n2 || (p1 != n1 && a1 * it[0][p1].fst < a2 * it[1][p2].fst))
			printf("%d %d\n", it[0][p1++].snd + 1, day[0][d] + 1);
		else
			printf("%d %d\n", it[1][p2++].snd + 1, day[1][d] + 1);
	}
}

int main() {
	int i, j, n, m, s, t, p;
	scanf("%d %d %d %d", &n, &m, &k, &s);
	for(j = 0; j < 2; j++)
	for(i = 0; i < n; i++) {
		scanf("%d", &a[j][i]);
		day[j][i] = i;
		if(i && a[j][i] > a[j][i - 1]) a[j][i] = a[j][i - 1], day[j][i] = day[j][i - 1];
	}
	for(i = 0; i < m; i++) {
		scanf("%d %d", &t, &p);
		it[t - 1].pb(pii(p, i));
	}
	sort(it[0].begin(), it[0].end());
	sort(it[1].begin(), it[1].end());
	if(cost(n - 1) > s) { puts("-1"); return 0; }
	int l = 0, r = n - 1;
	while(l < r) {
		int m = (l + r) / 2;
		if(cost(m) <= ll(s)) r = m;
		else l = m + 1;
	}
	printf("%d\n", l + 1);
	build(l);
}