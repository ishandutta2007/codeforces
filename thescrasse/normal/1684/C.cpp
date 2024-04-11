#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll cn[maxn], l;
vector<ll> mt[maxn], st[maxn];

void upd(ll i, ll j, ll x) {
    if (j >= 2) cn[i] -= (mt[i][j] < mt[i][j - 1]);
    if (j <= m - 1) cn[i] -= (mt[i][j] > mt[i][j + 1]);
    mt[i][j] = x;
    if (j >= 2) cn[i] += (mt[i][j] < mt[i][j - 1]);
    if (j <= m - 1) cn[i] += (mt[i][j] > mt[i][j + 1]);
}

void sw(ll a, ll b) {
    ll i, x, y;
    if (a == b) return;
    for (i = 1; i <= n; i++) {
        x = mt[i][a]; y = mt[i][b];
        upd(i, a, y); upd(i, b, x);
    }
}

bool good(ll a, ll b) {
    ll i, j, r = 0;
    sw(a, b);
    for (i = 1; i <= n; i++) {
        r += cn[i];

        /* for (j = 1; j <= m; j++) cout << mt[i][j] << ' ';
        cout << nl;
        cout << "cn =" _ cn[i] << nl; */
    }
    sw(a, b);
    return (r == 0);
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
        cin >> n >> m;
        for (i = 1; i <= n; i++) {
            mt[i].clear(); cn[i] = 0;
        }
        for (i = 1; i <= n; i++) {
            mt[i].pb(-1);
            for (j = 1; j <= m; j++) {
                cin >> a; mt[i].pb(a);
            }
            st[i] = mt[i];
            sort(st[i].begin(), st[i].end());

            for (j = 2; j <= m; j++) {
                if (mt[i][j] < mt[i][j - 1]) cn[i]++;
            }
        }

        k = -1;
        for (i = 1; i <= n; i++) {
            if (cn[i] > 0) {
                k = i; break;
            }
        }

        if (k == -1) {
            cout << 1 _ 1 << nl; continue;
        }

        for (j = 1; j <= m; j++) {
            if (mt[i][j] != st[i][j]) {
                l = j; break;
            }
        }

        flag[0] = 0;
        for (j = 1; j <= m; j++) {
            if (good(l, j)) {
                flag[0] = 1;
                cout << l _ j << nl; break;
            }
        }

        if (flag[0] == 0) cout << -1 << nl;
    }

    return 0;
}