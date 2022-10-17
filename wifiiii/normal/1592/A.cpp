#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        int x = a.back();
        a.pop_back();
        int y = a.back();
        int ans = h / (x + y) * 2;
        h %= x + y;
        if(h > 0) {
            if(h <= x) ans += 1;
            else ans += 2;
        }
        cout << ans << '\n';
    }
}