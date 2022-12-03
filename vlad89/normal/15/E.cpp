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

const int mod = 1000000009;
int pow2[1234567];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    pow2[0] = 1;
    FOR (i, 1, 1234567) {
        pow2[i] = pow2[i-1]*2;
        pow2[i] %= mod;
    }
    long long n;
    cin >> n;
    n /= 2;
    if (n == 1) {
        cout << 10 << endl;
        return 0;
    }
    long long res = 0;
    long long now = 0;
    for (int d = n-2; d >= 0; --d) {
        now += 4;
        now = ((now * (pow2[d+2]-3)) % mod + mod) % mod;
    }
    now += 2;
    now *= now;
    now %= mod;
    now *= 2;
    now %= mod;
    now += 2;
    now %= mod;
    cout << now << endl;
    return 0;
}