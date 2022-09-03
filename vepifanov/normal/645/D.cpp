#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define j0 j5743892
#define j1 j542893
#define prev PREV
#define next NEXT
                         
typedef vector<int> vi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }
template<class T> T sqr(T a) { re a * a; }
template<class T> T sgn(T a) { re a > 0 ? 1 : (a < 0 ? -1 : 0); }

#define filename ""

int n;
int m;
int was[100000];
vi v[100000];
vi q;
map<ii, int> num;

int go (int x) {
	if (was[x]) re 0;
	was[x] = 1;
	for (int i = 0; i < sz (v[x]); i++) go (v[x][i]);
	q.pb (x);
	re 0;
}

int main () {
	scanf ("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf ("%d%d", &a, &b); a--; b--;
		v[a].pb (b);
		num[mp (a, b)] = i + 1;
	}
	for (int i = 0; i < n; i++) go (i);
	int ans = 0;
	for (int i = 0; i + 1 < n; i++)
		if (!num.count (mp (q[i + 1], q[i]))) {
			printf ("-1\n");
			re 0;
		} else ans = max (ans, num[mp (q[i + 1], q[i])]);
	printf ("%d\n", ans);
	return 0;
}