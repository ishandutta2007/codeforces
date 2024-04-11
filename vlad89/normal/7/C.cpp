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

void egcd(ll n, ll m, ll& x, ll& y, ll& d) {       
    ll x1 = 0, y1 = 1, x2 = 1, y2 = 0, q, r;
    while (m) {
        q = n / m; r = n % m; 
        x = x2 - q * x1;
        y = y2 - q * y1;
        n = m; m = r; x2 = x1; x1 = x; y2 = y1; y1 = y;
    }
    x = x2, y = y2, d = n;
}
bool dioph (ll a, ll b, ll c, ll & x, ll & y, ll & d)
{
    egcd (a, b, x, y, d);
    if (c % d ) return false;
    x *= c / d; y *= c / d;
    return true;
} 

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll a, b, c;
    cin >> a >> b >> c;
    c = -c;
    ll x, y, tmp;
    if (!dioph (a, b, c, x, y, tmp))
        cout << -1 << endl;
    else
        cout << x << ' ' << y << endl;
	return 0;
}