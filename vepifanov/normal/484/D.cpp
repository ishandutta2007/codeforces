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
#define prev PREV
                         
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
int x[1000001];
ll res[1000001];
ii tree[1000001][20];
int p[1000001];

ii merge (ii a, ii b) {
    re mp (min (a.fi, b.fi), max (a.se, b.se));
}

ii get (int l, int r) {
    int t = p[r - l + 1];
    re merge (tree[l][t], tree[r - (1 << t) + 1][t]);
}

int main () {
    scanf ("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf ("%d", &x[i]);
        tree[i][0] = mp (x[i], x[i]);
    }   
    int t = 0;
    for (int i = 1; i <= n; i++) {
        while ((1 << (t + 1)) <= i) t++;
        p[i] = t;
    }
    for (int j = 0; j < 19; j++)
        for (int i = 0; i < n; i++)
            tree[i][j + 1] = merge (tree[i][j], ((i + (1 << j)) < n) ? tree[i + (1 << j)][j] : mp (1000000000, -1000000000));
    vi v;
    for (int i = 0; i < n; i++) {
        if ((i == 0 || x[i - 1] >= x[i]) && (i + 1 == n || x[i + 1] >= x[i])) {
            v.pb (i);
            if (i + 1 < n) v.pb (i + 1);
        }   
        if ((i == 0 || x[i - 1] <= x[i]) && (i + 1 == n || x[i + 1] <= x[i])) {
            v.pb (i);
            if (i + 1 < n) v.pb (i + 1);
        }
    }
    v.pb (0);
    v.pb (n);
    sort (all (v));
    v.resize (unique (all (v)) - v.begin ());
    res[0] = 0;
    for (int i = 1, j = 0; i <= n; i++) {
        while (v[j + 1] < i) j++;
        res[i] = res[i - 1];
        for (int k = 0; k < 5 && k <= j; k++) {
            int a = v[j - k];
            ii tmp = get (a, i - 1);
            res[i] = max (res[i], res[a] + tmp.se - tmp.fi);
        }
    }
    cout << res[n] << endl;
    return 0;
}