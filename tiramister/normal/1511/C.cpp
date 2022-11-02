#include <iostream>
#include <vector>

using namespace std;

constexpr int C = 50;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> cs(C, -1);
    for (int i = 1; i <= n; ++i) {
        int c;
        cin >> c;
        --c;
        if (cs[c] == -1) cs[c] = i;
    }

    while (q--) {
        int c;
        cin >> c;
        --c;

        cout << cs[c] << " ";
        for (auto& p : cs) {
            if (p < cs[c]) ++p;
        }
        cs[c] = 1;
    }
    cout << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    solve();

    return 0;
}