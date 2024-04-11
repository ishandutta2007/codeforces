#include<bits/stdc++.h>
using namespace std;

#define int long long
#define fi first
#define se second

const int N = 1e3 + 5;



signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q; cin >> q;
    while (q--){
        int n, k; cin >> n >> k;
        int ans = n / k * k;
        ans += min(n % k, k / 2);
        cout << ans << endl;
    }
}