#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    int a;
    cin >> a;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    multiset<int> s;
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        s.insert(c[i]);
        while (k < x[i]) {
            if (s.size() > 0) {
                auto it = s.begin();
                k += a;
                ans += *it;
                s.erase(it);
            } else {
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}