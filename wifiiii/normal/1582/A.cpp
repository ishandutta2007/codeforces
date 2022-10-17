#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b, c;
        cin >> a >> b >> c;
        ll s = a + 1ll * 2 * b + 1ll * 3 * c;
        cout << (s & 1) << '\n';
    }
}