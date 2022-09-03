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
string res;
int g[26][26];

int go (int i, int cur) {
	res += char ('a' + cur);
	if (i == n) re 0;
	int k = -1;
	for (int j = 0; j < m; j++)
		if (k == -1 || g[cur][k] > g[cur][(cur + j) % m])
			k = (cur + j) % m;
	g[cur][k]++;
	go (i + 1, k);
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	res = "";
	go (1, 0);
	printf ("%s\n", res.c_str ());
/*	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++)
			printf ("%d ", g[i][j]);
		printf ("\n");
	}*/
	re 0;
}