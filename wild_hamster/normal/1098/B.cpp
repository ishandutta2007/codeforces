#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <string>
#include <time.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
#define MOD 1000000007
typedef int ll;
using namespace std;
ll n,m,k, y, z, l, i, j, x;
ll  q, ans, w[100500], d[100500], p[100500];
vector<ll> a[100500];


string pat = "TACG";

ll rows[300500][4][4], cols[300500][4][4], perm[5], best_perm[5];
int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        a[i].resize(m);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        char c;
        cin >> c;
        if (c == 'A')
            a[i][j] = 1;
        else if (c == 'C')
            a[i][j] = 2;
        else if (c == 'G')
            a[i][j] = 3;
        else
            a[i][j] = 0;
    }
    for (int i = 0; i < n; i++) {
        for (int l = 0; l < 4; l++) {
            for (int r = 0; r < 4; r++) {
                for (int j = 0; j < m; j++) {
                    if (j % 2 == 0) {
                        rows[i][l][r] += (a[i][j] != l);
                    } else {
                        rows[i][l][r] += (a[i][j] != r);
                    }
                }
            }
        }
    }

    for (int j = 0; j < m; j++) {
        for (int l = 0; l < 4; l++) {
            for (int r = 0; r < 4; r++) {
                for (int i = 0; i < n; i++) {
                    if (i % 2 == 0) {
                        cols[j][l][r] += (a[i][j] != l);
                    } else {
                        cols[j][l][r] += (a[i][j] != r);
                    }
                }
            }
        }
    }

    ll opt_ans = n*m + 5;
    string type = "";

    for (int i = 0; i < 4; i++)
        perm[i] = i;
    do {
        //row
        ll error = 0;
        ll x1 = perm[0], x2 = perm[1], x3 = perm[2], x4 = perm[3];
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                error += min(rows[i][x1][x2], rows[i][x2][x1]);
            } else {
                error += min(rows[i][x3][x4], rows[i][x4][x3]);
            }
        }
        if (error < opt_ans) {
            opt_ans = error;
            type = "row";
            for (int i = 0; i < 4; i++) {
                best_perm[i] = perm[i];
            }
        }

        error = 0;
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) {
                error += min(cols[j][x1][x2], cols[j][x2][x1]);
            } else {
                error += min(cols[j][x3][x4], cols[j][x4][x3]);
            }
        }

        if (error < opt_ans) {
            opt_ans = error;
            type = "col";
            for (int i = 0; i < 4; i++) {
                best_perm[i] = perm[i];
            }
        }
    } while (next_permutation(perm, perm+4));

    for (int i = 0; i < 4; i++) {
        perm[i] = best_perm[i];
    }
    //cout << opt_ans << endl;
    ll x1 = perm[0], x2 = perm[1], x3 = perm[2], x4 = perm[3];


    if (type == "row") {
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (rows[i][x1][x2] < rows[i][x2][x1]) {
                    for (int j = 0; j < m; j++) {
                        if (j % 2 == 0) {
                            a[i][j] = x1;
                        } else {
                            a[i][j] = x2;
                        }
                    }
                } else {
                    for (int j = 0; j < m; j++) {
                        if (j % 2 == 0) {
                            a[i][j] = x2;
                        } else {
                            a[i][j] = x1;
                        }
                    }
                }
            } else {
                if (rows[i][x3][x4] < rows[i][x4][x3]) {
                    for (int j = 0; j < m; j++) {
                        if (j % 2 == 0) {
                            a[i][j] = x3;
                        } else {
                            a[i][j] = x4;
                        }
                    }
                } else {
                    for (int j = 0; j < m; j++) {
                        if (j % 2 == 0) {
                            a[i][j] = x4;
                        } else {
                            a[i][j] = x3;
                        }
                    }
                }
            }
        }
    } else {
        for (int j = 0; j < m; j++) {
            if (j % 2 == 0) {
                if (cols[j][x1][x2] < cols[j][x2][x1]) {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            a[i][j] = x1;
                        } else {
                            a[i][j] = x2;
                        }
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            a[i][j] = x2;
                        } else {
                            a[i][j] = x1;
                        }
                    }
                }
            } else {
                if (cols[j][x3][x4] < cols[j][x4][x3]) {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            a[i][j] = x3;
                        } else {
                            a[i][j] = x4;
                        }
                    }
                } else {
                    for (int i = 0; i < n; i++) {
                        if (i % 2 == 0) {
                            a[i][j] = x4;
                        } else {
                            a[i][j] = x3;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << pat[a[i][j]];
        cout << endl;
    }
    return 0;
}