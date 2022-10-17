#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int l, r, a;
        cin >> l >> r >> a;
        // x/a x%a
        // r%a
        int x = max(l, r / a * a - 1);
        cout << max(r / a + r % a, x / a + x % a) << '\n';
    }
}