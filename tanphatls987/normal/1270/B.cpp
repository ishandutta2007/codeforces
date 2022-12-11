#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, a[N];
void solve() {
    for(int i = 2; i <= n; i++) if (abs(a[i] - a[i - 1]) >= 2) {
        cout << "YES\n";
        cout << i - 1 << " " << i << '\n';
        return;
    }
    cout << "NO\n";
}
int main() {
    int test;
    cin >> test;
    while (test--) {
        cin >> n;
        for(int i = 1; i <= n; i++) cin >> a[i];
        solve();
    }
}