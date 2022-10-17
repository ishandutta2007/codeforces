#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n), ans(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        int cur = 0;
        for(int i = 0; i < n - 1; ++i) {
            int p = abs(a[i] + cur) < abs(cur - a[i]) ? 1 : -1;
            cur = p * a[i] + cur;
            ans[i] = p;
        }
        if(cur == 0) {
            cur += a[n - 2] * ans[n - 2];
            ans[n - 2] *= 2;
        }
        for(int i = 0; i < n - 1; ++i) {
            ans[i] *= a[n - 1];
        }
        ans[n - 1] = -cur;
        for(int i = 0; i < n; ++i) cout << ans[i] << " "; cout << '\n';
    }
}