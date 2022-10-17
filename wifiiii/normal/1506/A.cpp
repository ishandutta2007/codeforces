#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, m, x;
        cin >> n >> m >> x;
        ll a = (x - 1) / n, b = x % n;
        if(b == 0) b = n;
        cout << (b - 1) * m + a + 1 << endl;
    }
}