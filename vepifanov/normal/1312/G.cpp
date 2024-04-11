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

const int N = 1000001;

int n;
int m;
int next[N][26];
int x[N];
int res[N];
int cnt[N];
int pos[N];
int fin[N];

int go (int x, int right) {
	cnt[x] = fin[x];
	right += fin[x];
	pos[x] = right;
	for (int i = 0; i < 26; i++)
		if (next[x][i] != 0) {
			int tmp = go (next[x][i], right);
			cnt[x] += tmp;
			right += tmp;
		}
	re cnt[x];
}

int go2 (int x, int d, int right, int best) {
	res[x] = min (d, pos[x] + best);
//	printf ("%d %d %d %d = %d %d %d\n", x, d, right, best, cnt[x], pos[x], res[x]);
	if (fin[x]) d = min (d, res[x]);
	best = min (best, d - right);
	right += fin[x];
	for (int i = 0; i < 26; i++)
		if (next[x][i] != 0) {
			go2 (next[x][i], d + 1, right, best);
			right += cnt[next[x][i]];
		}
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		char c[5];
		scanf ("%d %s", &x, c);
		next[x][c[0] - 'a'] = i;
	}
	scanf ("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf ("%d", &x[i]);
		fin[x[i]] = 1;
	}
	go (0, 0);
	go2 (0, 0, 0, 0);
	for (int i = 0; i < m; i++) printf ("%d ", res[x[i]]);
	printf ("\n");
	re 0;
}