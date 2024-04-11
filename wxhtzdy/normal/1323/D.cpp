#include <bits/stdc++.h>
using namespace std;

int get(vector<int>& v, int x) {
        auto it = upper_bound(v.begin(), v.end(), x); return it - v.begin();
}

int cnt(vector<int>& v, int l, int r) {
        return get(v, r - 1) - get(v, l - 1);
}

int main() {
        ios::sync_with_stdio(false);
        cin.tie(0);
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
                cin >> a[i];
        int ans = 0;
        for (int i = 0; i < 30; i++) {
                vector<int> v;
                for (int x : a) v.push_back(x % (1 << (i + 1)));
                sort(v.begin(), v.end());
                long long tmp = 0;
                for (int x : v) {
                        tmp += cnt(v, (1 << i) - x, (2 << i) - x);
                        tmp += cnt(v, (3 << i) - x, (4 << i) - x);
                        if ((2 * x) & (1 << i)) {
                                tmp--;
                        }
                }
                tmp /= 2;
                if (tmp & 1) ans ^= 1 << i;
        }
        cout << ans;
        return 0;
}