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
#define DEBUG(x) cout << #x << " = " << x << endl;

#define INF 1000000000

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

ll d[64][64][2][2];

/*void rec (VI know, int x, int y, int c0, int c1, string q, string w) {
    if (x > y) {
        reverse (ALL (w));
        cout << q << w << endl;
        return;
    }
    REP (d1, 2) if (know[x] == -1 || know[x] == d1)
        REP (d2, 2) if (know[y] == -1 || know[y] == d2)
             {
                if (c0 == 0 && d1 > d2) continue;
                if (c1 == 0 && d1 > !d2) continue;
                int n0 = c0;
                int n1 = c1;
                if (d1 < d2)
                    n0 = 1;
                if (d1 < !d2)
                    n1 = 1;
                rec (know, x+1, y-1, n0, n1, q + char ('0' + d1), w + char ('0' + d2));
            }
}*/

ll cc (VI know) {
    memset (d, 0, sizeof (d));
    ll res = 0;
    d[0][SZ (know)-1][0][0] = 1;
    for (int x = 0, y = SZ (know) - 1; x <= y; ++x, --y) {
        REP (d1, 2) if (know[x] == -1 || know[x] == d1)
            REP (d2, 2) if (know[y] == -1 || know[y] == d2)
            {
                if (x == y && d1 != d2) continue;
                REP (c0, 2) REP (c1, 2) {
                    if (c0 == 0 && d1 > d2) continue;
                    if (c1 == 0 && d1 > !d2) continue;
                    int n0 = c0;
                    int n1 = c1;
                    if (d1 < d2)
                        n0 = 1;
                    if (d1 < !d2)
                        n1 = 1;
                    if (x+1 <= y-1)
                        d[x+1][y-1][n0][n1] += d[x][y][c0][c1];
                    else
                        res += d[x][y][c0][c1];
                }
            }
    }
    return res;
}

int main() {
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    ll k;
    cin >> n >> k;
    VI know (n, -1);
    know[0] = 0;
//    rec (know, 0, SZ (know)-1, 0, 0, string(), string());
    ++k;
//    cout << cc (know) << endl;
    if (cc (know) < k) 
        cout << -1 << endl;
    else {
        for (int i = 1; i < SZ (know); ++i) {
            know[i] = 0;
            long long p = cc (know);
            if (p < k) {
                k -= p;
                ++know[i];
            }
        }
        REP (i, SZ (know))
            cout << know[i];
        cout << endl;
    }
    return 0;
}