#include <iostream>
#include <cstdio>
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

vector <PII> a[2];
int sum [100001];

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, v;
    scanf ("%d%d", &n, &v);
    int q, w;
    REP (i, n)
    {
        scanf ("%d%d", &q, &w);
        a[q-1].pb (PII (w, i));
    }
    SORT(a[0]);
    SORT (a[1]);
    reverse (ALL (a[0]));
    reverse (ALL (a[1]));
    
    REP (i, SZ (a[1]))
        sum[i+1] = sum[i] + a[1][i].X;

    int best = 0;
    int take1 = 0;
    int take2 = 0;
    int cur = 0;    
    REP (i, SZ (a[0])+1)
    {
        if (i > v)
            break;
        int res = cur + sum[min ((v-i)/2, SZ (a[1]))];
        if (res > best)
        {
            best = res;
            take1 = i;
            take2 = min ((v-i)/2, SZ (a[1]));
        }
        if (i != SZ (a[0]))
            cur += a[0][i].X;
    }
    printf ("%d\n", best);
    bool first = true;
    REP (i, take1)
    {
        if (!first)
            printf (" ");
        first = false;
        printf ("%d", a[0][i].Y+1);
    }
    REP (i, take2)
    {
        if (!first)
            printf (" ");
        first = false;
        printf ("%d", a[1][i].Y+1);
    }    
    printf ("\n");
	return 0;
}