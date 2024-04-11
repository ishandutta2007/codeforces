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

int x[24];
int y[24];
int d[1<<24];
int from[1<<24][2];
int f2[24][24];
int f1[24];

int dist (int x1, int y1, int x2, int y2) {
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int x0, y0;
    int n;
    scanf ("%d%d", &x0, &y0);
    scanf ("%d", &n);
    REP (i, n) 
        scanf ("%d%d", x+i, y+i);    
    REP (i, 1<<n) d[i] = INF;
    REP (i, n) REP (j, n)
        f2[i][j] = dist (x0, y0, x[i], y[i]) + dist (x[i], y[i], x[j], y[j]) + dist (x[j], y[j], x0, y0);
    REP (i, n)
        f1[i] = 2*dist (x0, y0, x[i], y[i]);
    int j, k;
    d[0] = 0;
    REP (i, (1<<n)-1) if (d[i]<INF) {
        j = 0;
        while (i & (1<<j)) ++j;
        if (d[i|(1<<j)] > d[i] + f1[j]) {
            d[i|(1<<j)] = d[i] + f1[j];
            from[i|(1<<j)][0] = j;
            from[i|(1<<j)][1] = j;
        }
        
        for (k = j+1; k < n; ++k)
            if (!(i & (1<<k)))
                if (d[i|(1<<j)|(1<<k)] > d[i] + f2[j][k]) {
                    d[i|(1<<j)|(1<<k)] = d[i] + f2[j][k];
                    from[i|(1<<j)|(1<<k)][0] = j;
                    from[i|(1<<j)|(1<<k)][1] = k;                    
                }        
    }
    printf ("%d\n", d[(1<<n)-1]);
    int x = (1<<n)-1;
    VI res;
    while (x) {
        res.pb (0);
        res.pb (from[x][0]+1);
        if (from[x][1] != from[x][0])
        {
            res.pb (from[x][1]+1);                        
            x = x^(1<<from[x][0])^(1<<from[x][1]);
        } else
            x = x^(1<<from[x][0]);
    }
    res.pb (0);
    REP (i, SZ (res)) {
        if (i)
            printf (" ");
        printf ("%d", res[i]);
    }
    printf ("\n");
	return 0;
}