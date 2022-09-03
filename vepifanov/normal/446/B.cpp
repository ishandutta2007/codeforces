#include <cstdio>
#include <numeric>
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
#include <string>
#include <map>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <bitset>
#include <queue>
#include <sstream>
#include <deque>
#include <cassert>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }

int n;
int m;
int k, p;
ll row[1000];
ll col[1000];
ll sumcol[1000001];
ll sumrow[1000001];
multiset<ll> rows, cols;
ll colsub, rowsub;

int main () {
    scanf ("%d%d%d%d", &n, &m, &k, &p);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            int x;
            scanf ("%d", &x);
            row[i] += x;
            col[j] += x;
        }
    for (int i = 0; i < n; i++) rows.insert (-row[i]);
    for (int i = 0; i < m; i++) cols.insert (-col[i]);
    ll ans = -1e18, srow = 0, scol = 0;
    for (int i = 0; i < k; i++) {
        {
            ll tmp = -(*rows.begin());
            rows.erase (rows.begin ());
            rows.insert (-(tmp - m * p));
            srow += tmp;
            sumrow[i + 1] = srow;
        }   
        {
            ll tmp = -(*cols.begin());
            cols.erase (cols.begin ());
            cols.insert (-(tmp - n * p));
            scol += tmp;
            sumcol[i + 1] = scol;
        }
    }
    for (int i = 0; i <= k; i++) {
        ll cur = sumrow[i] + sumcol[k - i] - (ll)i * (k - i) * p;
        ans = max (ans, cur);
    }
    cout << ans << endl;        
    return 0;
}