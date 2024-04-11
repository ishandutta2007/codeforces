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

const int N = 5000;
const int O = 500000;

int n;
int m;
int r;

int f[N + 1];
vi pr;
int npr[N + 1];
int now[N + 1];
int cnt[N + 1];
int o;
ll sum[O];
ll tot[O];
map<int, int> next[O];

void add (int cur) {
	int tmp = accumulate (now, now + r, 0);
	int pos = 0;
	for (int i = r - 1; i >= 0; i--) {
//		printf ("add %d %d | %d %d\n", i, now[i], pos, cur);
		tot[pos] += cur;
		sum[pos] += (ll)tmp * cur;
		tmp -= now[i];
		if (next[pos].find (now[i]) == next[pos].end ())
			next[pos][now[i]] = o++;
		pos = next[pos][now[i]];
	}
	tot[pos] += cur;
}

ll ans;

void go (int pos, int len, ll csum, ll ctot) {
//	printf ("%d %d %lld %lld\n", pos, len, csum, ctot);
	if (len == -1) {
		ans = min (ans, csum);
		re;
	}
	ans = min (ans, csum + sum[pos]);
	ll small = 0, large = 0, same = 0;
	ll tsmall = 0, tlarge = 0;
	for (auto& v : next[pos]) {
		same += sum[v.se];
		tlarge += tot[v.se];
		large += v.fi * tot[v.se];
	}	
	for (auto& v : next[pos]) {
		large -= v.fi * tot[v.se];
		tlarge -= tot[v.se];
//		printf ("%d %d %lld %lld ", pos, len, csum, ctot);
//		printf ("go %d %d\n", v.fi, v.se);
//		go (v.se, len - 1, csum + (ctot + tot[pos] - tot[v.se]) * v.fi + sum[pos] - sum[v.se] - v.fi * tot[v.se], ctot + tot[pos] - tot[v.se]);
		go (v.se, len - 1, csum + v.fi * ctot + same - sum[v.se] + (v.fi * tsmall - small) + (large - v.fi * tlarge), ctot + tot[pos] - tot[v.se]);
		small += v.fi * tot[v.se];
		tsmall += tot[v.se];
	}	
}

int main () {
	for (int i = 2; i <= N; i++)
		if (!f[i]) {
			npr[i] = sz (pr);
			pr.pb (i);
			for (int j = i; j <= N; j += i)
				if (!f[j])
					f[j] = i;
		}
	r = sz (pr);
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		cnt[x]++;
	}
	memset (now, 0, sizeof (now));
	o = 1;
	for (int i = 0; i <= N; i++) {
		int j = i;
		while (j > 1) {
			int k = f[j];
			while (j % k == 0) {
				j /= k;
//				printf ("++%d %d\n", k, npr[k]);
				now[npr[k]]++;
			}
		}
//		for (int j = 0; j < r; j++) printf ("%d ", now[j]);
//		printf ("\n");
		if (cnt[i] > 0) add (cnt[i]);
	}
	ans = 1e18;
	go (0, r - 1, 0, 0);
	cout << ans << endl;
//	cerr << clock () << endl;
	re 0;
}