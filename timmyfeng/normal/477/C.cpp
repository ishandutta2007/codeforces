#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s, p; cin >> s >> p;
    int n = s.size(), k = p.size();

    vector cost(n + 1, vector<int>(n + 1, INT_MAX));
    cost[0][0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (cost[i][j] == INT_MAX) continue;
            cost[i + 1][j] = min(cost[i + 1][j], cost[i][j] + (j % k > 0));
            if (s[i] == p[j % k]) cost[i + 1][j + 1] = min(cost[i + 1][j + 1], cost[i][j]);
        }
    }

    vector<int> answer(n + 1);
    for (int i = 1; k * i <= n; ++i) {
        if (cost[n][k * i] <= n)
            answer[cost[n][k * i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        answer[i] = max(answer[i], answer[i - 1]);
    }

    for (int i = 0; i <= n; ++i) {
        answer[i] = min(answer[i], (n - i) / k);
        cout << answer[i] << " ";
    }
    cout << "\n";
}