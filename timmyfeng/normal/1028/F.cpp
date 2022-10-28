#include <bits/stdc++.h>
using namespace std;

array<long long, 2> simplify(long long x, long long y) {
    long long gcd = __gcd(x, y);
    return {x / gcd, y / gcd};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    map<long long, set<array<long long, 2>>> ring;
    map<array<long long, 2>, int> match;
    int m = 0;

    for (int i = 0; i < n; ++i) {
        int t;
        long long x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            ++m;
            for (auto [x0, y0] : ring[x * x + y * y]) {
                match[simplify(x + x0, y + y0)] += 2;
            }
            ++match[simplify(x, y)];
            ring[x * x + y * y].insert({x, y});
        } else if (t == 2) {
            ring[x * x + y * y].erase({x, y});
            --match[simplify(x, y)];
            for (auto [x0, y0] : ring[x * x + y * y]) {
                match[simplify(x + x0, y + y0)] -= 2;
            }
            --m;
        } else {
            cout << m - match[simplify(x, y)] << "\n";
        }
    }
}