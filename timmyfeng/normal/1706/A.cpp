#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        string answer(m, 'B');
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            a = min(a, m + 1 - a);
            if (answer[a - 1] == 'B') {
                answer[a - 1] = 'A';
            } else {
                answer[m - a] = 'A';
            }
        }
        cout << answer << "\n";
    }
}