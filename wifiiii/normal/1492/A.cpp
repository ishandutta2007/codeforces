#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll p;
        cin >> p;
        ll ans = 8e18;
        ll a;
        cin >> a;
        ans = min(ans, (p + a - 1) / a * a);
        cin >> a;
        ans = min(ans, (p + a - 1) / a * a);
        cin >> a;
        ans = min(ans, (p + a - 1) / a * a);
        cout << ans - p << endl;
    }
}