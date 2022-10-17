#include <bits/stdc++.h>
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
        if(accumulate(a.begin(), a.end(), 0) & 1) {
            cout << "NO\n";
            continue;
        }
        vector<int> ans;
        auto solve = [&](int l, int r) {
            assert((r - l + 1) & 1);
            for(int i = l; i + 2 <= r; i += 2) ans.push_back(i);
            for(int i = r - 4; i >= l; i -= 2) ans.push_back(i);
        };
        if(n & 1) {
            cout << "YES" << endl;
            solve(0, n - 1);
            cout << ans.size() << '\n';
            for(int i : ans) cout << i + 1 << " "; cout << '\n';
        } else {
            int x = 0, ok = 0;
            for(int i = 0; i < n; ++i) {
                x ^= a[i];
                if(i % 2 == 0 && x == 0) {
                    ok = 1;
                    solve(0, i);
                    solve(i + 1, n - 1);
                    break;
                }
            }
            if(ok) {
                cout << "YES" << endl;
                cout << ans.size() << '\n';
                for(int i : ans) cout << i + 1 << " "; cout << '\n';
            } else {
                cout << "NO" << endl;
            }
        }
    }
}