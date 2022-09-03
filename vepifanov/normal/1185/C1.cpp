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
int cnt[101];

int main () {
	scanf ("%d%d", &n, &m);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		sum += x;
		int cur = 0, rem = sum;
		for (int j = 100; j > 0; j--)
			if (rem - cnt[j] * j > m) {
				cur += cnt[j];
				rem -= cnt[j] * j;
			} else {
				cur += (rem - m + j - 1) / j;
				break;
			}
		printf ("%d ", cur);
		cnt[x]++;
	}
	printf ("\n");
	re 0;
}