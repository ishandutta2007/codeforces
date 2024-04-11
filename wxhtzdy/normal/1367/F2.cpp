#include <bits/stdc++.h>

using namespace std;
using ld = long double;
using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        a[i] = {v[i], i};
    }
    sort(a.begin(), a.end());
    vector<int> p(n);
    int j = 0;
    unordered_multiset<int> next;
    for (int i = 0; i < n; i++) {
        if (i > 0 && a[i].first != a[i - 1].first) {
            j++;
        }
        p[a[i].second] = j;
        next.insert(j);
    }
    unordered_map<int, int> d;
    vector<int> dp1(n), dp2(n), dp3(n), cnt(n);
    for (int i = 0; i < n; i++) {
        if (next.count(p[i])) {
            next.erase(next.find(p[i]));
        }
        if (d.count(p[i] - 1)) {
            if (!d.count(p[i])) {
                dp2[i] = max(dp2[i], dp1[d[p[i] - 1]] + 1);
                if (!next.count(p[i] - 1)) {
                    dp2[i] = max(dp2[i], dp2[d[p[i] - 1]] + 1);
                }
            }
            if (!next.count(p[i] - 1)) {
                dp3[i] = max(dp3[i], dp2[d[p[i] - 1]] + 1);
            }
            dp3[i] = max(dp3[i], dp1[d[p[i] - 1]] + 1);
        }
        if (d.count(p[i])) {
            dp3[i] = max(dp3[i], dp3[d[p[i]]] + 1);
            dp2[i] = max(dp2[i], dp2[d[p[i]]] + 1);
            dp1[i] = dp1[d[p[i]]] + 1;
        } else {
            dp1[i] = 1;
        }
        dp2[i] = max(dp2[i], dp1[i]);
        dp3[i] = max(dp3[i], dp2[i]);
        d[p[i]] = i;
    }
    cout << n - *max_element(dp3.begin(), dp3.end()) << "\n";
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        solve();
    }
}