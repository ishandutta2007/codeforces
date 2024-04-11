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
int cnt[1 << 20];
int res[1 << 20][4];
int x[1 << 20];

void go (int x) {
	if (x >= (1 << (n - 1)) - 1) {
		for (int t = 0; t < 4; t++)
			if ((t & 1) + ((t >> 1) & 1) <= cnt[x])
				res[x][t] = int (cnt[x] > 0);
			else
				res[x][t] = -1e9;	
		re;
	}	
	go (2 * x + 1);
	go (2 * x + 2);
	for (int t = 0; t < 4; t++) res[x][t] = -1e9;
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 4; b++) {
			int c = a | b;
			res[x][c] = max (res[x][c], res[2 * x + 1][a] + res[2 * x + 2][b] + c);
		}
	re;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d", &x[i]); x[i]--;
//		printf ("add %d\n", x[i] / 2 + (1 << (n - 1)) - 1);
		cnt[x[i] / 2 + (1 << (n - 1)) - 1]++;
	}
	go (0);

	int ans = 0;
	for (int t = 0; t < 4; t++)
		ans = max (ans, res[0][t] + int (t > 0));
	printf ("%d\n", ans);
	re 0;
}