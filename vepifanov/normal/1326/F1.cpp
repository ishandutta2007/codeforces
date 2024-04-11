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

int n;
int m;
string s[20];
int g[20][20];
int cnt[1 << 14][14][1 << 7];
ll res[1 << 14];

int rev (int x, int n) {
	int y = 0;
	for (int i = 0; i < n; i++) {
		y = (y << 1) ^ (x & 1);
		x >>= 1;
	}
	re y;
}

void gen (int i, int last, int mask, int ans) {
	if (i == m) {
//		printf ("%d %d %d %d %d\n", m, i, last, mask, ans);
		cnt[mask][last][ans]++;
		re;
	}
	for (int j = 0; j < n; j++)
		if (((mask >> j) & 1) == 0)
			gen (i + 1, j, mask | (1 << j), ans | (g[last][j] << (i - 1)));
}

int main () {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			g[i][j] = s[i][j] - '0';
	m = (n + 1) / 2;
	for (int i = 0; i < n; i++) gen (1, i, 1 << i, 0);
	if (n % 2 == 0) {
		for (int mask = 0; mask < (1 << n); mask++)
			if (__builtin_popcount (mask) == m)
				for (int i = 0; i < n; i++)
					if ((mask >> i) & 1) {
						int dmask = ((1 << n) - 1) ^ mask;
						for (int j = 0; j < n; j++)
							if ((dmask >> j) & 1) {
//								printf ("%d %d | %d %d\n", mask, i, dmask, j);
								for (int b = 0; b < (1 << (m - 1)); b++)
									if (cnt[dmask][j][b]) {
										int rb = (rev (b, m - 1) << m) ^ (g[i][j] << (m - 1));
										for (int a = 0; a < (1 << (m - 1)); a++)
											if (cnt[mask][i][a])
												res[a ^ rb] += (ll)cnt[mask][i][a] * cnt[dmask][j][b];
									}
		            		}
					}
	} else {
		for (int mask = 0; mask < (1 << n); mask++)
			if (__builtin_popcount (mask) == m)
				for (int i = 0; i < n; i++)
					if ((mask >> i) & 1) {
						int dmask = ((1 << n) - 1) ^ mask ^ (1 << i);
//						printf ("%d %d | %d %d\n", mask, i, dmask, i);
						for (int b = 0; b < (1 << (m - 1)); b++)
							if (cnt[dmask][i][b]) {
//								printf ("b = %d\n", b);
								int rb = rev (b, m - 1) << (m - 1);
								for (int a = 0; a < (1 << (m - 1)); a++)
									if (cnt[mask][i][a]) {
//										printf ("ab = %d\n", a ^ rb);
										res[a ^ rb] += (ll)cnt[mask][i][a] * cnt[dmask][i][b];
									}	
							}
					}
	}
	for (int i = 0; i < (1 << (n - 1)); i++) printf ("%lld ", res[i]);
	printf ("\n");
	cerr << clock () << endl;
	re 0;
}