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

pii a[1024];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, t;
    cin >> n >> t;
    t *= 2;
    set <int> pos;
    REP (i, n) {
        cin >> a[i].X >> a[i].Y;
        a[i].X *= 2;
        a[i].Y *= 2;
        a[i].X -= a[i].Y / 2;
        pos.insert (a[i].X - t);
        pos.insert (a[i].X + a[i].Y);
    }
    int ans = 0;
    FORE (it, pos) {
        int x = *it;
        bool ok = true;
        REP (i, n)
            if (max (x, a[i].X) < min (x + t, a[i].X + a[i].Y)) {
                ok = false;
                break;
            }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}