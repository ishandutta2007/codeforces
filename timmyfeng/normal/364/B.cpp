#include <bits/stdc++.h>
using namespace std;

const int NC = 1e6;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d; cin >> n >> d;

    bitset<NC> sums;
    sums[0] = 1;

    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        sums |= sums << c;
    }

    int sum = 0, days = 0;
    while (true) {
        int next_sum = -1;
        for (int i = sum + d; i > sum; --i) {
            if (sums[i]) {
                next_sum = i;
                break;
            }
        }

        if (next_sum == -1) {
            break;
        }
        sum = next_sum;
        ++days;
    }

    cout << sum << " " << days << "\n";
}