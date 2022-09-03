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

int get (int x) {
	if (x == 4) re 0;
	if (x == 8) re 1;
	if (x == 15) re 2;
	if (x == 16) re 3;
	if (x == 23) re 4;
	if (x == 42) re 5;
	re -1;
}

int cnt[7];

int main () {
	scanf ("%d", &n);
	cnt[0] = n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x);
		x = get (x);
		if (x == -1) continue;
		if (cnt[x] > 0) {
			cnt[x]--;
			cnt[x + 1]++;
		}	
	}
	printf ("%d\n", n - cnt[6] * 6);
	re 0;
}