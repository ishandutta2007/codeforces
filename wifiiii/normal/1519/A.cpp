#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll r, b, d;
        cin >> r >> b >> d;
        cout << (min(r, b) * d >= abs(r - b) ? "YES" : "NO") << '\n';
    }
}