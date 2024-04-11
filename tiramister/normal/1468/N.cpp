#line 1 "main.cpp"
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void solve() {
    vector<int> cs(3);
    for (auto& c : cs) cin >> c;

    bool judge = true;
    for (int i = 0; i < 3; ++i) {
        int x;
        cin >> x;
        if ((cs[i] -= x) < 0) judge = false;
    }

    for (int i = 0; i < 2; ++i) {
        int x;
        cin >> x;

        int d = min(cs[i], x);
        cs[i] -= d;
        x -= d;

        cs[2] -= x;
    }

    if (any_of(cs.begin(), cs.end(),
               [](auto x) { return x < 0; })) judge = false;

    cout << (judge ? "YES" : "NO") << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}