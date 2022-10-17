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
        int ans = n - 1;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                int cnt = 0;
                for(int k = 0; k < n; ++k) {
                    if((a[k] - a[i]) * (j - i) != (a[j] - a[i]) * (k - i)) ++cnt;
                    if(cnt >= ans) break;
                }
                ans = min(ans, cnt);
            }
        }
        cout << ans << '\n';
    }
}