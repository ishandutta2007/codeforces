#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> s(n);
        multiset<string> all;
        for (auto& i : s) {
            cin >> i;
            all.insert(i);
        }

        int ans = 0;
        for (auto& i : s) {
            all.erase(all.find(i));
            ans += (all.count(i) > 0);
            while (all.count(i)) {
                i[0] = ((i[0] - '0' + 1) % 10) + '0';
            }
            all.insert(i);
        }
        cout << ans << '\n';
        for (auto& i : s) {
            cout << i << '\n';
        }
    }
}