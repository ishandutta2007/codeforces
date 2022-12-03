#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

pii a[512], b[512];
int d[512][512];

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    scanf ("%d%d", &n, &m);
    REP (i, n) scanf ("%d%d", &a[i].X, &a[i].Y);
    REP (i, m) scanf ("%d%d", &b[i].X, &b[i].Y);
    REP (i, n) REP (j, n) if (a[i].X < a[j].X) {
        int c = 0;
        REP (k, m)
            if (b[k].X >= a[i].X && b[k].X < a[j].X) 
                if ((long long) (b[k].Y - a[i].Y) * (a[j].X - a[i].X) < (long long) (b[k].X - a[i].X) * (a[j].Y - a[i].Y))
                    ++c;
        d[i][j] = c;
        d[j][i] = -c;
    }
    int res = 0;
    REP (i, n) REP (j, i) REP (k, j) 
        res += (d[i][j] + d[j][k] + d[k][i] == 0);
    cout << res << endl;
	return 0;
}