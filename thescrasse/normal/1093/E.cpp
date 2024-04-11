// 1093E
// Intersection of Permutations

#pragma GCC optimize("O3")
#pragma GCC option("arch=native")

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 1000000007
#define maxn 200010
#define sq 1875

int i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
int f[maxn], x, ty, q, fn[maxn], r[maxn], p, s;
vector<array<int, 5>> qt, q1;
// q1: r_a l_b r_b i sg

void rst() {
    for (int i = 1; i <= n; i++) fn[i] = 0;
}

void upd(int p, int x) {
    // cout << "upd " << p << ' ' << x << nf;
    while (p <= n) {
        fn[p] += x; p += (p & (-p));
    }
}

int ps(int p) {
    // cout << "ps " << p << nf;
    int r = 0;
    while (p > 0) {
        r += fn[p]; p -= (p & (-p));
    }
    return r;
}

int rs(int l, int r) {
    return ps(r) - ps(l - 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n >> q;
    for (i = 1; i <= n; i++) {
        cin >> x; f[x] = i;
    }
    for (i = 0; i < q; i++) r[i] = 0;

    for (i = 1; i <= n; i++) {
        cin >> a[i]; a[i] = f[a[i]];
    }

    for (i = 0; i < q; i++) {
        cin >> ty; qt.pb({ty, 0, 0, 0});
        if (ty == 1) cin >> qt[i][1] >> qt[i][2] >> qt[i][3] >> qt[i][4];
        else cin >> qt[i][1] >> qt[i][2];
    }

    for (i = 0; i < q; i += sq) {
        q1.clear(); rst(); p = 0; m = min(q, i + sq);
        for (j = i; j < m; j++) {
            if (qt[j][0] == 1) {
                q1.pb({qt[j][1] - 1, qt[j][3], qt[j][4], j, -1});
                q1.pb({qt[j][2], qt[j][3], qt[j][4], j, 1});
            }
        }

        sort(q1.begin(), q1.end()); s = q1.size();
        /* for (auto u : q1) {
            for (j = 0; j < 5; j++) cout << u[j] << ' ';
            cout << nf;
        } */

        for (j = 1; j <= n; j++) f[a[j]] = j;
        for (j = 1; j <= n + 1; j++) {
            // cout << j << ' ' << p << nf;
            while (p < s && q1[p][0] == j - 1) {
                // cout << "fn = " << q1[p][3] << ' ' << rs(q1[p][1], q1[p][2]) << nl;
                r[q1[p][3]] += (q1[p][4] * rs(q1[p][1], q1[p][2])); p++;
            }
            if (j <= n) upd(f[j], 1);
        }

        for (j = i; j < m; j++) {
            // cout << "j = " << j << ' ' << r[j] << nl;
            if (qt[j][0] == 2) continue;
            for (k = i; k < j; k++) {
                if (qt[k][0] == 1) continue;
                p = qt[k][1];
                if (qt[j][1] <= a[p] && a[p] <= qt[j][2]) {
                    r[j] -= (qt[j][3] <= p && p <= qt[j][4]);
                    // cout << "bool = " << (qt[j][3] <= p && p <= qt[j][4]) << nl;
                    p = qt[k][2];
                    r[j] += (qt[j][3] <= p && p <= qt[j][4]);
                    // cout << "bool = " << (qt[j][3] <= p && p <= qt[j][4]) << nl;
                }
                p = qt[k][2];
                if (qt[j][1] <= a[p] && a[p] <= qt[j][2]) {
                    r[j] -= (qt[j][3] <= p && p <= qt[j][4]);
                    // cout << "bool = " << (qt[j][3] <= p && p <= qt[j][4]) << nl;
                    p = qt[k][1];
                    r[j] += (qt[j][3] <= p && p <= qt[j][4]);
                    // cout << "bool = " << (qt[j][3] <= p && p <= qt[j][4]) << nl;
                }
                swap(a[qt[k][1]], a[qt[k][2]]);
                /* for (ll l = 1; l <= n; l++) cout << a[l] << ' ';
                cout << nl; */
            }
            for (k = j - 1; k >= i; k--) {
                if (qt[k][0] == 2) swap(a[qt[k][1]], a[qt[k][2]]);
            }
        }

        for (j = i; j < m; j++) {
            if (qt[j][0] == 2) swap(a[qt[j][1]], a[qt[j][2]]);
        }
    }

    for (i = 0; i < q; i++) {
        if (qt[i][0] == 1) cout << r[i] << nl;
    }

    return 0;
}