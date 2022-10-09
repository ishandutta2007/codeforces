#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 1010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, tk[maxn], sq, tg, s, r, nsq[maxn];
vector<ll> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n; k = 0;
    if (n <= 3) {
        cout << 0; return 0;
    }

    if (n <= 8) {
        tg = (n - 2) / 2;
        for (i = 1; i <= n; i++) tk[i] = i % 2;
        while (k < tg) {
            q.clear();
            for (i = 1; i <= n; i++) {
                if (tk[i] == 0) {
                    q.pb(i); tk[i] = 1;
                }
            }
            if (q.empty()) s = 0;
            else s = q.size();
            k += s;

            cout << s << ' ';
            for (auto u : q) {
                cout << u << ' ';
            }
            cout << nf;

            cin >> r;
            if (r == -1) return 0;
            for (i = 0; i < s; i++) {
                if (r % 2 == 0) {
                    k -= tk[r]; tk[r] = 0;
                }
                r++; if (r == n + 1) r = 1;
            }
        }

        cout << 0 << nf;
    } else {
        sq = sqrt(n); tg = (n / sq) * (sq - 1);
        if (n % sq != 0) tg += (n - 1) % sq;
        tg -= (sq - 1);
        // cout << sq << ' ' << tg << nl;

        for (i = 1; i <= n; i++) {
            if (i == n || i % sq == 0) nsq[i] = 0;
            else nsq[i] = 1;
        }

        while (k < tg) {
            q.clear();
            for (i = 1; i <= n; i++) {
                if (tk[i] == 0 && nsq[i] == 1) {
                    q.pb(i); tk[i] = 1;
                }
            }
            if (q.empty()) s = 0;
            else s = q.size();
            k += s;

            cout << s << ' ';
            for (auto u : q) {
                cout << u << ' ';
            }
            cout << nf;

            cin >> r;
            if (r == -1) return 0;
            for (i = 0; i < s; i++) {
                if (nsq[r] == 1) {
                    k -= tk[r]; tk[r] = 0;
                }
                r++; if (r == n + 1) r = 1;
            }
        }

        cout << 0 << nf;
    }

    return 0;
}