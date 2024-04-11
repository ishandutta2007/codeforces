#include <iostream>
#include <memory.h>
#include <cstdio>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstring>
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

bool a[16000000];

int main() {
    #ifdef LocalHost
    freopen ("input.txt", "r", stdin);
    #endif
    int n, m;
    cin >> n >> m;
    int R = 0;
    long long ans = 0;
    for (int b = 1; b <= n; ++b) {
	int Z = 0;
	for (int x = b-1; (ll)b*b-(ll)x*x <= m && x >= 0; --x) {
	    a[-b+x + 10000000] = true;
	    a[-b-x + 10000000] = true;
	    Z++;
	}
	while (R < m && R+1 <= (long long) b*b)
	    R++;
	ans += 2*(R-Z);
    }
    for (int i = 0; i < 16000000; ++i)
	ans += a[i];
    cout << ans << endl;
    return 0;
}