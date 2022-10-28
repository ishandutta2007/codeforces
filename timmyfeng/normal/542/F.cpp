#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t;
    cin >> n >> t;

    vector<array<int, 2>> tasks(n);
    for (auto &[a, b] : tasks) {
        cin >> a >> b;
    }
    sort(tasks.begin(), tasks.end());

    vector<int> nodes;
    for (int i = 1, j = 0; i <= t; ++i) {
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            if (it != --nodes.end()) {
                auto nxt = it;
                *it += *++nxt;
                nodes.erase(nxt);
            }
        }

        while (j < n && tasks[j][0] == i) {
            nodes.push_back(tasks[j++][1]);
        }

        sort(nodes.rbegin(), nodes.rend());
    }

    cout << nodes[0] << "\n";
}