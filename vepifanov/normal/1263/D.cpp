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
int p[200100];
int cool[200100];
char h[100];

int gp (int x) {
	if (p[x] == x) re p[x];
	re p[x] = gp (p[x]);
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n + 26; i++) p[i] = i;
	for (int i = 0; i < n; i++) {
		scanf (" %s", h);
		for (int j = 0; h[j]; j++) {
			int a = gp (h[j] - 'a');
			int b = gp (i + 26);
			if (a != b) {
				if (rand () & 1) swap (a, b);
				p[a] = b;
			}
		}
	}
	for (int i = 0; i < n; i++) cool[gp (i + 26)] = 1;
	int ans = 0;
	for (int i = 0; i < n + 26; i++)
		if (p[i] == i && cool[i])
			ans++;
	printf ("%d\n", ans);
	re 0;
}