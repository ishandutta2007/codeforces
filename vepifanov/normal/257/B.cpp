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

ii go (int k, int n, int m, int t) {
    if (n == 0 && m == 0) re mp (0, 0);
    ii tmp;
    if (!t) {
        if (n > 0 && (k == 0 || k == 1 && m == 0)) {
            tmp = go (0, n - 1, m, 1);
            tmp.fi += int (k == 0);
            tmp.se += int (k == 1);
            re tmp;
        } else {
            tmp = go (1, n, m - 1, 1);
            tmp.fi += int (k == 1);
            tmp.se += int (k == 0);
            re tmp;         
        }
    } else {
        if (n > 0 && (k == 1 || k == 0 && m == 0)) {
            tmp = go (0, n - 1, m, 0);
            tmp.fi += int (k == 0);
            tmp.se += int (k == 1);
            re tmp;
        } else {
            tmp = go (1, n, m - 1, 0);
            tmp.fi += int (k == 1);
            tmp.se += int (k == 0);
            re tmp;         
        }
    }
}

int main () {
    scanf ("%d%d", &n, &m);
    ii a = go (0, n - 1, m, 1);
    ii b = go (1, n, m - 1, 1);
    if (a.fi > b.fi || a.fi == b.fi && a.se < b.se) printf ("%d %d\n", a.fi, a.se); else printf ("%d %d\n", b.fi, b.se);
    return 0;
}