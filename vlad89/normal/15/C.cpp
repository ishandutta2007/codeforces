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

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

long long res;
long long ans;
int bits[64];

void process (long long n) {
    int m = 0;
    long long x = n;
    while (n) {
        bits[m] = n & 1;
        n /= 2;
        ++m;
    }
    long long after = 0;
    long long before;
    REP (i, m) {
        before = x>>(i+1LL);        
        if (((before * (1LL<<i)) + bits[i] * (after+1)) & 1)
            res ^= 1LL<<i;
        after += (1LL<<i) * bits[i];
    }
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    scanf ("%d", &n);
    REP (i, n) {
        long long q, w;
        cin >> w >> q;
//        for (long long j = w; j < q+w; ++j)
//            ans ^= j;
        process (w+q-1);
        process (w-1);
    }
//    cout << res << endl;
//    cout << ans << endl;
    if (res)
        puts ("tolik"); else puts ("bolik");
    return 0;
}