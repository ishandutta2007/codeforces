#include <bits/stdc++.h>
using namespace std;

const int N = 300;

int length[N], cost[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> length[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> cost[i];
    }

    map<int, int> gcd = {{0, 0}};
    for (int i = 0; i < n; ++i) {
        map<int, int> new_gcd = gcd;
        for (auto [l, c] : gcd) {
            int new_length = __gcd(l, length[i]);
            if (new_gcd.count(new_length) == 0) {
                new_gcd[new_length] = c + cost[i];
            } else {
                new_gcd[new_length] = min(new_gcd[new_length], c + cost[i]);
            }
        }
        swap(gcd, new_gcd);
    }

    cout << (gcd.count(1) == 0 ? -1 : gcd[1]) << "\n";
}