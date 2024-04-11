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
char g[4][4];
char o[256];

void solve() {
	int i, j;
	for(i = 0; i + 1 < 4; i++)
		for(j = 0; j + 1 < 4; j++) {
			char c = g[i][j];
			if(c == g[i+1][j] && c == g[i+1][j+1] && c == g[i][j+1]) {
				puts("YES");
				exit(0);
			}
		}
}

int main() {
	int i, j;
	o['#'] = '.';
	o['.'] = '#';
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			scanf(" %c", &g[i][j]);
	solve();
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++) {
			g[i][j] = o[g[i][j]];
			solve();
			g[i][j] = o[g[i][j]];
		}
	puts("NO");
}