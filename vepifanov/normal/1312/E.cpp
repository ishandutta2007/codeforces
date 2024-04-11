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
int can[501][501];
int res[501];
int x[501];

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) scanf ("%d", &x[i]);
	for (int i = n - 1; i >= 0; i--)
		for (int j = i; j < n; j++)
			if (i == j)
				can[i][j] = x[i];
			else {
				can[i][j] = -1;
				for (int k = i; k < j; k++)
					if (can[i][k] != -1 && can[i][k] == can[k + 1][j]) {
						can[i][j] = can[i][k] + 1;
						break;
					}	
			}	
	for (int i = 0; i <= n; i++) res[i] = 1e9;
	res[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (can[i][j] != -1)
				res[j + 1] = min (res[j + 1], res[i] + 1);
	printf ("%d\n", res[n]);
	re 0;
}