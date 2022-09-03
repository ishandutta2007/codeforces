//#pragma GCC optimize ("Ofast")
//#pragma GCC target ("avx2")
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

const int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};
 
int n;
int m;

vvi del (vvi now, int x, int y) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (i == x || j == y || i + j == x + y || i - j == x - y)
				now[i][j] = 0;
	re now;
}

vvi mv (vvi now, int dx, int dy) {
	vvi tmp (8, vi (8, 0));
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			if (now[i][j] && i + dx >= 0 && i + dx < 8 && j + dy >= 0 && j + dy < 8)
				tmp[i + dx][j + dy] = 1;
	re tmp;
}

int main () {
	int ttt;
	scanf ("%d", &ttt);
	for (int it = 0; it < ttt; it++) {
		vvi now (8, vi (8, 1));
		int x = 3, y = 3;
//		now = del (now, x, y);
		printf ("%d %d\n", x + 1, y + 1);
		fflush (stdout);
		while (true) {
			char h[20];
			scanf (" %s", h);
			string s (h);
			if (s == "Done") break;
			int kx = int (s.find("Down") != string::npos) - int (s.find("Up") != string::npos);
			int ky = int (s.find("Right") != string::npos) - int (s.find("Left") != string::npos);
			now = mv (now, kx, ky);
/*			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++)
					cout << ".#"[now[i][j]];
				cout << endl;
			}
			cout << endl;*/
			now = del (now, x, y);
/*			for (int i = 0; i < 8; i++) {
				for (int j = 0; j < 8; j++)
					cout << ".#"[now[i][j]];
				cout << endl;
			}*/
			pair<ii, ii> ans (mp (1e9, -1e9), mp (0, 0));
			for (int t = 0; t < 8; t++) {
				int nx = x + dx[t];
				int ny = y + dy[t];
				if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8) continue;
				ii cur (0, 0);
				for (int tt = 0; tt < 8; tt++) {
					vvi tmp = del (mv (now, dx[tt], dy[tt]), nx, ny);
					int cnt = 0, dist = 0, dist2 = rand () % 100;
					for (int i = 0; i < 8; i++)
						for (int j = 0; j < 8; j++) {
							cnt += tmp[i][j];
							dist += tmp[i][j] * (abs (i - nx) + abs (j - ny));
//							dist2 += now[i][j] * (abs (i - nx) + abs (j - ny));
//							dist2 = max (dist2, now[i][j] * (abs (i - nx) + abs (j - ny)));
						}
					cur = max (cur, mp (cnt, dist * 1000 + dist2));
				}
//				cur.se = cur.se * 10 - min (min (nx, 7 - nx), min (ny, 7 - ny));
				ans = min (ans, mp (cur, mp (nx, ny)));
			}
//			cout << ans.fi.fi << " " << ans.fi.se << endl;
			x = ans.se.fi;
			y = ans.se.se;
			printf ("%d %d\n", x + 1, y + 1);
			fflush (stdout);
		}
	}
    re 0;
}