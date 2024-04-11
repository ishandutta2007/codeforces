#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set

using ll = long long;

using namespace std;

void solve(){
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll x = x2 - x1;
    ll y = y2 - y1;
    ll m = min(x, y);
    ll d = abs(x-y);
    cout << (m+d)*(m)+1 << endl;
}

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}