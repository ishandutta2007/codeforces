#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <cstring>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <utility>
#include <sstream>
#include <set>
#include <time.h>
#include <memory.h>
#include <queue>
#include <bitset>
#include <functional>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define sz(a) ((int) (a).size())
#define pb push_back
#define SORT(x) sort(all(x))
#define UNIQUE(x) SORT(x),(x).resize(unique(all(x))-(x).begin())
#define FOR(i,a,b) for(int i = (a); i < (b); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i, n) FOR(i, 0, n)

#define X first
#define Y second

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<vi> vvi;
typedef long long ll;

const double pi = acos(-1.0);

ll gcd(ll x, ll y) {
	if (x < 0) x = -x;
	if (y < 0) y = -y;
	if (x < y) swap(x, y);
	while (y) {
		ll t = y;
		y = x % y;
		x = t;
	}
	return x;
}

vi a;
int n;
long long d[128][2];

int main () {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif
	string s;
	cin >> s;

	REP (i, sz (s))
		a.pb(s[i]-'A');
	n = sz(a);

	long long res = 0;
	REP (i, 2) {
		memset(d, 0, sizeof(d));
		d[0][i] = 1;		
		if (a[0] == 0 && i == 1) {
			d[1][0] = 1;
			d[1][1] = 1;
		}
		REP (j, n) REP (v, 2) {
			int k = (j+1)%n;
			if (v == 0 && a[j] == 0) d[j+1][0] += d[j][v];
			if (v == 0 && a[j] == 1 && a[k] == 0) { d[j+2][0] += d[j][v]; d[j+2][1] += d[j][v]; }
			if (v == 1 && a[j] == 1) { d[j+1][0] += d[j][v]; d[j+1][1] += d[j][v]; }
		}

		if (a[0] == 0 && i == 1)
			res += d[n+1][0];
		else
			res += d[n][i];			
	}

	cout << res << endl;
#ifdef LocalHost
	cout << "--FINISHED--" << endl;
	while (1);
#endif
	return 0;
}