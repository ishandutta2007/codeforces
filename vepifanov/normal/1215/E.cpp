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

const int T = 20;

int n;
int m;
int cnt[T];
vi v[T];
ll res[T][400001];
ll ans[1 << T];
ii prv[1 << T];
int x[400001];
vi w[400001];

int out (int mask) {
	if (!mask) re 0;
	int i = prv[mask].se;
	out (mask ^ (1 << i));
	for (int j = 0; j < cnt[i]; j++) printf ("%d ", i + 1);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf ("%d", &x[i]); x[i]--;
		v[x[i]].pb (i);
		cnt[x[i]]++;
	}
	for (int i = 0; i < T; i++)
		for (int j = 0; j < T; j++)
			if (i != j) {
				res[i][j] = 0;
				for (int a = 0, b = 0; a < sz (v[i]); a++) {
					while (b < sz (v[j]) && v[j][b] < v[i][a]) b++;
					res[i][j] += sz (v[j]) - b;
				}
			}
	for (int i = 0; i < (1 << T); i++) ans[i] = 1e18;
	ans[0] = 0;
	for (int i = 0; i < (1 << T); i++) {
		int pos = 0;
		for (int j = 0; j < T; j++)
			if (((i >> j) & 1) == 0) {
				ll cur = 0;
				for (int k = 0; k < T; k++)
					if ((i >> k) & 1)
						cur += res[k][j];
				if (ans[i | (1 << j)] > ans[i] + cur) ans[i | (1 << j)] = ans[i] + cur;
			}
	}
	cout << ans[(1 << T) - 1] << endl;
//	out ((1 << T) - 1);
//	printf ("\n");
	re 0;
}