#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x;
        cin >> x;
        cout << 100 / gcd(x, 100) << '\n';
    }
}