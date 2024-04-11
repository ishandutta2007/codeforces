#pragma comment(linker, "/STACK:250000000")
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <ctime>
#include <cassert>
#include <memory.h>
#include <fstream>
#include <bitset>
#include <algorithm>
#include <cmath>
        
//#include <unordered_map>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define for1(i, n) for (int i = 1; i < int(n); i++)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define forr(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define forft(i, l, r) for (int i = int(l); i < int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ms(a, v) memset(a, v, sizeof(a))
#define x first
#define y second
#define X first
#define Y second
#define ft first
#define sc second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(4e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;     

const int N = 1e5 + 10;

int n, m;
string s;

int poses[2][N];
int pref[2][N];
int sum[N];
pt z[N];

bool read() {
	cin >> n >> s >> m;
	return true;
}

void solve() {
	forn(i, n) {
		if (s[i] == 'a' || s[i] == 'b') {
			int c = s[i] - 'a';
			poses[c ^ (i & 1)][i] = 1;
		}
	}

	forn(j, 2) {
		forn(i, n) {
			pref[j][i + 1] = pref[j][i] + poses[j][i];
		}
	}

	forn(i, n) {
		sum[i + 1] = sum[i] + (s[i] == '?');
	}

	forn(i, N) {
		z[i] = mp(0, 0);
	}

	forn(i, n) {
		z[i + 1] = max(z[i + 1], z[i]);

		if (i + m <= n && pref[1 - (i & 1)][i + m] - pref[1 - (i & 1)][i] == 0) {
			int cnt = sum[i + m] - sum[i];
			z[i + m] = max(z[i + m], mp(z[i].X + 1, z[i].Y - cnt));
		}
	}

	cout << -z[n].Y << endl;
}

//#define FILES

int main() {
#ifdef AR
	assert(freopen("input.txt", "rt", stdin));
	assert(freopen("output.txt", "wt", stdout));
#else
#ifdef FILES
	assert(freopen(".in", "rt", stdin));
	assert(freopen(".out", "wt", stdout));
#endif
#endif

	srand(time(NULL));

	cout << setprecision(10) << fixed;
	cerr << setprecision(10) << fixed;

	read();
	solve();

#ifdef AR
	cerr << "Time: " << clock() << endl;
#endif
	return 0;
}