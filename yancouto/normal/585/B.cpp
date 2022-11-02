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

char g[3][103];
int n;
int memo[3][103][103];
int solve(int i, int j, int t) {
	if(i < 0 || i >= 3) return false;
	if(j == n) {
		return true;
	}
	int &r = memo[i][j][t];
	if(r != -1) return r;
	if(j + 2*t < n && g[i][j + 2*t] != '.' && g[i][j + 2*t] != 's') {
		return r = 0;
	}
	if(j + 2*t + 1 < n && g[i][j + 2*t +  1] != '.') {
		return r = 0;
	}
	r = false;
	if(j + 2*t + 2 >= n || g[i][j + 2*t + 2] == '.')
		r = solve(i, j + 1, t + 1);
	if(i && (j + 2*t + 1 >= n || g[i - 1][j + 2*t + 1] == '.') && (j + 2*t + 2 >= n || g[i - 1][j + 2*t + 2] == '.'))
		r |= solve(i - 1, j + 1, t + 1);
	if(i < 2 && (j + 2*t + 1 >= n || g[i + 1][j + 2*t + 1] == '.') && (j + 2*t + 2 >= n || g[i + 1][j + 2*t + 2] == '.'))
		r |= solve(i + 1, j + 1, t + 1);
	return r;
}

int main() {
	int i, j, si, sj;
	for_tests(t, tt) {
		scanf("%d %*d", &n);
		for(i = 0; i < 3; i++)
			for(j = 0; j < n; j++) {
				scanf(" %c", &g[i][j]);
				if(g[i][j] == 's') si = i, sj = j;
			}
		memset(memo, -1, sizeof memo);
		if(solve(si, sj, 0)) puts("YES");
		else puts("NO");
	}
}