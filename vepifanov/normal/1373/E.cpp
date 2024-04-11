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

int main () {
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
		scanf ("%d%d", &n, &m);
		string ans = "-1";
		for (int a = 0; a <= n; a++)
			for (int b = 0; b <= n; b += 9)
				for (int c = 0; c < 10; c++) {
					int cur = 0;
					for (int t = 0; t <= m; t++)
						if (c + t < 10)
							cur += a + b + c + t;
						else
							cur += a + 1 + c + t - 10;
					if (cur == n) {
						string cur = "";
						int A = a, f = 0;
						while (A > 0) {
							int tmp = min (A, 8 + f);
							f = 1;
							cur += '0' + tmp;
							A -= tmp;
						}
						reverse (all (cur));
						cur += string (b / 9, '9');
						cur += '0' + c;
						if (ans == "-1" || (sz (ans) > sz (cur) || (sz (ans) == sz (cur) && ans > cur))) ans = cur;
					}
				}
		cout << ans << endl;
	}
	re 0;
}