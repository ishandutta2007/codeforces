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

const int mod = 1000*1000*1000+7;

int n;
int m;
int cyc;
vii v[200000];
int was[200000];
int d[200000];

int go (int x, int p) {
	m++;
	was[x] = 1;
	for (int i = 0; i < sz (v[x]); i++) {
		int y = v[x][i].fi;
		int z = v[x][i].se;
		if (z == p) continue;
		if (was[y] == 1) {
			cyc = d[x] - d[y] + 1;
		} else
		if (!was[y]) {
			d[y] = d[x] + 1;
			go (y, z);
		}
	}
	was[x] = 2;
	re 0;
}

int main () {
	scanf ("%d", &n);
	for (int i = 0; i < n; i++) {
		int x;
		scanf ("%d", &x); x--;
		v[i].pb (mp (x, i));
		v[x].pb (mp (i, i));
	}
	int res = 1;
	for (int i = 0; i < n; i++)
		if (!was[i]) {
			m = 0;
			cyc = 0;
			go (i, -1);
			int ans = 1;
			for (int i = 0; i < cyc; i++) ans = (ans * 2) % mod;
			ans = (ans + mod - 2) % mod;
			for (int i = 0; i < m - cyc; i++) ans = (ans * 2) % mod;
			res = ((ll)res * ans) % mod;
		}	
	cout << res << endl;
	return 0;
}