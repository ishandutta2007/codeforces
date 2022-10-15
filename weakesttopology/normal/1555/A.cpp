#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    const int L = lcm(lcm(6, 8), 10), small = 3 * L;
    vector<bool> can(small + 1);
    can[0] = true;
    for (int x = 0; x < small; ++x) {
        if (!can[x]) continue;
        for (int add : {6, 8, 10}) {
            int y = x + add;
            if (y <= small) can[y] = true;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long take = max(0LL, (n - small + L - 1) / L) * L;
        long long ans = take;
        n -= take;
        while (!can[n]) ++n;
        ans += n;
        ans = (ans * 25) / 10;
        cout << ans << '\n';
    }
    exit(0);
}