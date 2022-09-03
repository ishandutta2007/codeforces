#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin (),(x).end()
#define sqrt(x) sqrt(abs(x))
#define re return
#define sz(x) ((int)(x).size ())
#define prev PREV
#define next NEXT

using ll = long long;
using ii = pair<int, int>;
using ld = long double;
using D = double;
using vi = vector<int>;
using vii = vector<ii>;
using vvi = vector<vi>;
using vs = vector<string>;

template<typename T> T abs (T x) { re x < 0 ? -x : x; }
template<typename T> T sgn (T x) { re x < 0 ? -1 : (x > 0 ? 1 : 0); }
template<typename T> T sqr (T x) { re x * x; }
template<typename T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }

const int N = 1010;
const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

int n;
int m;
int was[N][N];
int d[2][N][N];
ii q[N * N];

void go (int t, int sx, int sy) {
	memset (was, 0, sizeof (was));
	int l = 0, r = 1;
	q[0] = mp (sx, sy);
	d[t][sx][sy] = 0;
	was[sx][sy] = 1;
	while (l < r) {
		int x = q[l].fi;
		int y = q[l].se;
		l++;
		for (int d = 0; d < 8; d++) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (nx < 1 || nx > n || ny < 1 || ny > m || was[nx][ny]) continue;
			was[nx][ny] = 1;
			::d[t][nx][ny] = ::d[t][x][y] + 1;
			q[r++] = mp (nx, ny);
		}
	}
}

int one (int x1, int y1, int x2, int y2) {
	int x = abs (x2 - x1);
	int y = abs (y2 - y1);
	re int (x * y == 2);
}

const int NN = 41;

char res[NN][NN][NN][NN][2];
//int dep[NN][NN][NN][NN][2];
pair<char, char> par[NN][NN][NN][NN][2];
char cnt[NN][NN][NN][NN][2];
//vector<pair<pair<pair<char, char>, pair<char, char>>, char> > w[NN][NN][NN][NN][2];

void calc () {
	vector<pair<pair<pair<char, char>, pair<char, char>>, char> > q;
	int l = 0;
	for (int x1 = 1; x1 <= n; x1++)
		for (int y1 = 1; y1 <= m; y1++)
			for (int x2 = 1; x2 <= n; x2++)
				for (int y2 = 1; y2 <= m; y2++)
					for (int t = 0; t < 2; t++) {
						if (x1 == x2 && y1 == y2) {
							res[x1][y1][x2][y2][t] = -1;
							q.pb (mp (mp (mp (x1, y1), mp (x2, y2)), t));
							continue;
						}
						if (t == 0) {
							if (x2 == n / 2 + 1 && y2 == m / 2 && !one (x1, y1, x2, y2)) {
								res[x1][y1][x2][y2][t] = -1;
								q.pb (mp (mp (mp (x1, y1), mp (x2, y2)), t));
								continue;
							}
						} else {
							if (x2 == n / 2 && y2 == m / 2 && !one (x1, y1, x2, y2)) {
								res[x1][y1][x2][y2][t] = -1;
								q.pb (mp (mp (mp (x1, y1), mp (x2, y2)), t));
								continue;
							}
						}
						for (int d = 0; d < 8; d++) {
							int nx = x1 + dx[d];
							int ny = y1 + dy[d];
							if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
							cnt[x1][y1][x2][y2][t]++;
//							w[x2][y2][nx][ny][t ^ 1].pb (mp (mp (mp (x1, y1), mp (x2, y2)), t));
						}
					}
	while (l < sz (q)) {
		int x1 = q[l].fi.fi.fi;
		int y1 = q[l].fi.fi.se;
		int x2 = q[l].fi.se.fi;
		int y2 = q[l].fi.se.se;
		int t = q[l].se;
		l++;
		for (int d = 0; d < 8; d++) {
			int nx1 = x2 + dx[d];
			int ny1 = y2 + dy[d];
			int nx2 = x1;
			int ny2 = y1;
			int nt = t ^ 1;
			if (nx1 < 1 || ny1 < 1 || nx1 > n || ny1 > m) continue;
			if (res[nx1][ny1][nx2][ny2][nt]) continue;
			if (res[x1][y1][x2][y2][t] == -1) {
				res[nx1][ny1][nx2][ny2][nt] = 1;
				par[nx1][ny1][nx2][ny2][nt] = mp (x2, y2);
				q.pb (mp (mp (mp (nx1, ny1), mp (nx2, ny2)), nt));
			} else {
				cnt[nx1][ny1][nx2][ny2][nt]--;
				if (!cnt[nx1][ny1][nx2][ny2][nt]) {
					par[nx1][ny1][nx2][ny2][nt] = mp (x2, y2);
					res[nx1][ny1][nx2][ny2][nt] = -1;
					q.pb (mp (mp (mp (nx1, ny1), mp (nx2, ny2)), nt));
				}
			}
		}
	}
}

