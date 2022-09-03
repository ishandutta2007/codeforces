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
ll row[500];
ll col[500];

int main () {
	scanf ("%d", &n);
	int ii, jj;
	ll d1 = 0, d2 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			int x;
			scanf ("%d", &x);
			if (x == 0) {
				ii = i;
				jj = j;
			}
			row[i] += x;
			col[j] += x;
			if (i == j) d1 += x;
			if (i == n - j - 1) d2 += x;
		}
	if (n == 1) {
		printf ("1\n");
		re 0;
	}
	ll tmp = row[(ii + 1) % n] - row[ii];
	row[ii] += tmp;
	col[jj] += tmp;
	if (ii == jj) d1 += tmp;
	if (ii == n - jj - 1) d2 += tmp;
	int ok = int (tmp > 0 && d1 == d2);
	for (int i = 0; i < n; i++) ok &= int (row[i] == d1 && col[i] == d1);
	if (ok) cout << tmp << endl; else cout << -1 << endl;
	return 0;
}