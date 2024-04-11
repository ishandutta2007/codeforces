#include <bits/stdc++.h>
using namespace std;

const int N = 202;

vector<array<int, 2>> diagonal[N];
int color[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            diagonal[i + j].push_back({i, j});
        }
    }

    for (int i = 1, j = 2; i <= n * n; ++i) {
        int a;
        cin >> a;

        int d = j;
        if (color[j] == a) {
            int k = j + 1;
            while (k <= 2 * n && diagonal[k].empty()) {
                ++k;
            }

            if (k <= 2 * n) {
                if (k == j + 1 && color[k] == 0) {
                    color[k] = color[k - 2];
                }
                d = k;
            } else {
                color[j] = 0;
            }
        }

        if (color[d] == 0) {
            ++color[d];
            while (color[d] == color[d - 1] || color[d] == color[d + 1] || color[d] == a) {
                ++color[d];
            }
        }

        auto [x, y] = diagonal[d].back();
        diagonal[d].pop_back();
        cout << color[d] << " " << x << " " << y << endl;

        while (j <= 2 * n && diagonal[j].empty()) {
            ++j;
        }
    }
}