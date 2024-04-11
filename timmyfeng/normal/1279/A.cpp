#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int mx = max({a, b, c});
        cout << (a + b + c - mx >= mx - 1 ? "Yes\n" : "No\n");
    }
}