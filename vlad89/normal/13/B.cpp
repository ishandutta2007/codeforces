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
typedef pair<int, int> pii;
typedef vector<pii> VPII;
typedef long long ll;

pii p[3][2];

pii operator - (pii a, pii b) { return pii (a.X - b.X, a.Y - b.Y); }
long long operator % (pii a, pii b) { return (long long) a.X * b.Y - (long long) a.Y * b.X; }

bool belong (pii x, pii a, pii b) {
    return (x-a) % (b-a) == 0;
}
long long sqr (long long x) { return x*x; }
long long dist (pii a, pii b) { return sqr (a.X-b.X) + sqr (a.Y-b.Y); }
bool good (pii a, pii b) {
    long long A = sqr (a.X) + sqr(a.Y);
    long long B = sqr (b.X) + sqr(b.Y);
    long long C = sqr (a.X-b.X) + sqr (a.Y-b.Y);
    return C <= A+B && (a%b);
}

bool check (pii x, pii a, pii b) {
    if (!belong (x, a, b)) return false;
    if (x.X < min (a.X, b.X) || x.X > max (a.X, b.X)) return false;
    if (x.Y < min (a.Y, b.Y) || x.Y > max (a.Y, b.Y)) return false;
    long long d1 = dist (x, a);
    long long d2 = dist (x, b);
    if (d2 < d1) swap (d1, d2);
    return d1*16>=d2;
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf ("%d", &n);
    REP (test, n) {
        REP (i, 3)
            scanf ("%d%d%d%d", &p[i][0].X, &p[i][0].Y, &p[i][1].X, &p[i][1].Y);
        bool ans = false;
        REP (q, 3) REP (w, 3) REP (e, 3) if (q != w && q != e && w != e) 
        {
            bool ok = false;
            REP (f, 2) REP (s, 2) if (p[q][f] == p[w][s]) {
                swap (p[q][0], p[q][f]);
                swap (p[w][0], p[w][s]);
                ok = true;
            }        
            if (!ok) continue;
            if (!good (p[q][1]-p[q][0], p[w][1]-p[w][0])) continue;           
            if (belong (p[e][1], p[q][0], p[q][1])) swap (p[e][0], p[e][1]);
            
            if (check (p[e][0], p[q][0], p[q][1]) && check (p[e][1], p[w][0], p[w][1])) 
                ans = true;
        }
        puts (ans ? "YES":"NO");
    }
	return 0;
}