#line 1 "main.cpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

pair<int, int> dxy(char c) {
    static const string ways = "LRUD";
    static const vector<pair<int, int>>
        dxys{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    for (int i = 0; i < 4; ++i) {
        if (c == ways[i]) return dxys[i];
    }
    terminate();
}

void solve() {
    string s;
    cin >> s;

    vector<pair<int, int>> pos;
    {
        int x = 0, y = 0;
        for (auto c : s) {
            auto [dx, dy] = dxy(c);
            x += dx, y += dy;
            pos.emplace_back(x, y);
        }
    }

    for (auto [sx, sy] : pos) {
        int x = 0, y = 0;
        for (auto c : s) {
            auto [dx, dy] = dxy(c);
            int nx = x + dx, ny = y + dy;

            if (nx == sx && ny == sy) continue;
            x = nx, y = ny;
        }

        if (x == 0 && y == 0) {
            cout << sx << " " << sy << "\n";
            return;
        }
    }

    cout << "0 0\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}