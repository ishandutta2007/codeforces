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
 
int n;
int m;
string ans;
string s;
int was[11][2][1 << 10];
int ct;

int gen (int i, int f, int mask, int j, string cur) {
	if (j > m) re 0;
	if (i == n) {
		ans = cur;
		re 1;
	}
	if (was[i][f][mask] == ct) re 0;
	was[i][f][mask] = ct;
	for (int t = 0; t < 10; t++)
		if (f || (s[i] - '0' <= t))
			if (gen (i + 1, f | int (s[i] - '0' < t), mask | (1 << t), j + int (((mask >> t) & 1) == 0), cur + char (t + '0')))
				re 1;
	re 0;
}

int main () {
	int tt;
	cin >> tt;
	for (int it = 0; it < tt; it++) {
		cin >> s >> m;
		n = sz (s);
		ct++;
		ans = "";
		gen (0, 0, 0, 0, "");
		cout << ans << endl;
	}
    re 0;
}