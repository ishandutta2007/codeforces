#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int mod = 1e9+7;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll n, d;
    cin >> n >> d;
    ll l = 0, r = 0;
    int ans = 0;
    while(n--) {
        ll x;
        cin >> x;
        if(x == 0) {
            if(r < 0) {
                ++ans;
                l = 0, r = d;
            } else {
                l = max(l, 0ll);
            }
        } else {
            l += x;
            r += x;
            r = min(r, d);
            if(l > d) return cout << -1 << endl, 0;
        }
    }
    cout << ans << endl;
}