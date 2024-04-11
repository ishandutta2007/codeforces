#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

long long solve(vector<int> &x, int k) {
    if (x.empty()) {
        return 0LL;
    }
    int l = x.size() - 1;
    long long ans = 0LL;
    while (l >= 0) {
        int lst = x[l];
        l = l - k;
        ans += 2 * lst;
    }
    ans -= x.back();
    return ans;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        vector<int> pos, neg;
        vector<int> x(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i];
            if (x[i] > 0) {
                pos.push_back(x[i]);
            } else if (x[i] < 0) {
                neg.push_back(-x[i]);
            }
        }
        sort(pos.begin(), pos.end());
        sort(neg.begin(), neg.end());
        long long r = solve(pos, k),
             s = solve(neg, k);
        long long ans = r + s;
        if (!neg.empty() && !pos.empty()) {
            ans += min(neg.back(), pos.back());
        }
        cout << ans << "\n";
    }
}