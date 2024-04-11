#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ll n;
    cin >> n;
    for(int tt= 0; tt < n; tt++) {
        ll x, y, h;
        cin >> x >> y >> h;


        ll ans = 1;

        while(x % 2 == 0) {
            ans *= 2;
            x /= 2;
        }

        while(y % 2 == 0) {
            ans *= 2;
            y /= 2;
        }

        cout << (ans >= h ? "YES\n":"NO\n");
    }
}