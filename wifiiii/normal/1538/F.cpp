#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll solve(ll x) {
    ll ret = 0;
    while(x) {
        ret += x;
        x /= 10;
    }
    return ret;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        cout << solve(r) - solve(l) << '\n';
    }
}