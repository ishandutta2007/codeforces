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
char h[10];
string col[100];

string calc () {
	string ans = "blue";
	int cur = 0;
	for (int i = 1; i <= n; i++) {
		if (col[i][0] == 'l') cur = 1;
		if (col[i][0] == 'u') cur = 0;
		if (col[i][0] != 'l' && col[i][0] != 'u' && cur == 0) ans = col[i];
	}
	re ans;
}

int main () {
	scanf ("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf (" %s", h);
		col[i] = string (h);
	}
	printf ("%s\n", calc ().c_str ());
	re 0;
}