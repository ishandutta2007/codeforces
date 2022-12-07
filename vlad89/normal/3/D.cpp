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
#include <memory.h>
#include <cmath>
#include <list>
#include <cstring>

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

char s[65536];
char t[65536];
VPII a;

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf ("%s", s);
    n = strlen (s);
    int m = 0;
    REP (i, n)
        if (s[i] == '?')
            ++m;
    a.resize (m);
    REP (i, m)
        scanf ("%d%d", &a[i].X, &a[i].Y);
    int j = 0;
    int open = 0;
    priority_queue <PII, VPII, greater <PII> > pp;
    REP (i, n)
    {
        if (s[i] == '?')
        {
            if (a[j].X < a[j].Y)
                t[i] = '(';
            else
            {
                t[i] = ')';
                pp.push (PII (a[j].X - a[j].Y, i));
            }
            ++j;          
        } else
            t[i] = s[i];
        if (t[i] == '(') open++; else open--;
        if (open < 0)
        {
            if (!SZ (pp))
            {
                cout << -1 << endl;
                return 0;
            }
            t[pp.top().Y] = '(';
            pp.pop();
            open += 2;
        } 
    }
    VI st;
    REP (i, n)
    {
        if (t[i] == '(')
            st.pb (i);
        else
            st.pop_back();
    }   
    set <int> ss; 
    REP (i, SZ (st))
        ss.insert (st[i]);
    vector <PII> gg;
    j = 0;
    REP (i, n)
    {
        if (t[i] == '(' && s[i] == '?')
            gg.pb (PII (a[j].Y - a[j].X, i));
        if (s[i] == '?')
            ++j;
    }    
    SORT (gg);
    REP (i, SZ (gg))
    {
        set <int>::iterator it = ss.lower_bound (gg[i].Y);
        if (it == ss.begin())
            continue;
        if (*it != gg[i].Y)
            --it;
        if (it != ss.begin())
        {
            t[gg[i].Y] = ')';
            int v1 = *it;
            --it;
            int v2 = *it;
            ss.erase (v1);
            ss.erase (v2);
        }
    }
    if (SZ (ss))
    {
        cout << -1 << endl;
        return 0;
    }
    long long res = 0;
    j = 0;
    REP (i, n)
        if (s[i] == '?')
        {
            if (t[i] == '(')
                res += a[j].X;
            else
                res += a[j].Y;
            ++j;
        }
    cout << res << endl;
    puts (t);
	return 0;
}