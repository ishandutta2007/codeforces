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

const int N = 10000000;

int n;
int m;

int f[N + 1];

int main () {
	f[1] = 1;
	for (int i = 2; i <= N; i++)
		if (!f[i]) {
			if (i <= N / i)
				for (int j = i * i; j <= N; j += i)
					f[j] = 1;
		}
	int tt;
	scanf ("%d", &tt);
	for (int it = 0; it < tt; it++) {
//		n = it + 2;
		scanf ("%d", &n);
		int a = 0, b = 0;
		for (int t = 1; t <= 100000; t++)
			if (!f[t + n - 1] && f[t]) {
				for (int s = 1; s <= 100000; s++)
					if (!f[t * (n - 1) + s] && f[s]) {
						a = t;
						b = s;
						break;
					}
				if (a != 0) break;
			}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (i + 1 == n && j + 1 == n)
					printf ("%d ", b);
				else
				if (i + 1 == n || j + 1 == n)
					printf ("%d ", a);
				else
					printf ("1 ");	
			}
			printf ("\n");
		}
		assert (a != 0 && b != 0);
	}
	re 0;
}