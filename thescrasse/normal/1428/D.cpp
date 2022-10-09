#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b, f[maxn], c, ty, x, y;
vector<ll> adj[4], ps;
vector<array<ll, 2>> sl;
vector<array<ll, 2>> v;
priority_queue<array<ll, 2>> pq;
set<ll> st;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> n;
    for (i = 1; i <= n; i++) {
        cin >> a[i]; f[a[i]]++;
        adj[a[i]].pb(i);
    }

    for (i = 0; i <= 3; i++) {
        sort(adj[i].begin(), adj[i].end());
        reverse(adj[i].begin(), adj[i].end());
    }

    c = n;

    for (auto u : adj[1]) sl.pb({u, 1});
    for (auto u : adj[2]) sl.pb({u, 2});
    sort(sl.begin(), sl.end()); reverse(sl.begin(), sl.end());

    for (auto u : sl) {
        ty = u[1]; b = u[0];
        if (ty == 1) {
            pq.push({-b, c}); st.insert(b);
            v.pb({c, b}); c--;
        } else {
            if (pq.empty()) {
                cout << -1 << nl; return 0;
            }
            x = -pq.top()[0]; y = pq.top()[1]; pq.pop();
            v.pb({y, b}); st.erase(x); st.insert(b);
        }
    }

    sort(ps.begin(), ps.end()); reverse(ps.begin(), ps.end());

    /* for (auto u : st) cout << u << ' ';
    cout << nl; */

    for (auto u : adj[3]) {
        if (st.empty()) {
            cout << -1 << nl; return 0;
        }
        auto it = st.end(); it--;
        b = *(it); st.erase(b); st.insert(u);
        // cout << "b, u = " << b << ' ' << u << nl;
        if (u > b) {
            cout << -1 << nl; return 0;
        }
        v.pb({c, u}); v.pb({c, b}); c--;
    }

    cout << v.size() << nl;
    for (auto u : v) {
        cout << u[0] << ' ' << u[1] << nl;
    }

    return 0;
}