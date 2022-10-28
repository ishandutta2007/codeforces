#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> r(n), b(n);
    for (int i = 0; i < n; ++i) {
        cin >> r[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    int hi = 100;
    int lo = 1;
    while (lo <= hi) {
        int mi = (lo + hi) / 2;
        int score1 = 0, score2 = 0;
        for (int i = 0; i < n; ++i) {
            if (r[i] && !b[i]) {
                score1 += mi;
            } else {
                score1 += r[i];
                score2 += b[i];
            }
        }
        if (score1 > score2) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    if (lo > 100) {
        cout << -1 << '\n';
    } else {
        cout << lo << '\n';
    }
}