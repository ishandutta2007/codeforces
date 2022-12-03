#include <iostream>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <sstream>
#include <vector>
#include <stack>
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
#define all(a) (a).begin(),(a).end()
#define UNIQUE(a) sort(ALL(a)),(a).resize(unique(ALL(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back

#define X first
#define Y second

typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef long long ll;

int n, x, y;
int ans[123456];

int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf ("%d", &n);
    scanf ("%d%d", &x, &y);
    vpii a;
    int v;
    REP (i, n) {
        scanf ("%d", &v);
        a.pb(pii (v, i));
    }
    if (x > y) {
        sort (all (a));        
        FOR (i, x, sz(a))
            ans[a[i].Y] = 1;        
    }        
    if (x < y) {
        REP (i, sz (a))
            a[i].Y = -a[i].Y;
        sort(all(a));
        REP (i, y)
            ans[-a[i].Y] = 1;
    }
    if (x == y) {
        FOR (i, n/2, n)
            ans[i] = 1;
    }
    REP (i, n) {
        if (i)
            printf (" ");
        printf ("%d", ans[i]+1);
    }
    puts("");
	return 0;
}