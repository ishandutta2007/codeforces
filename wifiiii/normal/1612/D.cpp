#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(int a, int b, int x) {
    int ok = 0;
    set<pair<ll,ll>> vis;
    function<void(ll,ll)> gcd = [&](ll a, ll b) {
        if(vis.count({a,b})) return;
        vis.insert({a,b});
        ll g = abs(a - b);
        if(a == x || b == x) ok = 1;
        gcd(a, g);
        gcd(b, g);
    };
    gcd(a, b);
    return ok;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll a, b, x;
        cin >> a >> b >> x;
        int ok = 0;
        function<ll(ll,ll)> gcd = [&](ll a, ll b) {
            if(a < b) swap(a, b);
            ll g = a - b;
            if(a == x || b == x) ok = 1;
            if(g && x <= a && (a - x) % g == 0) ok = 1;
            if(b && x <= g && (a - x) % b == 0) ok = 1;
            return b == 0 ? a : gcd(b, a % b);
        };
        gcd(a, b);
        cout << (ok ? "YES" : "NO") << '\n';
    }
}