#include<bits/stdc++.h>
using namespace std;
#define int long long

const int inf = 2e9;

signed main(){
    int n, x, y, minr1 = inf, maxl1 = -1, minr2 = inf, maxl2 = -1;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        maxl1 = max(maxl1, x);
        minr1 = min(minr1, y);
    }
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x >> y;
        maxl2 = max(maxl2, x);
        minr2 = min(minr2, y);
    }
    cout << max(0ll, max(maxl2 - minr1, maxl1 - minr2));
}