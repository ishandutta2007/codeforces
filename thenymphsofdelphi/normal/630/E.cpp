#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int a = (x2 - x1) / 2 + 1, b = (y2 - y1) + 1;
    int ans = (a + a - 1) * (b / 2);
    if (b & 1){
        ans += a;
    }
    cout << ans;
}