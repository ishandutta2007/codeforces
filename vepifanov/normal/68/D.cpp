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
typedef unsigned int ui;
typedef pair<ui, ui> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) {
    re x > 0 ? x : -x;
}


ui n;
ui m, r;
pair<ui, ui> q[50];
ui w[50];
map<ui, ii> all;
ui MAX = 1;

ui add2 (ui x, ui y) {
    if (!all.count (x)) all[x] = mp (0, 0);
    ii tmp = all[x];
    tmp.fi += y;
    all[x].fi = tmp.fi;
    if (tmp.se) {
        for (ui i = 0; i < r; i++)
            if (q[i].fi == x) {
                q[i].se = tmp.fi;
                while (i > 0 && q[i].se > q[i - 1].se) {
                    swap (q[i - 1], q[i]);
                    i--;
                }
                break;
            }
    } else {
        q[r] = mp (x, tmp.fi);
        ui i = r;
        while (i > 0 && q[i].se > q[i - 1].se) {
            swap (q[i - 1], q[i]);
            i--;
        }
        if (q[r].fi != x) {
            all[x].se = 1;
            all[q[r].fi].se = 0;
        }
    }
    re 0;
}

ui add (ui x, ui y) {
    if (x * 2 <= MAX) { add2 (x * 2, y); add2 (x * 2 + 1, y); }
    while (x > 1) {
        add2 (x, y);
        x /= 2;
    }
    re 0;
}

ui isanc (ui x, ui last) {
    while (x > last) x /= 2;
    re ui (x == last);
}

int main() {
    scanf ("%d%d", &n, &m);
    n++;
    MAX <<= n;
    MAX--;
    MAX <<= 1;
    MAX++;
    r = n + 1;
    for (ui i = 1; i <= r; i++) {
        q[i - 1] = mp (i + 1, 0);
        all[i + 1] = mp (0, 1);
    }
    for (ui i = 0; i < m; i++) {
        char s[10];
        int a, b;
        scanf ("%s%d%d", s, &a, &b);
        if (s[0] == 'a') {
            cin >> a >> b;
            add (a, b);
        } else {
            double ans = 0, prob = 1;
            ui last = 1, lk = 0;
            for (ui i = 0; i < r; i++) {
                ui x = q[i].fi;
                ui k = 0, y = x, ok = 0;
                while (y > 1) {
                    y /= 2;
                    ok |= ui (y == last);
                    w[k++] = y;
                }
                if (isanc (last, x)) continue;
                if (!ok) {
                    ans += q[i].se * prob;
                    break;
                }
                ans += prob * (1 - (1.0 / ((long long)1 << (k - lk)))) * q[i].se;
                prob *= (1.0 / ((long long)1 << (k - lk)));
                lk = k;
                last = x;
            }           
            printf ("%.10f\n", ans);
        }
    }
    return 0;
}