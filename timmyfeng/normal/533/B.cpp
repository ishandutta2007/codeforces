#include <bits/stdc++.h>
using namespace std;

const int N = 200001;

vector<int> adj[N];
long long a[N];

array<long long, 2> dfs(int u) {
    array<long long, 2> maxi = {0, LLONG_MIN};
    for (auto c : adj[u]) {
        auto child = dfs(c);
        array<long long, 2> update = {LLONG_MIN, LLONG_MIN};
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                update[i ^ j] = max(update[i ^ j], child[i] + maxi[j]);
            }
        }
        maxi = update;
    }
    maxi[1] = max(maxi[1], maxi[0] + a[u]);
    return maxi;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        int p;
        cin >> p >> a[i];
        if (p > -1) {
            adj[p].push_back(i);
        }
    }

    cout << dfs(1)[1] << "\n";
}