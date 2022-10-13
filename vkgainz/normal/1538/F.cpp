#include <bits/stdc++.h>
using namespace std;

int ch(int x) {
    int ans = 0;
    for(int i = 0; i < 10; i++) {
        ans += x;
        x /= 10;
    }
    return ans;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int l, r; cin >> l >> r;
        cout << ch(r) - ch(l) << "\n";
    }
}