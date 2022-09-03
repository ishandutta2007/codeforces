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

pair<ii, int> v[100000];
int res[100000];

bool l1 (pair<ii, int> a, pair<ii, int> b) {
    re a.fi.fi < b.fi.fi || a.fi.fi == b.fi.fi && a.se < b.se;
}

bool l2 (pair<ii, int> a, pair<ii, int> b) {
    re a.fi.se < b.fi.se || a.fi.se == b.fi.se && a.se < b.se;
}

int main () {
    scanf ("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf ("%d%d", &v[i].fi.fi, &v[i].fi.se);
        v[i].se = i;
    }   
    sort (v, v + n, l1);
    int cur = 0, pos = 0;
    while (pos < n) {
        int tmp = min (pos + m, n) - 1;
        cur = max (cur, v[tmp].fi.fi);
        sort (v + pos, v + tmp + 1, l2);
        int x0 = 0;
        for (int i = pos; i <= tmp;) {
            int x1 = v[i].fi.se;
            cur += x1 - x0;
            int j = i;
            while (j <= tmp && v[j].fi.se == x1) {
                res[v[j].se] = cur;
                j++;
            }   
            cur += 1 + (j - i) / 2;
            i = j;
            x0 = x1;
        }
        cur += x0;
        pos = tmp + 1;
    }
    for (int i = 0; i < n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}