#include <bits/stdc++.h>

using namespace std;

void solve() {
    int N; cin >> N;
    vector<string> S(N);
    for (int i = 0; i < N; i++) cin >> S[i];
    int mx = 0;
    for (int ch = 0; ch < 5; ch++) {
        char c = (char) (ch + 'a');
        vector<int> A;
        for (int i = 0; i < N; i++) {
            int bal = 0;
            for (int j = 0; j < S[i].size(); j++) bal += (S[i][j] == c ? 1 : -1);
            A.push_back(bal);
        }
        sort(A.rbegin(), A.rend());
        int sum = 0, ans = 0;
        for (int i = 0; i < A.size(); i++) if (sum + A[i] > 0) sum += A[i], ans++;
        mx = max(mx, ans);
    }
    cout << mx << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int tt; cin >> tt;
    while (tt--)
        solve();
    return 0;
}