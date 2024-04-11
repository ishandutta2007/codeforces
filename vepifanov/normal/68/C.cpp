#include <cstdio>
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

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < n; i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define y0 y3487465
#define y1 y8687969

typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}

int n;
int m, f;
map<ll, int> res[6][6];
int fl[6][6], fr[6][6], fc[6][6];
vi v;

int hash (vi v) {
    ll tmp = 0;
    for (int i = 0; i < sz (v); i++)
        tmp = tmp * 239 + v[i] + 1;
    re tmp;
}

int go (int i, int j) {
    if (i == j) re go (i + 1, 0);
    if (i == n) {
        if (v[n - 1] == f) re 0;
        re -1e9;
    }
    int h = hash (v);
    if (res[i][j].count (h)) re res[i][j][h];
    int cur = -1e9;
    for (int k = fl[j][i]; k <= fr[j][i] && k <= v[j]; k++) {
        v[j] -= k;
        v[i] += k;
        cur = max (cur, k * k + int (k > 0) * fc[j][i] + go (i, j + 1));
        v[j] += k;
        v[i] -= k;
    }
    res[i][j][h] = cur;
    re cur;
}

int main() {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            int a, b, l, h, c;
            scanf ("%d%d%d%d%d", &a, &b, &l, &h, &c); a--; b--;
            fl[a][b] = l;
            fr[a][b] = h;
            fc[a][b] = c;
        }
    for (f = 0; f <= 25; f++) {
        v = vector<int> (n, 0);
        v[0] = f;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j].clear ();
        int tmp = go (1, 0);
        if (tmp >= 0) {
            printf ("%d %d\n", f, tmp);
            re 0;
        }
    }
    printf ("-1 -1\n");
    return 0;
}