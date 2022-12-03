#include <iostream>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <vector>
#include <stack>
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
#define INFLL 1000000000000000000LL

typedef vector<int> VI;
typedef vector< vector<int> > VVI;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long ll;

int v;

int a[5];

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf("%d", &n);
    REP (i, n) {
        scanf("%d", &v);
        a[v]++;
    }
    int res = a[4];
    int g = min(a[1], a[3]);
    res += g;
    a[1] -= g;
    a[3] -= g;    
    res += a[3];
    res += a[2] / 2;
    a[2] %= 2;
    if (a[2]) {
        res++;
        a[1] = max(0, a[1] - 2);
    }
    res += (a[1] + 3) / 4;
    cout << res << endl;
	return 0;
}