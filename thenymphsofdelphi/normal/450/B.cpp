#include<bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9 + 7;

signed main(){
    int x, y, n, ans;
    cin >> x >> y >> n;
    n--;
    switch (n % 6){
        case 0: ans = x; break;
        case 1: ans = y; break;
        case 2: ans = y - x; break;
        case 3: ans = -x; break;
        case 4: ans = -y; break;
        case 5: ans = x - y; break;
    }
    ans %= mod;
    if (ans < 0){
        ans += mod;
    }
    cout << ans;
}