#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int n, x, y, ans = -1;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        ans = max(ans, x + y);
    }
    cout << ans;
}