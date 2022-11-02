#include <iostream>
#include <vector>

using namespace std;

void paint(int c, pair<int, int> p) {
    cout << c + 1 << " " << p.first << " " << p.second << endl;
}

void solve() {
    int n;
    cin >> n;

    // 
    vector<vector<pair<int, int>>> pss(2);
    for (int x = 1; x <= n; ++x) {
        for (int y = 1; y <= n; ++y) {
            pss[(x + y) % 2].emplace_back(x, y);
        }
    }

    // 12
    while (!pss[0].empty() && !pss[1].empty()) {
        int b;
        cin >> b;

        int c = (b == 1 ? 1 : 0);
        paint(c, pss[c].back());
        pss[c].pop_back();
    }

    // 3
    int t = (pss[0].empty() ? 1 : 0);
    while (!pss[t].empty()) {
        int b;
        cin >> b;

        int c = (b == 3 ? t : 2);
        paint(c, pss[t].back());
        pss[t].pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}