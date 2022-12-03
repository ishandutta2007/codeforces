#define _CRT_SECURE_NO_DEPRECATE
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <numeric>
#include <cstdlib>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#include <list>
#include <set>
#include <map>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) SORT(a),(a).resize(unique(all(a))-a.begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset (a, b, sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

const int N = 123456;
const int inf = -1u/4;
int n, m;
int a[N], b[N];
int eaten[N];
int count_eaten[N];
bool hz[N];

int d[N][2];

pii add (pii x, pii y) {
    if (x.X == y.X) return pii (x.X, x.Y+y.Y);
    if (x.X < y.X) return x;
    return y;    
}

int eat (int x) {
    return count_eaten[x];
}

int eat (int x, int y) {
    return add (pii (eaten[x], count_eaten[x]), pii (y, 1)).Y;
}

int eat (int x, int y, int z) {
    return add (add (pii (eaten[x], count_eaten[x]), pii (y, 1)), pii (z, 1)).Y;
}

int main() {
    #ifdef LocalHost
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int hernya1, hernya2;
    scanf ("%d%d%d%d", &m, &n, &hernya1, &hernya2);
    int M = m;
    REP (i, m) {
        scanf ("%d", b+i);        
    }
    REP (i, n) {
        scanf ("%d", a+i);
        eaten[i] = inf;
    }        
    int j = 0;
    int x1, x2, y;
    int i = 0;
    REP (ii, m) {
        b[i] = b[ii];
        while (j < n && a[j] < b[i]) ++j;
        x1 = j == 0 ? inf : b[i] - a[j-1];
        x2 = j == n ? inf : a[j] - b[i];
        if (x1 != x2) {
            if (x1 < x2)
                y = j-1; 
            else
                y = j;
            int x = min(x1, x2);
            if (x < eaten[y]) {
                eaten[y] = x;
                count_eaten[y] = 1;
            } else
            if (x == eaten[y])
                count_eaten[y]++;
        } else {
            ++i;
            hz[j] = hz[j-1] = true;
        }
    }        
    m = i;
        
    int ans = 0;
    REP (i, n)
        if (!hz[i])
            ans += count_eaten[i];
    j = 0;    
    int pj, px;    
    REP (i, m) {
        while (j < n && a[j] < b[i]) ++j;
        int x = b[i] - a[j-1];
        
        if (i) {
            if (j-1 != pj) {
                int past = max (d[i][0] + eat (pj), d[i][1] + eat (pj, px));
                d[i+1][0] = past + eat (j-1, x);
                d[i+1][1] = past + eat (j-1);
            } else {
                d[i+1][0] = max (d[i][0] + eat (pj, x), d[i][1] + eat (pj, x, px));
                d[i+1][1] = max (d[i][0] + eat (pj), d[i][1] + eat (pj, px));                
            }            
        } else {
            d[1][0] = ans + eat (j-1, x);
            d[1][1] = ans + eat (j-1);
        }
        pj = j;        
        px = x;
    }
    if (m == 0) {
        cout << M-ans << endl;        
    } else {
        cout << M-max (d[m][0] + eat (pj), d[m][1] + eat (pj, px)) << endl;
    }
    return 0;
}