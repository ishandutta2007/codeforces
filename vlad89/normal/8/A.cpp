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

char s[123456];
char a[128];
char b[128];

int p[128], p2[128];

bool check () {
    p[0] = -1;
    int sa = strlen (a);
    int sb = strlen (b);
    FOR (i, 1, sa)
    {
        p[i] = p[i-1];
        while (p[i] != -1 && a[p[i]+1] != a[i])
            p[i] = p[p[i]];
        if (a[p[i]+1] == a[i])
            p[i]++;
    }       
    
    p2[0] = -1;
    FOR (i, 1, sb)
    {
        p2[i] = p2[i-1];
        while (p2[i] != -1 && b[p2[i]+1] != b[i])
            p2[i] = p2[p2[i]];
        if (b[p2[i]+1] == b[i])
            p2[i]++;
    }       
    
    int n = strlen (s); 
    int x = -1;
    REP (i, n)
    {
        while (x != -1 && a[x+1] != s[i]) x = p[x];
        if (a[x+1] == s[i])
            ++x;
        if (x == sa-1)
        {
            x = -1;
            for (++i; i < n; ++i) {
                while (x != -1 && b[x+1] != s[i]) x = p2[x];
                if (b[x+1] == s[i])
                    ++x;
                if (x == sb-1) 
                    return true;
            }            
            return false;
        }
    }
    return false;
}

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    gets (s);
    gets (a);
    gets (b);
    bool q = check ();
    reverse (s, s + strlen (s));
    bool w = check ();
    if (q && w)
        cout << "both\n";
    if (q && !w)
        cout << "forward\n";
    if (!q && w)
        cout << "backward\n";
    if (!q && !w)
        cout << "fantasy\n";
	return 0;
}