#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll x;
        cin >> x;
        ll p = (1ll << (63 - __builtin_clzll(x))) - 1;
        cout << p << endl;
    }
}