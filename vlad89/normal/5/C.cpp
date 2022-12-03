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

char s[1234567];
int res[1234567];

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    gets (s);
    int n = strlen (s);
    VI st;
    int x = 0;
    int y = 1;
    REP (i, n)
    {
        if (s[i] == '(')
        {
            st.pb (i);
        }
        if (s[i] == ')')
        {
            if (!SZ (st)) continue;
            int z = i - st.back() + 1 + (st.back() ? res[st.back()-1] : 0);
            
            if (z > x)
            {
                x = z;
                y = 1;
            } else
            if (z == x)
                ++y;
            res[i] = z;
            st.pop_back();
        }
    }
    cout << x << ' ' << y << endl;
	return 0;
}