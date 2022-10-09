// 1439B
// Graph Subset Problem

#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF 1e9
#define mod 998244353
#define maxn 100010
#define gig 1000000

int i, i1, j, k, k1, t, n, m, res, flag[10], a, b, dg[maxn], s;
vector<int> adj[maxn];
priority_queue<array<int, 2>> pq;
array<int, 2> o;
vector<int> sl;

void rm(int s) {
    dg[s] = INF;
    for (auto u : adj[s]) {
        dg[u]--;
        if (dg[u] <= gig) {
            pq.push({-dg[u], u});
        }
    }
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
        cin >> n >> m >> k;
        for (i = 1; i <= n; i++) {
            adj[i].clear(); dg[i] = 0;
        }
        for (i = 0; i < m; i++) {
            cin >> a >> b;
            adj[a].pb(b); adj[b].pb(a);
            dg[a]++; dg[b]++;
        }

        for (i = 1; i <= n; i++) {
            sort(adj[i].begin(), adj[i].end());
        }

        while (!pq.empty()) pq.pop();

        for (i = 1; i <= n; i++) {
            pq.push({-dg[i], i});
        }

        flag[2] = 0;
        while (!pq.empty()) {
            o = pq.top(); pq.pop();
            m = -o[0]; s = o[1];
            if (dg[s] != m) continue;

            /* cout << "m, s = " << m << ' ' << s << nl;
            for (i = 1; i <= n; i++) {
                cout << dg[i] << ' ';
            }
            cout << nl; */

            if (m > gig) {
                break;
            } else if (m >= k) {
                sl.clear();
                cout << 1 << ' ';
                for (i = 1; i <= n; i++) {
                    if (dg[i] <= gig) sl.pb(i);
                }
                cout << sl.size() << nl;
                for (auto u : sl) cout << u << ' ';
                cout << nl;
                flag[2] = 1; break;
            } else if (m == k - 1) {
                vector<int> v; v.pb(s); flag[0] = 1;
                for (auto u : adj[s]) {
                    if (dg[u] <= gig) v.pb(u);
                }
                for (auto i : v) {
                    for (auto j : v) {
                        if (i >= j) continue;
                        if (!binary_search(adj[i].begin(), adj[i].end(), j)) flag[0] = 0;
                    }
                }

                if (flag[0] == 1) {
                    cout << 2 << nl;
                    for (auto u : v) cout << u << ' ';
                    cout << nl;
                    flag[2] = 1; break;
                } else {
                    rm(s);
                }
            } else if (m < k - 1) {
                rm(s);
            }
        }

        if (flag[2] == 0) cout << -1 << nl;
    }

    return 0;
}