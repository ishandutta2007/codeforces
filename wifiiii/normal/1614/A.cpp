#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, l, r, k;
        cin >> n >> l >> r >> k;
        vector<int> a;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(l <= x && x <= r) {
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = 0; i < a.size(); ++i) {
            k -= a[i];
            if(k < 0) break;
            ans += 1;
        }
        cout << ans << '\n';
    }
}