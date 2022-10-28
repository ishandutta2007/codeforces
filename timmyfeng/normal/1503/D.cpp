#include <bits/stdc++.h>
using namespace std;

const int N = 400001;

int a[N], b[N], card[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        card[a[i]] = card[b[i]] = i;
    }

    int ans = 0;
    int l = 1, r = 2 * n;
    vector<array<int, 2>> s, t;

    while (l < r) {
        int tally = 0, flip = 0;

        queue<pair<int, bool>> queue;
        queue.push({l, true});

        while (!queue.empty()) {
            auto [x, f] = queue.front();
            queue.pop();

            int u = card[x];
            if (a[u] != x) {
                swap(a[u], b[u]);
                ++flip;
            }
            ++tally;

            if (f) {
                for (int i = r; i > b[u]; --i) {
                    queue.push({i, false});
                }
                l = max(l, a[u] + 1), r = min(r, b[u] - 1);
                s.push_back({a[u], b[u]});
            } else {
                for (int i = l; i < b[u]; ++i) {
                    queue.push({i, true});
                }
                r = min(r, a[u] - 1), l = max(l, b[u] + 1);
                t.push_back({a[u], b[u]});
            }
        }

        ans += min(flip, tally - flip);
    }

    while (!t.empty()) {
        s.push_back(t.back());
        t.pop_back();
    }

    bool ok = (int) s.size() == n;
    for (int i = 1; i < (int) s.size(); ++i) {
        ok &= s[i - 1][0] < s[i][0];
        ok &= s[i - 1][1] > s[i][1];
    }

    cout << (ok ? ans : -1) << "\n";
}