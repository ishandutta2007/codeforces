#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll a, b, x, y, g;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b >> x >> y;
    g=__gcd(x, y);
    x/=g, y/=g;
    cout << min(a/x, b/y);
}