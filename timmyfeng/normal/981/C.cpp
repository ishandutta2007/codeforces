#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> deg(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        ++deg[u], ++deg[v];
    }

    int junctions = 0;
    for (int i = 1; i <= n; ++i) {
        junctions += deg[i] >= 3;
    }

    if (junctions == 0) {
        int u = find(deg.begin(), deg.end(), 1) - deg.begin();
        int v = find(deg.begin() + u + 1, deg.end(), 1) - deg.begin();

        cout << "Yes\n";
        cout << 1 << "\n";
        cout << u << " " << v << "\n";
    } else if (junctions == 1) {
        int u = 1;
        while (deg[u] < 3) {
            ++u;
        }

        cout << "Yes\n";
        cout << count(deg.begin(), deg.end(), 1) << "\n";
        for (int i = 1; i <= n; ++i) {
            if (deg[i] == 1) {
                cout << u << " " << i << "\n";
            }
        }
    } else {
        cout << "No\n";
    }
}