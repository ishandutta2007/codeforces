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

const int N = 200000;
const int NN = 100;

int n;
int m;
string s;
int pos;
int p[N];
int q[N];

int go (int l, int r, int final) {
	if (l + 1 == r) re 1;
	int s = (l + r) / 2;
	if (!go (l, s, final)) re 0;
	if (!go (s, r, final)) re 0;
	int i = l, j = s, k = l;
	while (i < s && j < r) {
		if (pos == n) re 0;
		if (::s[pos++] == '0') {
			q[k++] = p[i++];
		} else {
			q[k++] = p[j++];
		}
	}
	while (i < s) q[k++] = p[i++];
	while (j < r) q[k++] = p[j++];
	for (int t = l; t < r; t++) p[t] = q[t];
	re 1;
}

int main () {
	cin >> s;
	n = sz (s);
	int l = 0, r = N;
	while (r - l > 1) {
		int s = (l + r) / 2;
		pos = 0;
		if (go (0, s, false))
			if (pos == n) {
				pos = 0;
				for (int j = 0; j < s; j++) p[j] = j;
				go (0, s, true);
				for (int j = 0; j < s; j++) p[q[j]] = j;
				printf ("%d\n", s);
				for (int j = 0; j < s; j++) printf ("%d ", p[j] + 1);
				printf ("\n");
				break;			
			}
		if (pos >= n) r = s; else l = s;
	}
	cerr << clock () << endl;	
	re 0;
}