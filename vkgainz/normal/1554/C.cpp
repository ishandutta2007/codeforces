#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        if(m < n) {
            cout << 0 << "\n";
        }
        else {
            int x = 0;
            for(int i = 0; i < 30; i++) {
                if(! (n & (1 << i))) {
                    x += (1 << i);
                }
            }
            for(int i = 29; i >= 0; i--) {
                if(! (n & (1 << i))) {
                    if(x - (1 << i) > m - n) {
                        x -= (1 << i);
                    }
                }
            }
            cout << x << "\n";
        }
    }
}