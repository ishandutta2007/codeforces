#include <bits/stdc++.h>

using namespace std;

#define pb push_back

void solve() {
    int N, K; cin >> N >> K;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> pos[N + 1];
    for (int i = 0; i < N; i++) {
        pos[A[i]].pb(i);
    }
    int nxt = 1;
    vector<int> can[K + 1];
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j < min(K, (int) pos[i].size()); j++) {
            can[nxt].pb(pos[i][j]);
            nxt = (nxt == K ? 1 : nxt + 1);
        }
    }
    int mn = 1e9;
    for (int i = 1; i <= K; i++) mn = min(mn, (int) can[i].size());
    vector<int> ans(N);
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j < mn; j++) {
            ans[can[i][j]] = i;
        }
    }
    for (int i = 0; i < N; i++) cout << ans[i] << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}