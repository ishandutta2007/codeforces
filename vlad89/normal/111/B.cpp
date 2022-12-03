#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

vector<pii> add[123456];
vector<int> d[123456];
int res[123456];
int x[123456];
int y[123456];

int main () {
    #ifdef LOCAL
    	freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    scanf ("%d", &n);
    REP (i, n) {
        scanf ("%d%d", &x[i], &y[i]);
        for (int j = 1; j * j <= x[i]; ++j) {
            if (x[i] % j == 0) {
                d[i].pb(j);
                if (x[i] != j*j)
                    d[i].pb(x[i] / j);
            }
        }
        REP (j, sz (d[i]))
            add[i - y[i]].pb(pii(d[i][j], i));
        
        res[i] = sz(d[i]);
    }
    set<pii> mp;
    REP (i, n) {
        REP (j, sz(add[i]))
            mp.insert(add[i][j]);
        REP (j, sz(d[i]))
            mp.erase(pii(d[i][j], i));
            
        REP (j, sz(d[i])) {
            set<pii>::iterator it1 = mp.lower_bound(pii (d[i][j], -1));
            set<pii>::iterator it2 = it1;
            while (it2 != mp.end() && it2->X == d[i][j]) {                
                res[it2->Y]--;
                ++it2;
            }
            mp.erase(it1, it2);
        }
    }
    REP (i, n)
        printf("%d\n", res[i]);
    return 0;
}