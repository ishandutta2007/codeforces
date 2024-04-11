#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> cnt(m);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[x % m] += 1;
        }
        int ans = 0;
        for(int i = 1; i <= m - i; ++i) {
            if(cnt[i] || cnt[m - i]) ans += max(1, max(cnt[m - i], cnt[i]) - min(cnt[m - i], cnt[i]));
        }
        if(cnt[0]) ++ans;
        cout << ans << '\n';
    }
}