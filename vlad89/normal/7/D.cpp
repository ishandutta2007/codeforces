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

char str[5000001];
int a[10000001];
int d[10000001];
long long res;

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    gets (str);
    int n = strlen (str), i = 0;
    int p = 0;
    int m = 0;
    int s, e, d;
    bool ok;
    while (i < n)
    {
        if (i > p && str[i-p-1] == str[i])
        {
            p += 2;
            ++i;
            continue;
        }
        a[m++] = p;
        s = m-2;
        e = s-p;
        bool ok = false;
        FORD (j, s, e+1)
        {
            d = j-e-1;
            if (a[j] == d)
            {
                p = d;
                ok = true;
                break;
            }
            a[m++] = min (d, a[j]);
        }
        if (!ok)
        {
            p = 1;
            ++i;
        }        
    }
    a[m++] = p;
    s = m-2;
    e = s - (2 * n + 1 - m);
    FORD (x, s, e+1)
    {
        d = i-e-1;
        a[m++] = min (d, a[x]);
    }
    REP (i, n)
    {
        a[i] = 0;
        if (a[i+1] == i+1)       
            a[i] = (i == 0 ? 1 : 1 + a[(i-1)/2]);
        res += a[i];
    }
    cout << res << endl;
	return 0;
}