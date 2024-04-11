#include <bits/stdc++.h>
using namespace std;

int k;
vector<pair<int, string>> sol;

void dir(int num, string s) {
    if (!num) return;
    sol.emplace_back(num, s);
    k -= num * s.size();
    if (!k) {
        cout << sol.size() << '\n';
        for (auto i : sol) {
            cout << i.first << ' ' << i.second << '\n';
        }
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m >> k;
    if (k > 4 * n * m - 2 * n - 2 * m) {
        cout << "NO" << '\n';
        exit(0);
    }
    cout << "YES" << '\n';
    dir(min(m - 1, k), "R");
    dir(min(m - 1, k), "L");
    for (int i = 1; i < n; ++i) {
        dir(1, "D");
        if (k / 3 < m - 1) {
            if (k >= 3) {
                dir(k / 3, "RUD");
            }
            dir(1, string("RUD").substr(0, k));
        } else {
            dir(m - 1, "RUD");
        }
        dir(min(k, m - 1), "L");
    }
    dir(k, "U");
}