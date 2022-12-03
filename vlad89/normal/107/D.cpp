#include <cstring>
#include <memory.h>
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

const int N = 128;
const int C = 1024;

vector<int> b[26];
int prod[26];
int p[26];

void decode(int code, int a[26]) {
    REP (i, 26) {
        a[i] = code % prod[i];
        code /= prod[i];
    }
}

int encode(int a[26]) {
    int code = 0;
    for (int i = 25; i >= 0; --i)
        code = code * prod[i] + a[i];
    return code;
}

const int mod = 12345;

int d[N][N];
int m;

void mult(int a[N][N], int b[N][N], int c[N][N]) {
    memset(d, 0, sizeof (d));
    REP (k, m) REP (i, m) REP (j, m) {
        d[i][j] += a[i][k] * b[k][j];
        d[i][j] %= mod;
    }
    memcpy(c, d, sizeof (d));
}

int a[N][N], res[N][N];

int main () {
    #ifdef LOCAL
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif    
    long long n;
    int c;
    cin >> n >> c;    
    REP (i, c) {
        char ch;
        int x;
        cin >> ch >> x;
        b[ch-'A'].pb(x);
    }
    m = 1;
    REP (i, 26) {
        prod[i] = 1;
        REP (j, sz (b[i])) {
            m *= b[i][j];
            prod[i] *= b[i][j];
        }
    }
    REP (i, m)
        REP (j, 26) if (sz(b[j])) {
            decode(i, p);            
            p[j]++;
            p[j] %= prod[j];
            int code = encode(p);
            a[i][code]++;
        }
    REP (i, m) res[i][i] = 1;
    while (n) {
        if (n & 1) 
            mult(res, a, res);
        mult(a, a, a);
        n /= 2;
    }
    int ans = 0;
    REP (i, m) {
        decode(i, p);
        bool bad = false;
        REP (j, 26) if (sz(b[j])) {
            bool ok = false;
            REP (k, sz (b[j]))
                if (p[j] % b[j][k] == 0) {
                    ok = true;
                    break;
                }
            if (!ok) {
                bad = true;
                break;
            }
        }            
        if (!bad) {
            ans += res[0][i];
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}