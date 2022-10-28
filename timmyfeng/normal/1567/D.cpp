#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long s;
        cin >> s >> n;

        long long power = 1;
        multiset<long long> ans;
        while ((int) ans.size() < n - 1 && power < s) {
            if (s % (10 * power) == 0) {
                power *= 10;
            } else {
                s -= power;
                ans.insert(power);
            }
        }
        ans.insert(s);

        while ((int) ans.size() < n) {
            assert(ans.upper_bound(1) != ans.end());
            long long nxt = *ans.upper_bound(1);

            power = 1;
            while (power * 10 < nxt) {
                power *= 10;
            }

            ans.erase(ans.find(nxt));
            while ((int) ans.size() < n - 1 && nxt > power) {
                ans.insert(power);
                nxt -= power;
            }
            ans.insert(nxt);
        }

        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";
    }
}