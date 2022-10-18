#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 2e5 + 5;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q = 1;
    cin >> q;
    while (q--){
        int x, y; cin >> x >> y;
        int ans = (y / x + 1) * (y / x + 1) * (y % x) + (y / x) * (y / x) * (x - y % x);
        cout << ans << endl;
    }
}