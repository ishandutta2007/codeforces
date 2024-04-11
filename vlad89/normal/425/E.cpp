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

#define ADD(x, y) (((x) + (y)) % mod)
#define SUB(x, y) (((((x) - (y)) % mod) + mod) % mod)
#define MUL(x, y)  ((((long long) (x)) * (y)) % mod)

const int mod = 1000000007;

int d[2][512][512];
int p2[512];

int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
#endif
    int n, k;
    p2[0] = 1;
    FOR (i, 1, 512) {
	p2[i] = MUL(p2[i-1], 2);
    }
    cin >> n >> k;
    d[0][0][0] = 1;
    REP (i, n) {
	int x = i & 1;
	int y = x ^ 1;
	REP (j, i+1) {
	    REP (t, k+1) if (d[x][j][t]) {
		d[y][j][t] = ADD(d[y][j][t], MUL(d[x][j][t], p2[j]));
		d[y][i+1][t+1] = ADD(d[y][i+1][t+1], MUL(d[x][j][t], SUB(p2[i+1], p2[j])));
	    }
	}
	memset(d[x], 0, sizeof(d[x]));
    }
    int res = 0;
    REP (j, n+1) {
	res = ADD(res, d[n&1][j][k]);
    }
    cout << res << endl;
    return 0;
}