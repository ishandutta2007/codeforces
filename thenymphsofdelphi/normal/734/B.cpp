#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    int a, b, c, d, ans = 0;
    cin >> a >> b >> c >> d;
    ans += 256 * min(min(a, c), d);
    a -= min(min(a, c), d);
    ans += 32 * min(a, b);
    cout << ans;
}