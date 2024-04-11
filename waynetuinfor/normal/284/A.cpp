#include <bits/stdc++.h>
using namespace std;

int p;

bool check(int x) {
    bool ok = true;
    int k = 1;
    for (int i = 1; i <= p - 2; ++i) {
        k *= x; k %= p;
        // cout << k << endl;
        if ((k - 1 + p) % p == 0) return false;
    }
    k *= x; k %= p;
    // cout << k << endl;
    if ((k - 1 + p) % p == 0) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> p;
    int ans = 0;
    for (int i = 1; i <= p; ++i) if (check(i)) ++ans;
    cout << ans << endl;
    return 0;
}