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
int m;
vii w[5000];
ii v[5000];
int p[5000], u[5000], pc[5000], px[5000], res[5000];

int go (int x, int p) {
    for (int i = 0; i < sz (w[x]); i++) {
        int y = w[x][i].fi;
        int z = w[x][i].se;
        if (y != p) {
            px[y] = x;
            pc[y] = z;
            go (y, x);
        }
    }
    re 0;
}

int main() {
    scanf ("%d", &n);   
    for (int i = 0; i < n; i++) {
        scanf ("%d", &v[i].fi);
        v[i].se = i;
    }
    sort (v, v + n);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        w[a].pb (mp (b, c));
        w[b].pb (mp (a, c));
    }
    go (0, 0);
    for (int i = 0; i < n; i++) {
        p[i] = i;
        res[i] = -1;
    }
    int it = 0;
    while (true) {
        int ok = 1;
        for (int i = 0; i < n; i++) u[i] = 0;
        for (int i = 0; i < n; i++) {
            int j = v[i].se;
            if (p[j] > 0 && u[p[j]] < pc[p[j]]) {
                ok = 0;
                u[p[j]]++;
                p[j] = px[p[j]];
            } else
            if (p[j] == 0 && res[j] == -1)
                res[j] = it;
        }
        if (ok) break;
        it++;
    }
    for (int i = 0; i < n; i++) printf ("%d ", res[i]);
    printf ("\n");
    return 0;
}