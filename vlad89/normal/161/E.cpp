#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

vector<int> a[100000][6];

bool pr[100000];

int b[6][6];
int d[6];
int n;
int res;

void rec(int x) {
    if (x == n) {
	++res;
	return;
    }
    REP (i, sz (a[d[x]][n-x])) {
	int g = a[d[x]][n-x][i];
	bool good = true;
	for (int j = n-1; j > x; --j) {
	    d[j] = d[j] * 10 + g % 10;
	    if (!sz(a[d[j]][n-x-1]))
		good = false;
	    g /= 10;
	}
	if (good) rec(x+1);
	for (int j = n-1; j > x; --j) {
	    d[j] /= 10;
	}
    }
}

int main () {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);
#endif
    FOR (i, 2, 100000) if (!pr[i]) {
	for (int j = 2; i * j< 100000; ++j) {
	    pr[i*j] = true;
	}
	for (int d = 10000, num = 4; num >= 0; d /= 10, num--) {
	    a[i / d][num].pb(i);
	}
    }
    int t;
    cin >> t;
    REP (i, t) {
       string p;
       cin >> p;
       REP (j, sz (p))
	   d[j] = p[j]-'0';
       n = sz (p);
       res = 0;
       rec(1);
       cout << res << endl;
    }
    return 0;
}