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

const int N = 4000000;
 
int n;
int m;
int res[N + 1];

int main () {
	scanf ("%d%d", &n, &m);
	res[1] = 0;
	int sum = 0;
	int pref = 0;
	for (int i = 1; i <= n; i++) {
		pref = (pref + res[i]) % m;
		res[i] = (sum + pref) % m;
		if (i == 1) res[i] = 1;
		for (int j = 2; i * j <= n; j++) {
			res[i * j] = (res[i * j] + res[i]) % m;
//			printf ("add %d %d %d\n", i * j, (i + 1) * j - 1, res[i]);
			if ((i + 1) * j <= n) res[(i + 1) * j] = (res[(i + 1) * j] + m - res[i]) % m;
		}
		sum = (sum + res[i]) % m;
//		printf ("%d = %d %d %d\n", i, res[i], sum, pref);
	}
	printf ("%d\n", res[n]);
	cerr << clock () << endl;
    re 0;
}