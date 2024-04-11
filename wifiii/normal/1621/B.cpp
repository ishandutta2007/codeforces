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
        int L = INT_MAX, R = INT_MIN, ml = -1, mr = -1;
        map<pair<int,int>, int> mp;
        for(int i = 0; i < n; ++i) {
            int l, r, x;
            cin >> l >> r >> x;
            if(l < L || (l == L && ml > x)) {
                L = l;
                ml = x;
            }
            if(r > R || (r == R && mr > x)) {
                R = r;
                mr = x;
            }
            if(!mp.count({l, r})) {
                mp[{l, r}] = x;
            } else {
                mp[{l, r}] = min(mp[{l, r}], x);
            }
            int ans = ml + mr;
            if(mp.count({L, R})) ans = min(ans, mp[{L, R}]);
            cout << ans << '\n';
        }
    }
}