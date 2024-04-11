#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl "\n"
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, c[1010][1010], p1, p2;
bool visited[1010][1010], e1[1010], e2[1010], ps[1010][1010];
char x;

ll m1[4] = {0, 1, 0, -1};
ll m2[4] = {1, 0, -1, 0};

void dfs(ll s1, ll s2) {
    ll i, j, k;
    if (visited[s1][s2]) {
        return;
    }
    visited[s1][s2] = true;
    for (i = 0; i < 4; i++) {
        p1 = s1 + m1[i]; p2 = s2 + m2[i];
        if (p1 >= 0 && p1 < n && p2 >= 0 && p2 < m) {
            if (c[p1][p2] == 1) {
                dfs(p1, p2);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n >> m;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cin >> x;
            if (x == '#') {
                c[i][j] = 1;
            } else {
                c[i][j] = 0;
            }
        }
    }

    res = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (!visited[i][j] && c[i][j] == 1) {
                dfs(i, j);
                res++;
            }
        }
    }

    for (i = 0; i < n; i++) {
        check1 = 0;
        for (j = 0; j < m; j++) {
            if (c[i][j] == 1 && check1 == 0) {
                check1++;
            }
            if (c[i][j] == 0 && check1 == 1) {
                check1++;
            }
            if (c[i][j] == 1 && check1 == 2) {
                check1++;
            }
            if (check1 == 3) {
                res = -1;
            }
        }
    }

    for (j = 0; j < m; j++) {
        check1 = 0;
        for (i = 0; i < n; i++) {
            if (c[i][j] == 1 && check1 == 0) {
                check1++;
            }
            if (c[i][j] == 0 && check1 == 1) {
                check1++;
            }
            if (c[i][j] == 1 && check1 == 2) {
                check1++;
            }
            if (check1 == 3) {
                res = -1;
            }
        }
    }

    for (i = 0; i < n; i++) {
        e1[i] = 1;
        for (j = 0; j < m; j++) {
            if (c[i][j] == 1) {
                e1[i] = 0;
            }
        }
    }

    for (i = 0; i < m; i++) {
        e2[i] = 1;
        for (j = 0; j < n; j++) {
            if (c[j][i] == 1) {
                e2[i] = 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (e1[i] == 1 && e2[j] == 1) {
                ps[i][j] = 1;
            } else {
                ps[i][j] = 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (ps[i][j] == 1) {
                e1[i] = 0;
                e2[j] = 0;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (e1[i] == 1) {
            res = -1;
        }
    }

    for (i = 0; i < m; i++) {
        if (e2[i] == 1) {
            res = -1;
        }
    }

    cout << res;

    return 0;
}