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

int a[128][128];
int far[128][128][128];
int Sum[128][128];

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k;
    scanf ("%d%d", &n, &k);
    int y = k/2;
    int x = k/2;
    REP (i, k)
        REP (j, k) {
            far[i][j][0] = 0;
            FOR (q, 1, k + 1)
                far[i][j][q] = far[i][j][q-1] + abs (i-y) + abs (j+q-1-x);
        }
    
    REP (i, n) {
        int m;
        scanf ("%d", &m);
        int res = INF;
        int ry, rx;
        REP (q, k)
            REP (w, k-m+1)
                if (Sum[q][w+m] == Sum[q][w]) {
                    if (far[q][w][m] < res) {
                        res = far[q][w][m];
                        ry = q;
                        rx = w;
                    }
                }
        if (res == INF) {
            puts ("-1");
            continue;
        }
        REP (w, m)
            a[ry][rx+w] = 1;
        REP (w, k)
            Sum[ry][w+1] = Sum[ry][w] + a[ry][w];
        printf ("%d %d %d\n", ry+1, rx+1, rx+m);
    }
	return 0;
}