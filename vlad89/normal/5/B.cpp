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

char s[1024][1024];
char g[1024];

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n = 0;
    int m = 0;
    while (gets (s[n]) != NULL)
    {
        m = max (m, (int)strlen (s[n]));
        ++n;
    }
    REP (i, m+2)
        g[i] = '*';
    puts (g);
    int odd = 0;
    REP (i, n)
    {
        int x = strlen (s[i]);
        printf ("*");
        REP (j, (m-x+odd)/2)
            printf (" ");
        printf ("%s", s[i]);
        REP (j, m - x - (m-x+odd)/2)
            printf (" ");
        if ((m-x) % 2 == 1)
            odd = 1-odd;
        printf ("*\n");
    }
    puts (g);
	return 0;
}