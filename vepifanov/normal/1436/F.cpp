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

const int M = 100000;
const int mod = 998244353;

int n;
int m;
int f[M + 1];
int cnt[M + 1];
int meb[M + 1];

int power (int a, ll b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		a = ((ll)a * a) % mod;
		b /= 2;
	}
	re c;
}

int calc (int d) {
	ll sum = 0;
	for (int i = d; i <= M; i += d) sum += cnt[i];
	if (sum == 1) re 0;
	int ans = 0;
	int cur = 0;
	int ps2 = power (2, sum - 2);
	int mul = ps2;
	if (sum > 2) mul = (mul + (ll)(sum - 2) % mod * power (2, sum - 3)) % mod;
	for (int i = d; i <= M; i += d) {
		ans = (ans + (ll)cnt[i] * i % mod * i % mod * ((sum - 1) % mod) % mod * ps2) % mod;
		ans = (ans + (ll)cur * i % mod * cnt[i] % mod * mul * 2) % mod;
		cur = (cur + (ll)i * cnt[i]) % mod;
		if (cnt[i] > 1)
			ans = (ans + (ll)i * i % mod * cnt[i] % mod * (cnt[i] - 1) % mod * mul) % mod;
	}
//	cout << d << " " << ans << endl;
	re ans;
}

int main () {
	for (int i = 2; i <= M; i++)
		if (!f[i])
			for (int j = i; j <= M; j += i)
				f[j] = i;
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf ("%d%d", &a, &b);
		cnt[a] = b;
	}
	meb[1] = 1;
	for (int i = 2; i <= M; i++)
		if ((i / f[i]) % f[i] == 0)
			meb[i] = 0;
		else
			meb[i] = ((ll)meb[i / f[i]] * (mod - 1)) % mod;	
	int ans = 0;
	for (int d = 1; d <= M; d++)
		if (meb[d] != 0)
			ans = (ans + (ll)calc (d) * meb[d]) % mod;
	printf ("%d\n", ans);
	re 0;
}