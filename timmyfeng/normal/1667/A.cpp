#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(true);
    cin.tie(nullptr);

    int n; cin >> n;

    vector<int> a(n);
    for (auto &i : a) cin >> i;

    long long answer = LLONG_MAX;
    for (int i = 0; i < n; ++i) {
        long long target = 0, moves = 0;
        for (int j = i - 1; j >= 0; --j) {
            moves += target / a[j] + 1;
            target = a[j] * (target / a[j] + 1);
        }
        target = 0;
        for (int j = i + 1; j < n; ++j) {
            moves += target / a[j] + 1;
            target = a[j] * (target / a[j] + 1);
        }
        answer = min(answer, moves);
    }

    cout << answer << "\n";
}