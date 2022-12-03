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

const int mod = 1000000007;

int d[5001][5001];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    string s, t;
    cin >> s;
    cin >> t;
    int n = sz(s);
    int m = sz(t);
    REP (i, n) {
	d[i][0] = 1;
    }
    int res = 0;
    REP (i, n) {
	REP (j, m) {
	    d[i][j+1] += d[i][j];
	    if (d[i][j+1] >= mod) d[i][j+1] -= mod;

	    if (s[i] == t[j]) {
		d[i+1][j+1] += d[i][j];
		if (d[i+1][j+1] >= mod) d[i+1][j+1] -= mod;
		res += d[i+1][j+1];
		if (res >= mod) res -= mod;
	    }
	}
    }
    cout << res << endl;
    return 0;
}