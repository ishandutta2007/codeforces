#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int a[8][3];

inline ll dist(int i, int j) {
	ll dx = a[i][0] - a[j][0];
	ll dy = a[i][1] - a[j][1];
	ll dz = a[i][2] - a[j][2];
	return dx * dx + dy * dy + dz * dz;
}
inline bool ok() {
	ll d[8], x; int dn = 0, i = 0, j;
	ll m1 = LLONG_MAX;
	for(j = 1; j < 8; j++) {
		d[dn++] = dist(0, j);
		if(d[dn-1] < m1) m1 = d[dn-1];
	}
	ll m2 = 2ll * m1, m3 = 3ll * m1;
	int e1 = 0, e2 = 0, e3 = 0;
	for(i = 0; i < dn; i++)
		if(d[i] == m1) e1++;
		else if(d[i] == m2) e2++;
		else if(d[i] == m3) e3++;
	for(i = 1; i < 8; i++)
		for(j = i + 1; j < 8; j++) {
			x = dist(i, j);
			if(x == m1) e1++;
			else if(x == m2) e2++;
			else if(x == m3) e3++;
		}
	return e1 == 12 && e2 == 12 && e3 == 4;
}

void solve(int i) {
	if(i == 8) {
		if(!ok()) return;
		puts("YES");
		for(i = 0; i < 8; i++)
			printf("%d %d %d\n", a[i][0], a[i][1], a[i][2]);
		exit(0);
	}
	int g[3] = {0, 1, 2}, b[3] = {a[i][0], a[i][1], a[i][2]};
	do {
		a[i][0] = b[g[0]]; a[i][1] = b[g[1]]; a[i][2] = b[g[2]];
		solve(i + 1);
	} while(next_permutation(g, g + 3));
}

int main() {
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 3; j++)
			scanf("%d", &a[i][j]);
	solve(0);
	puts("NO");
}