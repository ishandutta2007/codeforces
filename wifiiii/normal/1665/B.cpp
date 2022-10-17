#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            mx = max(mx, ++mp[x]);
        }
        int ans = n - mx;
        while(mx < n) {
            mx *= 2;
            ans += 1;
        }
        cout << ans << '\n';
    }
}