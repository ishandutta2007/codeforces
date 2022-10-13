#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    multiset<long long> in;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        in.insert(a[i]);
    }
    int ans = 0;
    while (!in.empty()) {
        auto it = in.begin();
        int curr = (*it);
        if (in.count(curr * 1LL * x)) {
            in.erase(in.lower_bound(curr * 1LL * x));
            in.erase(it);
        } else {
            in.erase(it);
            ++ans;
        }
    }
    cout << ans << "\n";
}

int main() {
    int t; cin >> t;
    while (t--) solve();
}