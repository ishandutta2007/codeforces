#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        if(x % 2 == 0) {
            cout << (x - 1) / 2 << " " << (x - 1) / 2 + 1 << " " << 1 << '\n';
        } else {
            for(ll i = 3; i <= x; ++i) {
                if(gcd(i, x - i - 1) == 1) {
                    cout << i << " " << x - i - 1 << " " << 1 << '\n';
                    break;
                }
            }
        }
    }
}