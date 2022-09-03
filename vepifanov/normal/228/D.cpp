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
int x[100000];
ll f[5][10][100001];

int add (int t, int s, int x, int y) {
    x++;
    while (x <= n) {
        f[t][s][x] += y;
        x |= x + 1;
    }
    re 0;
}

ll get (int t, int s, int x) {
    x++;
    ll y = 0;
    while (x > 0) {
        y += f[t][s][x];
        x = (x & (x + 1)) - 1;
    }
    re y;
}

ll get (int t, int s, int a, int b) {
    re get (t, s, b) - get (t, s, a - 1);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        for (int j = 2; j <= 6; j++)
            add (j - 2, i % (2 * (j - 1)), i, x[i]);
    }   
    scanf ("%d", &m);
    for (int i = 0; i < m; i++) {
        int t, a, b, c;
        scanf ("%d", &t);
        if (t == 1) {
            scanf ("%d%d", &a, &b); a--;
            for (int j = 2; j <= 6; j++)
                add (j - 2, a % (2 * (j - 1)), a, b - x[a]);
            x[a] = b;
        } else {
            scanf ("%d%d%d", &a, &b, &c); a--; b--;
            ll ans = 0;
            for (int j = 0; j < 2 * (c - 1); j++) {
                int p = (a + j) % (2 * (c - 1));
                int k = j + 1;
                if (k > c) k = 2 * c - k;
                ans += k * get (c - 2, p, a, b);
            }
            printf ("%I64d\n", ans);
        }
    }
    return 0;
}