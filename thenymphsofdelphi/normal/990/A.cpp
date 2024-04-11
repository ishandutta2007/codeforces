#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    int t = n / m;
    t *= m;
    int ans = b * (n - t);
    t += m;
    ans = min(ans, a * (t - n));
    cout << ans;
}