#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

const int N = 200010;
const int MID = 33;

const int mul1 = 239;
const int mod1 = 1000*1000*1000+7;
const int mul2 = 23917;
const int mod2 = 1000*1000*1000+9;

int n;
int m;
char h[N];
string s[N];
string w[N];
pair<string, string> u[N];
ll good = 0;
ll ans = 0;
int p1[N];
int ht1[N];
int p2[N];
int ht2[N];
map<pair<ll, ll>, int> all[MID][MID];

ll get (int l, int r) {
	int tmp1 = ht1[l] - (ll)ht1[r] * p1[r - l] % mod1;
	if (tmp1 < 0) tmp1 += mod1;
	int tmp2 = ht2[l] - (ll)ht2[r] * p2[r - l] % mod2;
	if (tmp2 < 0) tmp2 += mod2;
	re (ll)tmp1 * mod2 + tmp2;
}

void calc (int l, int r) {
	ll cur = 0;
	if (m >= MID) {
		for (int i = l; i < r; i++)
			for (int j = i + 1; j < r; j++) {
				int a = 0, b = m;
				while (u[i].se[a] == u[j].se[a]) a++;
				while (u[i].se[b - 1] == u[j].se[b - 1]) b--;
				int ok = 3;
				for (int k = a + 1; k < b; k++) ok &= int (u[i].se[k] >= u[i].se[k - 1]) + 2 * int (u[j].se[k] >= u[j].se[k - 1]);
				cur++;
				ans += 2 - int (ok > 0);
			}
	} else {
		for (int a = 0; a < m; a++)
			for (int b = a + 1; b <= m; b++)
				all[a][b].clear ();
		for (int i = l; i < r; i++) {
			ht1[m] = ht2[m] = 0;
			for (int j = m - 1; j >= 0; j--) {
				ht1[j] = ((ll)ht1[j + 1] * mul1 + u[i].se[j]) % mod1;
				ht2[j] = ((ll)ht2[j + 1] * mul2 + u[i].se[j]) % mod2;
			}
			for (int a = 0; a < m; a++)
				for (int b = a + 1; b <= m; b++) {
//					printf ("add %d = %d %d %d %d\n", i, a, b, get (0, a), get (b, m));
					all[a][b][mp (get (0, a), get (b, m))]++;
				}
		}
		cerr << clock () << endl;
		for (int i = l; i < r; i++) {
			ht1[m] = ht2[m] = 0;
			for (int j = m - 1; j >= 0; j--) {
				ht1[j] = ((ll)ht1[j + 1] * mul1 + u[i].se[j]) % mod1;
				ht2[j] = ((ll)ht2[j + 1] * mul2 + u[i].se[j]) % mod2;
			}
			for (int j = 0; j < m; ) {
				int k = j;
				while (k + 1 < m && u[i].se[k] <= u[i].se[k + 1]) k++;
				int tmp = all[j][k + 1][mp (get (0, j), get (k + 1, m))] - 1;
//				printf ("%d = %d %d %d %d = %d\n", i, j, k + 1, get (0, j), get (k + 1, m), tmp);
				cur += tmp;
				ans += tmp;
				j = k + 1;
			}
		}
	}
	good += (ll)(r - l) * (r - l - 1) / 2;
	ans += 2 * ((ll)(r - l) * (r - l - 1) / 2 - cur);
}

int main () {
	p1[0] = p2[0] = 1;
	for (int i = 1; i < N; i++) {
		p1[i] = ((ll)p1[i - 1] * mul1) % mod1;
		p2[i] = ((ll)p2[i - 1] * mul2) % mod2;
	}	
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf (" %s", h);
		s[i] = string (h);
		w[i] = s[i];
		sort (all (w[i]));
		u[i] = mp (w[i], s[i]);
	}
	sort (u, u + n);
	m = sz (s[0]);
	ans = 0;
	good = 0;
	for (int i = 0; i < n; ) {
		int j = i;
		while (j < n && u[j].fi == u[i].fi) j++;
		calc (i, j);
		i = j;
	}
	ans += 1337 * ((ll)n * (n - 1) / 2 - good);
	printf ("%lld\n", ans);
	cerr << clock () << endl;
	re 0;
}