#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    map<int, int> cnt[2];
    cnt[1][0] = 1;
    int n;
    cin >> n;
    ll ans = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        sum ^= x;
        ans += cnt[i & 1][sum]++;
    }
    cout << ans << endl;
    exit(0);
}