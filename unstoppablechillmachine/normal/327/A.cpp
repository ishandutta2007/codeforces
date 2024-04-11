#include <iostream>

using namespace std;

const int sz = 200100;

int a[sz];

void solve() {
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        cnt += a[i];
    }
    int ans = cnt - 1;
    for (int i = 0; i < n; ++i) {
        int bal = 0;
        for (int j = i; j < n; ++j) {
            if (a[j] == 0) {
                ++bal;
            } else {
                --bal;
            }
            ans = max(ans, cnt + bal);
        }
    }
    cout << ans << '\n';
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
}