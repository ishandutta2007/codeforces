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
int m, k;
int ea[50000], eb[50000], was[50000], prev[50000], d[50000], q[50000];
set<ii> forb;
map<ii, int> all;
vi v[3000];

int out (int x) {
    if (d[x] != 0) out (prev[x]);
    printf ("%d ", eb[x] + 1);
    re 0;
}

int main() {
    scanf ("%d%d%d", &n, &m, &k);   
    for (int i = 0; i < m; i++) {
        scanf ("%d%d", &ea[i], &eb[i]); ea[i]--; eb[i]--;
        eb[i + m] = ea[i];
        ea[i + m] = eb[i];
        v[ea[i]].pb (i);
        v[eb[i]].pb (i + m);
        all[mp (ea[i], eb[i])] = i;
        all[mp (eb[i], ea[i])] = i + m;
    }
    for (int i = 0; i < k; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--; c--;
        if (all.count (mp (a, b)) && all.count (mp (b, c)))
            forb.insert (mp (all[mp (a, b)], all[mp (b, c)]));
    }
    ea[2 * m] = 0;
    eb[2 * m] = 0;
    int l = 0, r = 1;
    q[0] = 2 * m;
    was[2 * m] = 1;
    while (l < r) {
        int x = q[l++];
        int b = eb[x];
        if (b == n - 1) {
            printf ("%d\n", d[x]);
            out (x);
            re 0;
        }
        for (int i = 0; i < sz (v[b]); i++) {
            int y = v[b][i];
            if (!forb.count (mp (x, y)) && !was[y]) {
                was[y] = 1;
                d[y] = d[x] + 1;
                prev[y] = x;
                q[r++] = y;
            }
        }
    }
    printf ("-1\n");
    return 0;                  
}