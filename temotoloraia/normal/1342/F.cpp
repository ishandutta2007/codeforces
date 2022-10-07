#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef pair<int, int> pt;

const int INF = 1e9;
const int N = 15;

int n;
int a[N];
int sum[1 << N];
int dp[N + 1][1 << N][N + 1];
pt p[N + 1][1 << N][N + 1];

void solve() {
	scanf("%d", &n);
	forn(i, n) scanf("%d", &a[i]);
	
	forn(mask, 1 << n) {
		sum[mask] = 0;
		forn(i, n) if (mask & (1 << i))
			sum[mask] += a[i];
	}	
	
	forn(cnt, n + 1) forn(mask, 1 << n) forn(pos, n + 1)
		dp[cnt][mask][pos] = INF;
	
	dp[0][0][0] = 0;
	forn(cnt, n) forn(mask, 1 << n) forn(pos, n) if (dp[cnt][mask][pos] < INF) {
		int rmask = mask ^ ((1 << n) - 1);
		for (int nmask = rmask; nmask; nmask = (nmask - 1) & rmask) {
			if (sum[nmask] <= dp[cnt][mask][pos])
				continue;
			if ((nmask >> pos) == 0)
				continue;
			int npos = pos + __builtin_ctz(nmask >> pos) + 1;
			if (dp[cnt + 1][mask | nmask][npos] > sum[nmask]) {
				dp[cnt + 1][mask | nmask][npos] = sum[nmask];
				p[cnt + 1][mask | nmask][npos] = mp(mask, pos);
			}
		}
	}
	
	int acnt = 0, apos = 0;
	forn(cnt, n + 1) forn(pos, n + 1) if (dp[cnt][(1 << n) - 1][pos] < INF)
		acnt = cnt, apos = pos;
		
	vector<pt> ans;
	
	int mask = (1 << n) - 1, pos = apos;
	for (int cnt = acnt; cnt > 0; --cnt) {
		int nmask = p[cnt][mask][pos].x;
		int npos = p[cnt][mask][pos].y;
		forn(i, n) if ((nmask ^ mask) & (1 << i))
			if (i != pos - 1) ans.pb(mp(i, pos - 1));
		mask = nmask, pos = npos;
	}
	
	
	printf("%d\n", sz(ans));
	forn(i, sz(ans)) {
		int from = ans[i].x;
		forn(j, i) from -= ans[j].x < ans[i].x;
		int to = ans[i].y;
		forn(j, i) to -= ans[j].x < ans[i].y;
		printf("%d %d\n", from + 1, to + 1);
	}
}	

int main() {
	int tc;
	scanf("%d", &tc);
	forn(i, tc) solve();
		
}