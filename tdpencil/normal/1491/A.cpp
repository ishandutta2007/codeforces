#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vt vector

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    vt<int> a(n);
    for(auto &e: a) cin >> e;
    int one = 0;
    for(auto &e: a) {
        if(e == 1) one++;
    }

    while(q--) {
        int x; cin >> x;
        if(x == 1) {
            int k; cin >> k;
            k--;
            if(a[k] == 1) {
                one--;
            } else {
                one++;
            }
            a[k]^=1;
        } else {
            int k; cin >> k;
            if(k <= one) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }
}