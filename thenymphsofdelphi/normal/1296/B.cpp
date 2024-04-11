#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 2e5 + 5, inf = 1e18 + 7;

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int q = 1;
cin >> q;
while (q--){
    int ans = 0, n;
    cin >> n;
    while (n >= 10){
        int t = 1, m = n;
        while (m >= 10){
            t *= 10;
            m /= 10;
        }
        t *= m;
        ans += t;
        n -= t;
        n += t / 10;
    }
    ans += n;
    cout << ans << endl;
}
}