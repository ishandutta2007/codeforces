// code from https://wiki.olinfo.it/it/2021/pre-oii/allenamento

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 250010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;
ll nr[maxn][2][2];
vector<ll> adj[2][maxn];
set<ll> st[2];

struct min_stack {
    vector<array<int, 2>> v;
    min_stack(): v({}) {}

    void ins1(int p, int x) {
        while (!v.empty() && x <= v.back()[1]) v.pop_back();
    }

    void ins2(int p, int x) {
        v.pb({p, x});
    }
};

struct max_stack {
    vector<array<int, 2>> v;
    max_stack(): v({}) {}

    void ins1(int p, int x) {
        while (!v.empty() && x >= v.back()[1]) v.pop_back();
    }

    void ins2(int p, int x) {
        v.pb({p, x});
    }
};

min_stack s1;
max_stack s2;

void rst() {
    ll i, j;
    st[0].clear(); st[1].clear(); s1.v.clear(); s2.v.clear();
    st[0].insert(-1); st[1].insert(-1);
    for (i = 0; i <= 1; i++) {
        for (j = 1; j <= n; j++) {
            adj[i][j].clear();
        }
    }
    res = 0;
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
        // cout << "t =" _ t << nf;
        cin >> n; rst();
        for (i = 1; i <= n; i++) {
            cin >> a[i];
        }

        // nr[pos][</>][l/r]
        for (i = 1; i <= n; i++) {
            s1.ins1(i, a[i]); s2.ins1(i, a[i]);
            if (s1.v.empty()) nr[i][0][0] = 0;
            else nr[i][0][0] = s1.v.back()[0];
            if (s2.v.empty()) nr[i][1][0] = 0;
            else nr[i][1][0] = s2.v.back()[0];
            s1.ins2(i, a[i]); s2.ins2(i, a[i]);
        }

        s1.v.clear(); s2.v.clear();

        for (i = n; i >= 1; i--) {
            s1.ins1(i, a[i]); s2.ins1(i, a[i]);
            if (s1.v.empty()) nr[i][0][1] = n + 1;
            else nr[i][0][1] = s1.v.back()[0];
            if (s2.v.empty()) nr[i][1][1] = n + 1;
            else nr[i][1][1] = s2.v.back()[0];
            s1.ins2(i, a[i]); s2.ins2(i, a[i]);
        }

        for (i = 1; i <= n; i++) {
            adj[1][nr[i][0][0] + 1].pb(i);
            adj[0][nr[i][1][0] + 1].pb(i);
        }

        for (i = 1; i != n;) {
            // cout << "i =" _ i << nf;
            k = 0;
            for (auto u : adj[0][i]) st[0].insert(u);
            for (auto u : adj[1][i]) st[1].insert(u);

            /* for (auto u : st[0]) cout << u << ' ';
            cout << nf;
            for (auto u : st[1]) cout << u << ' ';
            cout << nf; */

            auto it0 = st[0].lower_bound(nr[i][0][1]); it0--; k = max(k, (*it0));
            auto it1 = st[1].lower_bound(nr[i][1][1]); it1--; k = max(k, (*it1));
            assert(k != i);

            for (j = i + 1; j <= k - 1; j++) {
                for (auto u : adj[0][j]) st[0].insert(u);
                for (auto u : adj[1][j]) st[1].insert(u);
            }
            i = k; res++;
        }

        cout << res << nf;
    }

    return 0;
}