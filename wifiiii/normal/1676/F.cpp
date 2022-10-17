#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        map<int, int> mp;
        for(int i : a) mp[i]++;
        int pre = -1, cnt = 0;
        int l = -1, r = -2;
        for(auto [x, y] : mp) {
            if(x == pre + 1 && y >= m) {
                cnt += 1;
            } else {
                cnt = 1;
            }
            if(y >= m) pre = x;
            else cnt = 0;
            if(cnt > r - l + 1) {
                l = x - cnt + 1;
                r = x;
            }
        }
        if(l == -1) {
            cout << -1 << '\n';
        } else {
            cout << l << ' ' << r << '\n';
        }
    }
}