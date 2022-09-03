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
string s[500];

int main () {
	cin >> n >> m;
	int tot = 0;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) tot += int (s[i][j] == '*');
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (s[i][j] == '*') {
				int cur = 1;
				for (int t = 0; t < 4; t++) {
					int ci = i, cj = j, now = 0;
					while (true) {
						ci += int (t == 0) - int (t == 1);
						cj += int (t == 2) - int (t == 3);
						if (ci < 0 || cj < 0 || ci >= n || cj >= m || s[ci][cj] != '*') break;
						now++;
					}
					if (now == 0) {
						cur = 0;
						break;
					}
					cur += now;
				}
				if (cur == tot) {
					printf ("YES\n");
					re 0;
				}
			}
	printf ("NO\n");
	re 0;
}