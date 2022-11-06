

#include <bits/stdc++.h>
using namespace std;
//
const int maxn = 100 + 5;
string a[maxn], b[maxn];

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    int ans = 0;
    for (int k = 1; k <= 4; ++k) {
        vector<string> sa, sb;
        for (int i = 0; i < n; ++i) if (a[i].size() == k) sa.push_back(a[i]);
        for (int i = 0; i < n; ++i) if (b[i].size() == k) sb.push_back(b[i]);
        map<string, int> ca, cb;
        for (auto i : sa) ++ca[i];
        for (auto i : sb) ++cb[i];
        for (auto &i : cb) {
            int x = min(ca[i.first], i.second);
            i.second -= x;
            ca[i.first] -= x;
        }
        for (auto i : ca) ans += i.second;
    }
    cout << ans << endl;
}