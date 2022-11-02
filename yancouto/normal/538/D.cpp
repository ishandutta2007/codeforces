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

pii es[50*51]; int en;
int n; char g[60][60], g2[200][200];
inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < n && j < n; }
int main() {
	int i, j, k;
	scanf("%d", &n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++) {
			scanf(" %c", &g[i][j]);
			if(g[i][j] == 'o')
				es[en++] = pii(i, j);
		}
	bool ok = true;
	for(i = 0; i < 2 * n - 1; i++)
		for(j = 0; j < 2 * n - 1; j++) {
			if(i == n - 1 && j == n - 1) { g2[i][j] = 'o'; continue; }
			if(!ok) break;
			int di = i - (n - 1), dj = j - (n - 1);
			for(k = 0; k < en; k++) {
				int ni = es[k].fst + di, nj = es[k].snd + dj;
				if(!valid(ni, nj)) continue;
				if(g[ni][nj] == '.') break;
			}
			if(k == en) {
				g2[i][j] = 'x';
				for(k = 0; k < en; k++) {
					int ni = es[k].fst + di, nj = es[k].snd + dj;
					if(!valid(ni, nj)) continue;
					if(g[ni][nj] == 'x') g[ni][nj] = 'y';
				}
			} else g2[i][j] = '.';
		}
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(g[i][j] == 'x')
				ok = false;
	if(!ok) { puts("NO"); return 0; }
	puts("YES");
	for(i = 0; i < 2 * n - 1; i++) {
		for(j = 0; j < 2 * n - 1; j++)
			putchar(g2[i][j]);
		putchar('\n');
	}
}