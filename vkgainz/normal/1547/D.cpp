#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> x(n);
        int curr = (1 << 30) - 1;
        for(int i = 0; i < n; i++) {
            cin >> x[i];
        }
        vector<int> y(n);
        y[0] = 0;
        curr = x[0];
        for(int i = 1; i < n; i++) {
            //take min y[i] s.t. x[i] ^ y[i] is a submsk of curr
            int diff = (x[i] | curr) ^ x[i];
            y[i] = diff;
            curr = x[i] ^ y[i];
        }
        for(int i = 0; i < n; i++) {
            cout << y[i] << " ";
        }
        cout << "\n";
    }
}