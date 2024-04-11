#include <iostream>
#include <cstdio>
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

int a[1100000];
VI b;

int count_less_eq (VI::iterator b, VI::iterator e, int x)
{
    VI::iterator it = lower_bound (b, e, x, greater <int> ());
    if (it == e) return 0;
    if (*it > x) ++it;
    return e-it;
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf ("%d", &n);
    int ma = 0;
    REP (i, n)
    {
        scanf ("%d", &a[i]);
        ma = max (ma, a[i]);
        while (SZ (b) && b.back() < a[i]) b.pop_back();
        b.pb (a[i]);            
    }
    long long cma = count (a, a + n, ma);
    long long res = 0;    
    if (cma > 1)
    {
        res -= cma * (cma-1)/2;
    } else
    {
        int ma2 = 0;
        REP (i, n) 
            if (a[i] != ma)
                ma2 = max (ma2, a[i]);
        long long cma2 = count (a, a + n, ma2);
        res -= cma2;
    }
    int it = 0;
    REP (i, n)
    {
        if (it != SZ (b) && b[it] == a[i])
            ++it;
            
        res += count_less_eq (b.begin() + it, b.end(), a[i]);        
        while (SZ (b) != it && b.back() < a[i]) b.pop_back();
        b.pb (a[i]);            
    }
    reverse (a, a + n);    
    b.clear();
    it = 0;
    
    REP (i, n)
    {
        while (SZ (b) && b.back() < a[i]) b.pop_back();
        b.pb (a[i]);            
    }
    
    REP (i, n)
    {
        if (it != SZ(b) && b[it] == a[i])
            ++it;
        
        res += count_less_eq (b.begin() + it, b.end(), a[i]-1);        
        while (SZ (b) != it && b.back() < a[i]) b.pop_back();
        b.pb (a[i]);            
    }    
    cout << res << endl;
	return 0;
}