#include<bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        long long a, b; cin >> a >> b;
        long long d = abs(a - b);
        if(d == 0) {
            cout << 0 << " " << 0 << "\n";
            continue;
        }
        long long num = min(a % d , d - a % d);
        cout << d << " " << num << "\n";
    }
}