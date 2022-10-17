#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> b;
        for(int i = 0, j = 0; i < n; i = j) {
            while(j < n && a[i] == a[j]) ++j;
            b.push_back(j - i);
        }
        vector<int> s(b.size() + 1);
        for(int i = 0; i < b.size(); ++i) {
            s[i + 1] = s[i] + b[i];
        }
        auto d = [&](int x) {
            if(x == 0) return 1;
            if(x <= 2) return 0;
            return (1 << (32 - __builtin_clz(x - 1))) - x;
        };
        int ans = 1e9, res = n;
        for(int i = 0; i <= b.size(); ++i) {
            for(int j = 0; j < 20; ++j) {
                int p = upper_bound(s.begin(), s.begin() + i + 1, 1 << j) - s.begin() - 1;
                if(p < 0) ans = min(ans, d(res) + d(0) + d(n - res));
                else ans = min(ans, d(res) + d(s[p]) + d(n - res - s[p]));
            }
            if(i < b.size()) res -= b[i];
        }
        cout << ans << '\n';
    }
}