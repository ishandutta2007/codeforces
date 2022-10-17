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
        vector<vector<int>> a(n + 1, vector<int>(n + 1));
        for(int i = 0; i < n; ++i) {
            int l, r;
            cin >> l >> r;
            a[l][r] = 1;
        }
        function<void(int,int)> solve = [&](int l, int r) {
            for(int i = l; i <= r; ++i) {
                if((i - 1 < l || a[l][i - 1]) && (i + 1 > r || a[i + 1][r])) {
                    cout << l << " " << r << " " << i << '\n';
                    if(i - 1 >= l) solve(l, i - 1);
                    if(i + 1 <= r) solve(i + 1, r);
                }
            }
        };
        solve(1, n);
    }
}