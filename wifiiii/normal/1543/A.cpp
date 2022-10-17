#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll a, b;
        cin >> a >> b;
        ll m = abs(a - b);
        if(m == 0) cout << 0 << " " << 0 << '\n';
        else cout << m << " " << min(a % m, m - a % m) << '\n';
    }
}