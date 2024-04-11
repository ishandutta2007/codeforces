#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx2")
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

const int N = 402;

int n;
int m;
int res[N][N];
int cnk[N][N];
int p2[N];

int main () {
	scanf ("%d%d", &n, &m);
	p2[0] = 1;
	for (int i = 1; i <= n; i++) p2[i] = ((ll)p2[i - 1] * 2) % m;
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= i; j++)
			if (i == 0 || j % i == 0)
				cnk[i][j] = 1;
			else
				cnk[i][j] = (cnk[i - 1][j] + cnk[i - 1][j - 1])	% m;
	for (int i = 0; i <= n + 1; i++)
		for (int j = 0; j <= i; j++)
			if (i == 0) 
				res[i][j] = 1;
			else
			if (i >= 2)
				for (int k = 1; k < i && k <= j; k++)
					res[i][j] = (res[i][j] + (ll)res[i - k - 1][j - k] * cnk[j][k] % m * p2[k - 1]) % m;
	int ans = 0;
	for (int i = 0; i <= n; i++) ans = (ans + res[n + 1][i]) % m;
	printf ("%d\n", ans);
	cerr << clock () << endl;
	re 0;
}