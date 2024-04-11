#include <iostream>

using namespace std;

typedef long long ll;

const int sz = 300100;

int a[sz];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 1e9;
    for (int it = 0; it < n; ++it) {
        ans = min(ans,a[it] / max(it, n - it - 1));
    }
    cout << ans << '\n';
}
int main() {
    int t = 1;
    while (t--) {
        solve();
    }
}