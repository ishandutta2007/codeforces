#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int sum = 0;
        bool good = false;
        auto bt = [&](auto& self, int i) -> void {
            if (i == n) return;
            for (int sgn : {+1, -1}) {
                sum += a[i] * sgn;
                if (sum == 0) good = true;
                self(self, i + 1);
                sum -= a[i] * sgn;
            }
            self(self, i + 1);
        };
        bt(bt, 0);
        cout << (good ? "YES" : "NO") << '\n';
    }
    exit(0);
}