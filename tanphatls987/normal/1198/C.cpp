#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 5e5 + 10;


int n, m;
vector<int> adj[N];
int v[N][2];
int h[N];

void solve() {
    vector<int> ans;
    for(int i = 1; i <= 3 * n; i++) h[i] = 0;

    for(int i = 1; i <= 3 * n; i++) {
        h[i] = 1;
        for(auto edge : adj[i]) {
            int j = v[edge][0] + v[edge][1] - i;
            if (h[j] == 1) {
                h[i] = h[j] = 0;
                ans.push_back(edge);
                break;
            }
        }
    }
    if (ans.size() >= n) {
        cout << "Matching\n";
        for(int i = 1; i <= n; i++) cout << ans[i - 1] << " ";
    } else {
        cout << "IndSet\n";
        for(int i = 1, j = 0; j < n; i++) if (h[i]) {
            cout << i << " ";
            j++;
        }
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--) {
        cin >> n >> m;
        for(int i = 1; i <= 3 * n; i++) adj[i].clear();
        for(int i = 1; i <= m; i++) {
            cin >> v[i][0] >> v[i][1];
            adj[v[i][0]].push_back(i);
            adj[v[i][1]].push_back(i);
        }
        solve();
    }

}