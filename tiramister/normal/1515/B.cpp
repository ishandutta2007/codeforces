#include <iostream>

using namespace std;
using lint = long long;

bool issq(lint x) {
    lint l = 0, r = x + 1;
    while (r - l > 1) {
        auto m = (l + r) / 2;
        if (m * m <= x) {
            l = m;
        } else {
            r = m;
        }
    }

    return x == l * l;
}

void solve() {
    lint n;
    cin >> n;

    cout << ((n % 2 == 0 && issq(n / 2)) ||
                     (n % 4 == 0 && issq(n / 4))
                 ? "YES"
                 : "NO")
         << "\n";
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;
    while (q--) solve();

    return 0;
}