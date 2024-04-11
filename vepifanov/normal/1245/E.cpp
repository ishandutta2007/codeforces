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

const int N = 10;

int n;
int m;
int g[N][N];
double res[N][N];

int main () {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf ("%d", &g[i][j]);
	for (int i = 0; i < N; i++)
		if (i & 1) {
			for (int j = N - 1; j >= 0; j--) {
				double sum = 0, stay = 0;
				for (int k = 1; k <= 6; k++) {
					int ii = i, jj = j + k;
					if (jj >= N) {
						ii--;
						jj = 2 * N - jj - 1;
					}
					if (ii < 0) stay++; else sum += min (res[ii][jj], res[ii - g[ii][jj]][jj]);
				}
				res[i][j] = (sum / 6 + 1) / (1 - stay / 6);
			}			
		} else {
			for (int j = 0; j < N; j++)
				if (i == 0 && j == 0)
					res[i][j] = 0;
				else {
					double sum = 0, stay = 0;
					for (int k = 1; k <= 6; k++) {
						int ii = i, jj = j - k;
						if (jj < 0) {
							ii--;
							jj = -jj - 1;
						}
						if (ii < 0) stay++; else sum += min (res[ii][jj], res[ii - g[ii][jj]][jj]);
					}
					res[i][j] = (sum / 6 + 1) / (1 - stay / 6);
				}
		}
	printf ("%.10f\n", res[N - 1][0]);
	re 0;
}