#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 210

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, c, cr, p2, ls, rq[maxn][2];
map<ll, bool> visited;

void ask(ll x) {
    cout << "? " << x << nf;
    cin >> c;
}

void clm(ll x) {
    cout << "= " << x << nf;
}

void qr(ll x, ll y) {
    // while (visited[cr] || visited[cr + x]) cr--;
    ask(x); ask(x + y);
}

int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;

        if (n <= 64) {
            for (i = 1; i <= n; i++) {
                if (i % 2 == 1) rq[i][0] = (i + 1) / 2;
                else rq[i][0] = n + 1 - rq[i - 1][0];
            }

            for (i = 1; i <= n; i++) {
                ask(rq[i][0]);
                if (i != 1 && c == 0) {
                    clm(n + 2 - i); break;
                }
                if (i == n) clm(1);
            }
        } else if (n <= 125) {
            for (i = 2; i <= 130; i++) {
                if (i % 2 == 1) rq[i][1] = (i + 1) / 2;
                else rq[i][1] = 64 + 1 - rq[i - 1][1];

                if (i % 2 == 0) rq[i][0] = i / 2;
                else rq[i][0] = n + 1 - rq[i - 1][0];
            }

            for (i = 1; i < n; i += 2) swap(rq[i][1], rq[i + 1][1]);

            ask(64); ask(1);

            j = c;

            for (i = 3; i <= 64; i++) {
                ask(rq[i][j]);
                if (i != 1 && c == 0) {
                    clm(abs(rq[i][j] - rq[i - 1][j]) + 1); break;
                }
                if (j == 1) {
                    if (abs(rq[i][j] - rq[i - 1][j]) == 1) {
                        clm(1); break;
                    }
                }
                if (j == 0) {
                    if (abs(rq[i][j] - rq[i - 1][j]) == 64) {
                        clm(64); break;
                    }
                }
            }
        } else {
            n--;
        m = n; k = 1; p2 = 1;
        for (i = 1;; i++) {
            k += (2 * (i % 2) - 1) * m;
            // cout << k << nf;
            m -= p2;
            if (m <= 0) {
                m += p2; p2 /= 2; break;
            }
            p2 *= 2;
        }

        i = (2 * (i % 2) - 1); i *= -1;
        ask(k); ask(k + i * m); ls = k + i * m; i *= -1;

        if (c == 0) {
            k = m;
        } else {
            k = 0;
            while (p2 >= m) p2 /= 2;
        }

        while (true) {
            c = 0;
            ask(ls + i * (k + p2)); ls += (i * (k + p2));
            i *= -1;
            if (c == 0) k += p2;
            if (p2 == 1) break;
            p2 /= 2;
        }

        clm(k + 1);
        }
    }

    return 0;
}