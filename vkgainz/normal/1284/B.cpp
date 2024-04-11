#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<pair<int, int>> in;
    int num = 0;
    for(int i = 0; i < n; i++) {
        int l; cin >> l;
        int mn = 1000000000, mx = 0;
        bool ascent = false;
        for(int j = 0; j < l; j++) {
            int s; cin >> s;
            if(s > mn) ascent = true;
            mn = min(mn, s);
            mx = max(mx, s);
        }
        if(ascent) {
            continue;
        }
        in.push_back({mn, mx});
        ++num;
    }
    vector<int> suf(1000002);
    for(auto [a, b] : in)
        ++suf[b];
    for(int i = 1000000; i >= 0; i--)
        suf[i] += suf[i + 1];
    long long ans = n * 1LL * n - (num * 1LL * num);
    for(auto [a, b] : in)
        ans += suf[a + 1];
    cout << ans;
}