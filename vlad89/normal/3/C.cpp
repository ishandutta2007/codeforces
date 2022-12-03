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

bool win (vector <string> a)
{
    REP (i, 3)
    {
        if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != '.') return true;        
        if (a[0][i] == a[1][i] && a[1][i] == a[2][i] && a[0][i] != '.') return true;        
    }    
    if (a[0][0] == a[1][1] && a[1][1] == a[2][2] && a[0][0] != '.') return true;
    if (a[0][2] == a[1][1] && a[2][0] == a[1][1] && a[0][2] != '.') return true;
    return false;
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector <string> a (3);
    cin >> a[0] >> a[1] >> a[2];
    
    int x = 0, o = 0;
    REP (i, 3) REP (j, 3)
        if (a[i][j] == 'X')
            x++;
        else
            if (a[i][j] == '0')
                o++;
    if (x == o)
    {
        if (!win (a)) cout << "first\n";
        else
        {
            bool ok = false;
            REP (i, 3) REP (j, 3)
                if (a[i][j] == '0')
                {
                    vector <string> b = a;
                    b[i][j] = '.';
                    if (!win (b))
                        ok = true;
                }
            if (ok)
                cout << "the second player won\n";
            else
                cout << "illegal\n";
        }
    } else
    if (x == o+1)
    {
        if (!win (a))
        {
            if (x+o == 9)
                cout << "draw\n";
            else
                cout << "second\n";            
        } else
        {
            bool ok = false;
            REP (i, 3) REP (j, 3)
                if (a[i][j] == 'X')
                {
                    vector <string> b = a;
                    b[i][j] = '.';
                    if (!win (b))
                        ok = true;
                }
            if (ok)
                cout << "the first player won\n";
            else
                cout << "illegal\n";            
        }
    } else
        cout << "illegal\n";
	return 0;
}