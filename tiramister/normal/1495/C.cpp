#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> ss(h);
    for (auto& s : ss) cin >> s;

    for (int i = 0; i < h; i += 3) {
        fill(ss[i].begin(), ss[i].end(), 'X');
    }

    for (int i = 0; i + 3 < h; i += 3) {
        // connect i-th and (i+3)-th rows

        bool ok = false;
        for (int j = 0; j < w && !ok; ++j) {
            if (ss[i + 1][j] == 'X') {
                ok = true;
                ss[i + 2][j] = 'X';
            }
        }
        for (int j = 0; j < w && !ok; ++j) {
            if (ss[i + 2][j] == 'X') {
                ok = true;
                ss[i + 1][j] = 'X';
            }
        }

        if (!ok) ss[i + 1][0] = ss[i + 2][0] = 'X';
    }

    if (h % 3 == 0) {
        // connect cells in the last row
        for (int j = 0; j < w; ++j) {
            if (ss[h - 1][j] == 'X') ss[h - 2][j] = 'X';
        }
    }

    for (auto s : ss) cout << s << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}