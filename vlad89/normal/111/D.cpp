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

const int mod = 1000000007;
int fact[1000001];

ll mul(ll x, ll y) {
    return (x * y) % mod;
}

ll inverse(ll a, ll n = mod) {
    ll x = 1, y = 0, b = n, k;
    for (;b; swap(x, y), swap(a, b)) {
        k = a / b;
        a -= b * k;
        x -= y * k;
    }
    return x < 0 ? x + n : x;
}

int cnk(int n, int k) {
    if (k > n) return 0;
    return mul(fact[n], inverse(mul(fact[k], fact[n-k])));
}

int d[1024][1024];

int qpow(int a, int n) {
    int r = 1;
    while (n) {
        if (n & 1) {
            r = mul(r, a);            
        }
        a = mul(a, a);
        n /= 2;
    }
    return r;
}

int n, m, k;

int a[32][32];

int rec(int y, int x) {
    if (y == n) {
        FOR (j, 1, m) {
            set<int> Q, W;
            REP (y, n) REP (x, m) {
                if (x < j) Q.insert(a[y][x]); else W.insert(a[y][x]);                
            }
            if (sz(Q) != sz(W))
                return 0;
        }
/*        REP (i, n) {
            REP (j, m)
            cout << a[i][j];
            cout << endl;
        }
            cout << endl;*/
        return 1;
    }
    int res = 0;
    for (int i = 1; i <= k; ++i) {
        a[y][x] = i;
        res += rec(y + (x+1) / m, (x+1) % m);
    }
    return res;
}

int main () {
    #ifdef LOCAL
    	freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    d[0][0] = 1;
    REP (i, 1023) REP (j, 1023) {
        d[i+1][j] = (d[i+1][j] + mul(d[i][j], j)) % mod;
        d[i+1][j+1] = (d[i+1][j+1] + d[i][j]) % mod;
    }
    fact[0] = 1;
    FOR (i, 1, 1000001)
        fact[i] = mul(fact[i-1], i);    
    cin >> n >> m >> k;
    ll res = 0;
    if (m == 1) {
        res = qpow(k, n);        
    } else {
        FOR (p, 1, min (n, k) + 1) {
            int val = 1;
            val = mul(val, d[n][p]);
            val = mul(val, fact[p]);                
            val = mul(val, val);
            REP (c, p+1) {     
                if (k < c + 2 * (p-c)) continue;                
                int add = val; 
                add = mul(add, qpow(c, n * (m-2)));
                
                add = mul(add, cnk(k, c));
                add = mul(add, cnk(k-c, p-c));
                add = mul(add, cnk(k-c - (p-c), p-c));
                res = (res + add) % mod;
            }
        }
    }
    cout << res << endl;
//    cout << rec(0, 0) << endl;
    return 0;
}