#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        map<int, int> mp;
        for(int i : a) mp[i] += 1;
        vector<pair<int,int>> b;
        int s = 0;
        for(auto [x, y] : mp) {
            s += y;
            b.push_back({x, s});
        }
        // in - out >= k
        // out = n - in
        // 2 * in >= n + k
        int mn = 1e9, l = -1, r = -1;
        for(int i = 0; i < b.size(); ++i) {
            int pre = i ? b[i - 1].second : 0;
            int lo = i, hi = b.size();
            while(lo < hi) {
                int mid = (lo + hi) / 2;
                if((b[mid].second - pre) * 2 >= n + k) {
                    hi = mid;
                } else {
                    lo = mid + 1;
                }
            }
            if(lo == b.size()) {
                break;
            } else {
                if(b[lo].first - b[i].first < mn) {
                    mn = b[lo].first - b[i].first;
                    l = b[i].first;
                    r = b[lo].first;
                }
            }
        }
        cout << l << " " << r << '\n';
        int x = 0, y = 0, lst = 0;
        for(int i = 0; i < n; ++i) {
            if(l <= a[i] && a[i] <= r) {
                ++x;
            } else {
                ++y;
            }
            if(x == y + 1) {
                if(k > 1) {
                    --k;
                    cout << lst + 1 << " " << i + 1 << '\n';
                    lst = i + 1;
                    x = 0, y = 0;
                } else {
                    cout << lst + 1 << " " << n << '\n';
                    break;
                }
            }
        }
    }
}