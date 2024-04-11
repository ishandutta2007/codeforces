#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 1;

long long a[N], b[N], l[N], r[N], locks[N];
vector<int> keys[N];
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;

        fill(keys, keys + n + 1, vector<int>());

        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) cin >> b[i];

        set<int> indices;
        for (int i = 1; i <= n; ++i) {
            a[i] += a[i - 1];
            b[i] += b[i - 1];
            if (a[i] != b[i]) indices.insert(i);
        }

        queue<int> q;
        for (int i = 0; i < m; ++i) {
            cin >> l[i] >> r[i]; --l[i];
            locks[i] = 0;
            for (auto j : {l[i], r[i]}) {
                if (a[j] != b[j]) {
                    keys[j].push_back(i);
                    ++locks[i];
                }
            }
            if (locks[i] == 0) q.push(i);
        }

        while (!q.empty()) {
            int i = q.front(); q.pop();

            while (true) {
                auto it = indices.upper_bound(l[i]);
                if (it == indices.end() || *it >= r[i]) break;
                for (auto j : keys[*it]) {
                    if (--locks[j] == 0) q.push(j);
                }
                indices.erase(it);
            }
        }

        if (indices.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
}