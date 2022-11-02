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
const int N = 3009;
char g[N][N];
int d[N][N], r[N][N];

vector<int> v[N];
int bit[N];
int add(int i, int x) {
	for(i += 2; i < N; i += (i & -i))
		bit[i] += x;
}
int get(int i) {
	int sum = 0;
	for(i += 2; i; i -= (i & -i))
		sum += bit[i];
	return sum;
}
inline int get(int i, int j) {
	return get(j) - get(max(i, 0) - 1);
}

int main() {
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	for(i = 0; i < n; i++) {
		scanf("%s", g[i]);
		for(j = m - 1; j >= 0; j--)
			if(g[i][j] == 'z')
				r[i][j] = 1 + r[i][j + 1],
				d[i][j] = 1 + (i? d[i - 1][j + 1] : 0);
	}
	ll tot = 0;
	for(j = 0; j < m; j++) {
		for(i = 0; i < n; i++) {
			for(int x : v[i]) add(x, -1);
			v[i].clear();
			if(r[i][j]) add(i, 1), v[min(n, i + r[i][j])].pb(i);
			if(r[i][j]) tot += get(i - min(r[i][j], d[i][j]) + 1, i);
		}
		for(int x : v[n]) add(x, -1);
		v[n].clear();
	}
	printf("%I64d\n", tot);
}