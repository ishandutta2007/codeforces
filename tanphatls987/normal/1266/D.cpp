#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 10;
const int MOD = 998244353;

typedef long long ll;


ll bal[N];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m;
    cin >> n >> m;    
    while (m--) {
        int u, v, d;
        cin >> u >> v >> d;
        bal[u] -= d;
        bal[v] += d;
    }
    long long tot = 0;
    vector<int> imp[2];
    for(int i = 1; i <= n; i++) {
        imp[bal[i] < 0].push_back(i);
        if (bal[i] < 0) tot += -bal[i];
    }
    vector<tuple<int, int, long long>> ans;
    
    for(int i1 = 0, j1 = 0; ; ) {
        while (i1 < imp[1].size() && bal[imp[1][i1]] == 0) i1++;
        while (j1 < imp[0].size() && bal[imp[0][j1]] == 0) j1++;
        if (i1 == imp[1].size()) break;
        int curu = imp[1][i1];
        int curv = imp[0][j1];
        ll cost = min(-bal[curu], bal[curv]);
        ans.push_back(make_tuple(curu, curv, cost));

        bal[curu] += cost;
        bal[curv] -= cost;
    }
    cout << ans.size() << '\n';
    for(auto i : ans) {
        int u, v; ll cost;
        tie(u, v, cost) = i;
        cout << u << " " << v << " " << cost << '\n';
    }
}