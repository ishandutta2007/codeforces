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

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int n, m, y1, x1, y2, x2, y3, x3, y4, x4;
    while (t--) {
        cin >> n >> m >> y1 >> x1 >> y2 >> x2;
        y2 -= y1;
        x2 -= x1;
        y2 = abs (y2);
        x2 = abs (x2);
        
        int y = y2+1;
        int x = x2+1;
        
        x1 = 0, y1 = 0;
        y2 = n-y; x2 = m-x;
        
        y3 = y-1; x3 = x-1;
        y4 = n-1; x4 = m-1;
        
        long long ans = (long long) (y2-y1+1) * (x2-x1+1) + (long long) (y4-y3+1) * (x4-x3+1);
        if (x2 >= x3 && y2 >= y3) 
            ans -= (long long) (x2-x3+1) * (y2-y3+1);
        cout << ((long long) n*m - ans) << endl;
    }
    return 0;
}