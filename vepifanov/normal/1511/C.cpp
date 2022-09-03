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
int pos[50];
int fst[50];

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < 50; i++) pos[i] = fst[i] = n;
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x); x--;
		if (fst[x] == n) pos[x] = fst[x] = i;
	}
	for (int i = 0; i < m; i++) {
		int x;
		scanf ("%d", &x); x--;
		int now = pos[x];
		if (now < 0) {
			int cur = 0;
			for (int j = 0; j < 50; j++)
				if (pos[j] < now) 
					cur++;
			now = cur;
		} else {
			int cur = now;
			for (int j = 0; j < 50; j++)
				if (pos[j] < 0 && fst[j] > now) 
					cur++;
			now = cur;
		}
		printf ("%d ", now + 1);
		pos[x] = -(i + 1);
	}
	printf ("\n");
	re 0;
}