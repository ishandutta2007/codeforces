#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define makeunique(x) sort(all(x)), (x).resize(unique(all(x)) - (x).begin())
#define re return
#define y0 y2415
#define y1 y346246
#define j0 j23562456
#define j1 j245623456
#define sqrt(x) sqrt (abs (x))

typedef unsigned long long ull;
typedef long long ll;
typedef double D;
typedef long double ld;
typedef pair <int, int> ii;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <vi> vvi;
typedef vector <string> vs;

template <class T> T gcd (T a, T b) { re a ? gcd (b % a, a) : b; }
template <class T> T abs (T x) { re x > 0 ? x : -x; }
template <class T> T sqr (T x) { re x * x; }
template <class T> int sgn (T x) { re x > 0 ? 1 : (x < 0 ? -1 : 0); }

const ld pi = acos (-1.0);

const int N = 20;
const int N1 = 12;
const int N2 = N - N1;

int n;
int m;

int cnt[1 << 20];
int g[500100];
int g1[500100];
int g2[500100];

char h[500100];
int now[N1 + 1][1 << N2];

int main()
{
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf (" %s", h);
		for (int j = 0; j < m; j++)
			g[j] |= int (h[j] == '1') << i;
	}
	cnt[0] = 0;
	for (int i = 1; i < (1 << n); i++) cnt[i] = cnt[i / 2] + (i & 1);
	int ans = 1e9;
	int n1 = min (n, N1);
	int n2 = n - n1;
	int m1 = (1 << n1) - 1;
	int m2 = (1 << n2);
	for (int j = 0; j < m; j++) {
		g1[j] = g[j] & m1;
		g2[j] = g[j] >> n1;
	}
	for (int i = 0; i <= m1; i += 2) {
		memset (now, 0, sizeof (now));
		for (int j = 0; j < m; j++) {
			int cur = g1[j] ^ i;
			now[cnt[cur]][g2[j]]++;
		}
		for (int j = 0; j < m2; j++) {
			int res = 0;
			for (int k = 0; k <= n1; k++) {
				for (int p = 0; p < m2; p++) {
					int tmp = k + cnt[j ^ p];
					res += now[k][p] * min (tmp, n - tmp);
				}
				if (res > ans) break;
			}	
			ans = min (ans, res);
		}
	}
	printf ("%d\n", ans);
	cerr << clock () << endl;
	return 0;
}