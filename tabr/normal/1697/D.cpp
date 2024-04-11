#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    auto Ask1 = [&](int i) {
        cout << "? 1 " << i + 1 << endl;
        char c;
        cin >> c;
        return c;
    };
    auto Ask2 = [&](int l, int r) {
        cout << "? 2 " << l + 1 << " " << r + 1 << endl;
        int t;
        cin >> t;
        return t;
    };
    vector<int> last(26, -1);
    int tc = Ask2(0, n - 1);
    for (int i = 1; i <= tc; i++) {
        int low = -1;
        int high = n - 1;
        while (high - low > 1) {
            int mid = (high + low) >> 1;
            if (Ask2(0, mid) >= i) {
                high = mid;
            } else {
                low = mid;
            }
        }
        char c = Ask1(high);
        last[c - 'a'] = high;
    }
    string ans;
    for (int i = 0; i < n; i++) {
        vector<pair<int, char>> t;
        for (int j = 0; j < 26; j++) {
            if (last[j] != -1 && last[j] <= i) {
                t.emplace_back(last[j], (char) ('a' + j));
            }
        }
        sort(t.begin(), t.end());
        if (t.back().first == i) {
            ans.push_back(t.back().second);
        } else {
            int low = 0;
            int high = (int) t.size();
            while (high - low > 1) {
                int mid = (high + low) >> 1;
                if (Ask2(t[mid].first, i) == (int) t.size() - mid) {
                    low = mid;
                } else {
                    high = mid;
                }
            }
            ans.push_back(t[low].second);
        }
        last[ans.back() - 'a'] = i;
    }
    cout << "! " << ans << endl;
    return 0;
}