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

int l[128];
int r[128];

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, p1, p2, p3, t1, t2;
    scanf ("%d%d%d%d%d%d", &n, &p1, &p2, &p3, &t1, &t2);
    long long res = 0;
    REP (i, n) {
        scanf ("%d%d", l+i, r+i);
        res += (r[i]-l[i]) * p1;
        if (i) {
            int T = l[i] - r[i-1];
            res += min (T, t1) * p1;
            if (T > t1) {
                res += min (T - t1, t2) * p2; 
                if (T > t1+t2)
                    res += (T-t1-t2) * p3;
            }
        }
    }
    cout << res << endl;
	return 0;
}