#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int a, b; cin >> a >> b;

        int n = a + b;
        set<int> answer;
        for (auto serves : {n / 2, (n + 1) / 2}) {
            for (int k = 0; k <= min({a, b, n / 2}); ++k) {
                answer.insert(abs(serves - a) + 2 * k);
            }
        }

        cout << answer.size() << "\n";
        for (auto &i : answer)
            cout << i << " ";
        cout << "\n";
    }
}