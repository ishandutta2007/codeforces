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
        int ans = 0;
        for(int s = 0; s < n; ++s) {
            if(s && a[s] == a[s-1]) continue;
            int p = s, cnt = 1;
            while(p < n) {
                int nxt = lower_bound(a.begin() + p + 1, a.end(), a[p] + (a[p] - a[s])) - a.begin();
                if(nxt == n) break;
                cnt += 1;
                p = nxt;
            }
            ans = max(ans, cnt);
        }
        cout << n - ans << '\n';
    }
}