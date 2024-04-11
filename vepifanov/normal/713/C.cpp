#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

int n;
int m;
int x[3010];
ll res[3010];
ll gl[3010][3010];
ll gr[3010][3010];

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) scanf ("%d", &x[i]);
	x[0] = -1e9;
	x[n + 1] = 2e9;
	for (int i = 0; i <= n; i++) {
		ll cur = 0;
		for (int j = i; j <= n + 1; j++) {
			cur += abs (((ll)x[i] + (j - i)) - x[j]);
			gl[i][j] = cur;
		}
	}
	for (int i = 1; i <= n + 1; i++) {
		ll cur = 0;
		for (int j = i; j >= 0; j--) {
			cur += abs (((ll)x[i] + (j - i)) - x[j]);
			gr[i][j] = cur;
		}
	}
	res[0] = 0;
	for (int i = 1; i <= n + 1; i++) res[i] = 1e18;
	for (int i = 0; i <= n; i++)
		for (int j = i + 1; j <= n + 1; j++)
			if (x[j] - x[i] >= j - i) {
				int l = i, r = j - 1;
				while (r - l > 500) {
					int s1 = (2 * l + r) / 3;
					int s2 = (l + 2 * r) / 3;
					ll h1 = gl[i][s1] + gr[j][s1 + 1];
					ll h2 = gl[i][s2] + gr[j][s2 + 1];
					if (h1 < h2) r = s2; else l = s1;
				}
				for (int k = l; k <= r; k++) {
					res[j] = min (res[j], res[i] + gl[i][k] + gr[j][k + 1]);
//					printf ("%d %d %d = %lld %lld %lld\n", i, j, k, res[i] + gl[i][k] + gr[j][k + 1], gl[i][k], gr[j][k + 1]);
				}
			}
	cout << res[n + 1] << endl;
	return 0;
}