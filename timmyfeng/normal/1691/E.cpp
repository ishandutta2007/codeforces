#include <bits/stdc++.h>
using namespace std;

const int N = 100000;

multiset<pair<int, int>> update_segments[2];
int dsu[N];

int find(int a) {
    return dsu[a] == -1 ? a : dsu[a] = find(dsu[a]);
}

bool unite(int a, int b) {
    a = find(a), b = find(b);
    if (a == b) return false;
    dsu[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n; cin >> n;

        vector<array<int, 4>> segments;
        for (int i = 0; i < n; ++i) {
            int c, l, r; cin >> c >> l >> r;
            segments.push_back({l, r, c, i});
        }
        sort(segments.begin(), segments.end());

        for (auto &i : update_segments) i.clear();

        int answer = n;
        fill(dsu, dsu + n, -1);
        for (auto [l, r, c, i] : segments) {
            int new_x = -1;
            while (!update_segments[1 - c].empty()) {
                auto [x, j] = *update_segments[1 - c].rbegin();
                if (x < l) break;

                answer -= unite(i, j);

                update_segments[1 - c].erase(--update_segments[1 - c].end());
                new_x = max(new_x, x);
            }

            update_segments[1 - c].insert({new_x, i});
            update_segments[c].insert({r, i});
        }

        cout << answer << "\n";
    }
}