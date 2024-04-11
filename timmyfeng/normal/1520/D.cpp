#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long ans = 0;
        map<int, int> tally;
        for (int i = 0; i < n; ++i) {
            int a;
            cin >> a;
            ans += tally[a - i]++;
        }

        cout << ans << "\n";
    }
}