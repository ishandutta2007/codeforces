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

const int mod = 1000*1000*1000+7;
const int N = 1000*1000;

int n;
int m;
int res[N + 1];
int f[N + 1];
int cnt[N + 1];
int ft[N + 1];
int rft[N + 1];

int calc (int a, int b) {
	if (b == 1) re a;
	int c = f[b];
	while (b % c == 0) b /= c;
	re calc (a, b) - calc (a / c, b);
}

int power (int a, int b) {
	int c = 1;
	while (b) {
		if (b & 1) c = ((ll)c * a) % mod;
		b /= 2;
		a = ((ll)a * a) % mod;
	}
	re c;
}

int main () {
	for (int i = 2; i <= N; i++)
		if (!f[i]) {
			f[i] = i;
			if ((ll)i * i <= N)
				for (int j = i * i; j <= N; j += i)
					if (!f[j])
						f[j] = i;
		}
	ft[0] = rft[0] = 1;
	for (int i = 1; i <= N; i++) {
		ft[i] = ((ll)ft[i - 1] * i) % mod;
		rft[i] = power (ft[i], mod - 2);
	}	
	scanf ("%d", &n);
	memset (res, 0, sizeof (res));
	res[1] = 1;
	cnt[1] = 1;
	int ans = 0, tot = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 2 * i; j <= n; j += i)
			if (res[j] < res[i] + 1) {
				res[j] = res[i] + 1;
				int now = calc (n / i, j / i);
				int sum = n - n / j - now;
				cnt[j] = ((ll)cnt[i] * now % mod * ft[now + sum - 1] % mod * rft[sum]) % mod;
//				printf ("%d -> %d = %d * %d\n", i, j, cnt[i], calc (n / i, j / i));
			} else
			if (res[j] == res[i] + 1) {
				int now = calc (n / i, j / i);
				int sum = n - n / j - now;
				cnt[j] = (cnt[j] + (ll)cnt[i] * now % mod * ft[now + sum - 1] % mod * rft[sum]) % mod;
//				printf ("%d -> %d = %d * %d\n", i, j, cnt[i], calc (n / i, j / i));
			}
//		printf ("%d = %d %d\n", i, res[i], cnt[i]);
		if (res[i] > ans) {
			ans = res[i];
			tot = cnt[i];
		} else
		if (res[i] == ans) tot = (tot + cnt[i]) % mod;
	}
//	for (int i = 1; i <= n - ans; i++) tot = ((ll)tot * i) % mod;
	printf ("%d\n", tot);
	re 0;
}