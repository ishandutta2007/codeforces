#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        if (n == 1) {
            cout << "Bob" << endl;
            continue;
        }
        ll p = 2;
        while (p * 4 <= n) p *= 4;
        string ans = (p == n) || (n - p) % 2 ? "Bob" : "Alice";
        cout << ans << endl;
    }
    exit(0);
}