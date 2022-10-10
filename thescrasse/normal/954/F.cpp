// 954F
// percorsi possibili in una griglia 3 x n con ostacoli rettangolari

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define INF (ll)1e18

ll i, i1, j, k, k1, t, n, m, res, check1, a, b, c, mt[3][3], pv[3][3], mod, x, stat[3];
ll st[3][3] = {{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
ll pt[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
vector<pair<ll, ll>> v;
vector<ll> o;

void fmexp(ll x) {
    /* cout << x << endl;

    for (i1 = 0; i1 < 3; i1++) {
        for (j = 0; j < 3; j++) {
            cout << st[i1][j] << ' ';
        }
        cout << endl;
    }
    cout << "---" << endl; */

    ll i, j, k;

    o.clear();
    while (x > 1) {
        if (x % 2 == 1) {
            o.push_back(1);
        }
        x /= 2;
        o.push_back(2);
    }
    reverse(o.begin(), o.end());

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            mt[i][j] = st[i][j];
        }
    }

    for (auto u : o) {
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                pv[i][j] = mt[i][j];
            }
        }
        if (u == 2) {
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    mt[i][j] = 0;
                    for (k = 0; k < 3; k++) {
                        mt[i][j] = (mt[i][j] + pv[i][k] * pv[k][j]) % mod;
                    }
                }
            }
        } else {
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    mt[i][j] = 0;
                    for (k = 0; k < 3; k++) {
                        mt[i][j] = (mt[i][j] + pv[i][k] * st[k][j]) % mod;
                    }
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    mod = 1000000007;
    cin >> n >> m;
    for (i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v.push_back({b, a});
        v.push_back({c + 1, a + 3});
    }

    for (i = 0; i < 3; i++) stat[i] = 0;

    v.push_back({2, -1});
    v.push_back({m + 1, 0});
    sort(v.begin(), v.end());

    for (i = 1; i < v.size(); i++) {
        k = v[i].first - v[i - 1].first;
        x = v[i].second - 1;

        if (k != 0) {
            fmexp(k);
            for (i1 = 0; i1 < 3; i1++) {
                for (j = 0; j < 3; j++) {
                    pv[i1][j] = pt[i1][j];
                }
            }
            res = 0;
            for (i1 = 0; i1 < 3; i1++) {
                for (j = 0; j < 3; j++) {
                    pt[i1][j] = 0;
                    for (k = 0; k < 3; k++) {
                        pt[i1][j] = (pt[i1][j] + mt[i1][k] * pv[k][j]) % mod;
                    }
                }
            }
        }

        /* for (i1 = 0; i1 < 3; i1++) {
            for (j = 0; j < 3; j++) {
                cout << mt[i1][j] << ' ';
            }
            cout << endl;
        }
        cout << "---" << endl; */

        if (x < 3) {
            stat[x]++;
            for (j = 0; j < 3; j++) {
                st[x][j] = 0;
            }
        } else {
            stat[x - 3]--;
            if (stat[x - 3] == 0) {
                for (j = 0; j < 3; j++) {
                    if (x + j != 5 || x == 4) {
                        st[x - 3][j] = 1;
                    } else {
                        st[x - 3][j] = 0;
                    }
                }
            }
        }

        /* for (i1 = 0; i1 < 3; i1++) {
            for (j = 0; j < 3; j++) {
                cout << pt[i1][j] << ' ';
            }
            cout << endl;
        }
        cout << "---" << endl; */
    }

    cout << pt[1][1];

    return 0;
}