int main () {
	int x1, y1, x2, y2;
	scanf ("%d%d", &n, &m);
	scanf ("%d%d%d%d", &x1, &y1, &x2, &y2);
	calc ();
	go (0, n / 2, m / 2);
	go (1, n / 2 + 1, m / 2);
	if (res[x1][y1][x2][y2][0] == 1) {
		printf ("WHITE\n"); fflush (stdout);
		while (true) {
			int nx = par[x1][y1][x2][y2][0].fi;
			int ny = par[x1][y1][x2][y2][0].se;
			printf ("%d %d\n", nx, ny);
			fflush (stdout);
			x1 = nx;
			y1 = ny;
			if (d[0][x1][y1] == 0 || (x2 == x1 && y2 == y1)) break;
			scanf ("%d%d", &x2, &y2);
		}
	} else {
		printf ("BLACK\n"); fflush (stdout);
		scanf ("%d%d", &x1, &y1);
		while (true) {
			int nx = par[x2][y2][x1][y1][1].fi;
			int ny = par[x2][y2][x1][y1][1].se;
			printf ("%d %d\n", nx, ny);
			fflush (stdout);
			x2 = nx;
			y2 = ny;
			if (d[1][x2][y2] == 0 || (x2 == x1 && y2 == y1)) break;
			scanf ("%d%d", &x1, &y1);
		}
	}
/*
	if (d[0][x1][y1] < d[1][x2][y2]) {
		printf ("WHITE\n");
		fflush (stdout);
		while (true) {
			if (one (x1, y1, x2, y2)) {
				printf ("%d %d\n", x2, y2);
				fflush (stdout);
				break;
			}
			pair<ii, ii> best (mp (1e9, 1e9), mp (-1, -1));
			for (int d = 0; d < 8; d++) {
				int nx = x1 + dx[d];
				int ny = y1 + dy[d];
				if (nx < 1 || nx > n || ny < 1 || ny > m || one (nx, ny, x2, y2)) continue;
				best = min (best, mp (mp (::d[0][nx][ny], -::d[1][nx][ny]), mp (nx, ny)));
			}	
			printf ("%d %d\n", best.se.fi, best.se.se);
			fflush (stdout);
			x1 = best.se.fi;
			y1 = best.se.se;
			if (d[0][x1][y1] == 0) break;
			scanf ("%d%d", &x2, &y2);
			if (x2 == -1 && y2 == -1) break;
		}
	} else
	if (d[0][x1][y1] == d[1][x2][y2]) {
		printf ("WHITE\n");
		fflush (stdout);
		while (true) {
			if (one (x1, y1, x2, y2)) {
				printf ("%d %d\n", x2, y2);
				fflush (stdout);
				break;
			}
			for (int d = 0; d < 8; d++) {
				int nx = x1 + dx[d];
				int ny = y1 + dy[d];
				if (nx < 1 || nx > n || ny < 1 || ny > m) continue;
				if (::d[0][nx][ny] < ::d[0][x1][y1]) {
					printf ("%d %d\n", nx, ny);
					fflush (stdout);
					x1 = nx;
					y1 = ny;
					break;
				}
			}
			if (d[0][x1][y1] == 0) break;
			scanf ("%d%d", &x2, &y2);
			if (x2 == -1 && y2 == -1) break;
		}
	} else {
		printf ("BLACK\n");
		fflush (stdout);
		while (true) {
			scanf ("%d%d", &x1, &y1);
			if (x1 == -1 && y1 == -1) break;
			if (one (x1, y1, x2, y2)) {
				printf ("%d %d\n", x1, y1);
				fflush (stdout);
				break;
			}
			pair<ii, ii> best (mp (1e9, 1e9), mp (-1, -1));
			for (int d = 0; d < 8; d++) {
				int nx = x2 + dx[d];
				int ny = y2 + dy[d];
				if (nx < 1 || nx > n || ny < 1 || ny > m || one (nx, ny, x1, y1)) continue;
				best = min (best, mp (mp (::d[1][nx][ny], -::d[0][nx][ny]), mp (nx, ny)));
			}	
			printf ("%d %d\n", best.se.fi, best.se.se);
			fflush (stdout);
			x2 = best.se.fi;
			y2 = best.se.se;
			if (d[1][x2][y2] == 0) break;
		}
	}*/
	re 0;
}