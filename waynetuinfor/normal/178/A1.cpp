#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> v;
    for (int i = 1; i < maxn; i <<= 1) v.push_back(i);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        int t = (--upper_bound(v.begin(), v.end(), n - i)) - v.begin();
        a[i + (1 << t)] += a[i];
        ans += a[i];
        cout << ans << endl;
    }
    return 0;
}