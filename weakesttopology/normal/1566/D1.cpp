#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        map<int, vector<int>> C;
        for (int i = 0; i < N * M; ++i) {
            int a;
            cin >> a;
            C[a].push_back(i);
        }
        vector<int> s(N * M);
        int ptr = 0;
        for (auto& [x, I] : C) {
            int k = (int)I.size();
            vector<pair<int, int>> chairs;
            for (int j = 0; j < k; ++j) {
                chairs.emplace_back(ptr / M, ptr % M);
                ++ptr;
            }
            sort(chairs.begin(), chairs.end(), [](auto p, auto q) { return p.first != q.first ? p.first < q.first : p.second > q.second; });
            for (int j = 0; j < k; ++j) {
                s[I[j]] = chairs[j].first * M + chairs[j].second;
            }
        }
        vector<bool> on(N * M);
        int ans = 0;
        for (int i = 0; i < N * M; ++i) {
            for (int x = s[i] - s[i] % M; x < s[i]; ++x) {
                ans += on[x];
            }
            on[s[i]] = true;
        }
        cout << ans << '\n';
    }
    exit(0);
}