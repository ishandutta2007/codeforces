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


int main () {
#ifdef LocalHost
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n, k;
    cin >> n >> k;
    if (k < n / 2 || (n == 1 && k != 0)) {
        cout << -1 << endl;
        return 0;
    }    
    vi res;
    int u = 999999999;
    REP (i, n / 2 - 1) {
        res.pb(u);
        res.pb(u-1);
        u -= 2;
        --k;
    }
    if (n > 1) {
        res.pb(k);
        res.pb(2 * k);
    }
    if (n & 1) res.pb(1000000000);
    REP (i, sz (res)) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << endl;
    return 0;
}