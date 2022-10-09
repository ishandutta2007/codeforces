#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, mt[maxn][maxn], s;
char c;
vector<array<ll, 6>> sl;
vector<array<ll, 3>> cl;

void mv(ll a, ll b, ll c, ll d, ll e, ll f) {
    sl.pb({a, b, c, d, e, f});
    mt[a][b] ^= 1; mt[c][d] ^= 1; mt[e][f] ^= 1;
}

void cl4(vector<ll> st) {
    /* cout << "cl4" << nl;
    for (auto u : st) cout << u << ' ';
    cout << nl; */
    ll i, l, x, s = 0;
    for (i = 1; i <= 4; i++) s += st[i];
    if (s == 0) return;

    if (s == 3) {
        l = 0; cl.pb({0, 0, 0});
        x = cl.size(); x--;
        for (i = 1; i <= 4; i++) {
            if (st[i] == 1) {
                st[i] ^= 1; cl[x][l] = i; l++;
            }
        }
    }

    if (s == 2) {
        flag[1] = 0;
        l = 0; cl.pb({0, 0, 0});
        x = cl.size(); x--;
        for (i = 1; i <= 4; i++) {
            if (st[i] == 0 || (st[i] == 1 && flag[1] == 0)) {
                st[i] ^= 1; cl[x][l] = i; l++;
                if (st[i] == 0) flag[1] = 1;
            }
        }
        cl4(st);
    }

    if (s == 1) {
        flag[0] = 0;
        l = 0; cl.pb({0, 0, 0});
        x = cl.size(); x--;
        for (i = 1; i <= 4; i++) {
            if (st[i] == 1 || (st[i] == 0 && flag[0] < 2)) {
                st[i] ^= 1; cl[x][l] = i; l++;
                if (st[i] == 1) flag[0]++;
            }
        }
        cl4(st);
    }

    if (s == 4) {
        flag[1] = 0;
        l = 0; cl.pb({0, 0, 0});
        x = cl.size(); x--;
        for (i = 1; i <= 4; i++) {
            if (st[i] == 0 || (st[i] == 1 && flag[1] < 3)) {
                st[i] ^= 1; cl[x][l] = i; l++;
                if (st[i] == 0) flag[1]++;
            }
        }
        cl4(st);
    }

    /* for (i = 0; i < 3; i++) {
        cout << cl[x][i] << ' ';
    }
    cout << nl; */
}

void init(vector<ll> st) {
    cl.clear(); cl4(st);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n >> m; sl.clear();
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                cin >> c;
                if (c == '0') mt[i][j] = 0;
                else mt[i][j] = 1;
            }
        }

        for (i = 1; i <= n - 2; i++) {
            for (j = 1; j <= m - 1; j++) {
                if (mt[i][j] == 1 && mt[i][j + 1] == 1) {
                    mv(i, j, i, j + 1, i + 1, j);
                } else if (mt[i][j] == 1 && mt[i][j + 1] == 0) {
                    mv(i, j, i + 1, j, i + 1, j + 1);
                } else if (mt[i][j] == 0 && mt[i][j + 1] == 1) {
                    mv(i, j + 1, i + 1, j, i + 1, j + 1);
                }
            }
        }

        if (m % 2) {
            if (mt[n - 1][m] == 1 && mt[n][m] == 1) {
                mv(n - 1, m, n, m - 1, n, m);
            } else if (mt[n - 1][m] == 1 && mt[n][m] == 0) {
                mv(n - 1, m - 1, n - 1, m, n, m - 1);
            } else if (mt[n - 1][m] == 0 && mt[n][m] == 1) {
                mv(n - 1, m - 1, n, m - 1, n, m);
            }
        }

        for (j = 1; j <= m - 1; j += 2) {
            vector<ll> st;
            vector<array<ll, 2>> fn;
            st.pb(0);
            st.pb(mt[n - 1][j]);
            st.pb(mt[n - 1][j + 1]);
            st.pb(mt[n][j]);
            st.pb(mt[n][j + 1]);
            init(st);
            for (auto u : cl) {
                // cout << "u = " << u[0] << ' ' << u[1] << ' ' << u[2] << nl;

                fn.clear();
                for (i = 0; i < 3; i++) {
                    if (u[i] == 1) fn.pb({n - 1, j});
                    else if (u[i] == 2) fn.pb({n - 1, j + 1});
                    else if (u[i] == 3) fn.pb({n, j});
                    else if (u[i] == 4) fn.pb({n, j + 1});
                }

                sl.pb({0, 0, 0, 0, 0, 0});
                for (i = 0; i < 3; i++) {
                    s = sl.size(); s--;
                    sl[s][2 * i] = fn[i][0];
                    sl[s][2 * i + 1] = fn[i][1];
                }
            }
        }

        s = sl.size(); cout << s << nl;
        for (auto u : sl) {
            for (i = 0; i < 6; i++) cout << u[i] << ' ';
            cout << nl;
        }
    }

    return 0;
}