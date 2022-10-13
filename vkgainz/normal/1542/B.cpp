#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, a, b; cin >> n >> a >> b;
        if(a == 1) {
            if((n - 1) % b == 0) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
        else {
            int curr = 1;
            bool work = false;
            while(curr * 1LL * a <= n) {
                work |= (n - curr) % b == 0;
                curr *= a;
            }
            work |= (n - curr) % b == 0;
            if(work) cout << "Yes" << "\n";
            else cout << "No" << "\n";
        }
    }
}