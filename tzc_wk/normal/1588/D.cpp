#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1,typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1,typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 10;
const int MAXP = 1024;
int n; string s[MAXN + 3];
int id[128]; bool ban[55];
vector<int> occ[MAXN + 3][55];
int dp[55][MAXP + 5], inq[55][MAXP + 5];
pii pre[55][MAXP + 5];
char askc(int c) {
	if (c < 26) return 'a' + c;
	else return 'A' + c - 26;
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) for (int j = 0; j < 53; j++) occ[i][j].clear();
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) for (int j = 0; j < s[i].size(); j++)
		occ[i][id[s[i][j]]].pb(j);
	for (int i = 1; i <= n; i++) occ[i][52].pb(-1);
	for (int i = 0; i < 52; i++) {
		ban[i] = 0;
		for (int j = 1; j <= n; j++) ban[i] |= (occ[j][i].empty());
	}
	dp[52][0] = 0; queue<pii> q; q.push(mp(52, 0));
	memset(inq, 0, sizeof(inq)); inq[52][0] = 1;
	while (!q.empty()) {
		pii p = q.front(); q.pop();
		int x = p.fi, y = p.se; inq[x][y] = 0;
		for (int c = 0; c < 52; c++) {
			if (ban[c]) continue;
			bool flg = 1; int msk = 0;
			for (int i = 1; i <= n; i++) {
				int pos = occ[i][x][y >> (i - 1) & 1], tt = -1;
				for (int j = 0; j < occ[i][c].size(); j++) {
					if (occ[i][c][j] > pos) {
						tt = j; break;
					}
				}
				if (tt == -1) {flg = 0; break;}
				msk |= (tt << i - 1);
			}
			if (flg) {
				if (dp[c][msk] < dp[x][y] + 1) {
					dp[c][msk] = dp[x][y] + 1;
					pre[c][msk] = mp(x, y);
					if (!inq[c][msk]) inq[c][msk] = 1, q.push(mp(c, msk));
				}
			}
		}
	}
	pair<int, pii> mx = mp(-1, mp(0, 0));
	for (int i = 0; i < 53; i++) for (int j = 0; j < (1 << n); j++)
		chkmax(mx, mp(dp[i][j], mp(i, j)));
	string res; int X = mx.se.fi, Y = mx.se.se;
	while(X ^ 52) {
		res.pb(askc(X)); pii pp = pre[X][Y];
		X = pp.fi; Y = pp.se;
	}
	reverse(res.begin(), res.end());
	cout << mx.fi << endl << res << endl;
}
int main() {
	for (int i = 0; i < 26; i++) id[i + 'a'] = i;
	for (int i = 0; i < 26; i++) id[i + 'A'] = 26 + i;
	int qu; scanf("%d", &qu);
	while (qu--) solve();
	return 0;
}