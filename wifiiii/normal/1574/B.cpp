#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        int r = a - 1 + b - 1 + c - 1;
        int l = max(0, 2 * max({a, b, c}) - a - b - c - 1);
        if(l <= m && m <= r) cout << "yes\n";
        else cout << "no\n";
    }
}