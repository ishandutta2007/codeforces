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

int a[128];
int al;

int main() {
    #ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t, m;
    cin >> t >> m;
    string oper;
    
    REP (i, t)
    {
        cin >> oper;
        if (oper[0] == 'd')
        {
            int k = 0;
            REP (j, m)
                if (a[j])
                {
                    if (k != j)
                    {
                        a[k] = a[j];
                        a[j] = 0;
                    }
                    ++k;
                }
        } else
        if (oper[0] == 'a')
        {
            int size;
            cin >> size;
            REP (j, m)
            {
                bool ok = true;
                REP (t, size)
                    if (j + t >= m || a[j+t])
                    {
                        ok = false;
                        break;
                    }
                if (ok)
                {
                    ++al;
                    cout << al << endl;
                    REP (t, size)
                        a[j+t] = al;
                    goto next;
                }     
            }         
            cout << "NULL\n";
        } else
        {
            int num;
            cin >> num;
            bool ok = false;
            if (num > 0)
            {
                REP (j, m)
                    if (a[j] == num)
                    {
                        a[j] = 0;
                        ok = true;
                    }
            }
            if (!ok)
                cout << "ILLEGAL_ERASE_ARGUMENT\n";
        }
next:;
    }
	return 0;
}