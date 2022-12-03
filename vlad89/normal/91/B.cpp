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

int n;
int a[123456];
int b[123456];

const int INF = 1000000001;
template<int N>
struct Minimizator {
    int a[N + 1], l[N + 1], r[N + 1];
    int n;
    #define PREV(x) (x & (x - 1))
    #define NEXT(X) ((x << 1) - PREV(x))
    int getMin(int q, int w) {
        if (q > w) return INF;
        q++;    w++;
        static int x, v;
        v = INF;
        for(x = q; NEXT(x) <= w;x = NEXT(x)) v = min (v,  r[x]);
        v = min (v, a[x]);
        for(x = w; PREV(x) >= q;x = PREV(x)) v = min (v,  l[x]);        
        return v;
    }
    void modify(int p,int v) {
        p++;
        static int x;
        a[p] = min (a[p], v);
        for(x = p; x <= n; x = NEXT(x)) l[x] = min (l[x], v);
        for(x = p; x; x = PREV(x)) r[x] = min (r[x], v);        
    }
    void init(int _n) {
        n = _n;
        REP(i, n + 1) {        
            a[i] = l[i] = r[i] = INF;
        }
    }
};

Minimizator<123456> mi;

int res[123456];

int main () {
    #ifdef LOCAL
    	freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    scanf ("%d", &n);
    REP (i, n) {
        scanf ("%d", &a[i]);
        b[i] = a[i];
    }
    sort(b, b + n);
    int m = unique(b, b + n) - b;
    mi.init(m);
    for (int i = n-1; i >= 0; --i) {
        a[i] = lower_bound(b, b+m, a[i])-b;
        int x = mi.getMin(0, a[i]-1);
        if (x == INF)
            res[i] = -1;
        else
            res[i] = -x-i-1;
        mi.modify(a[i], -i);
    }
    REP (i, n) {
        if (i)
            printf(" ");
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}