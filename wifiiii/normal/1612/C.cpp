#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll k, x;
        cin >> k >> x;
        // 1, 2, ..., k, k - 1, ..., 1
        ll tot = k * (k + 1) / 2 + k * (k - 1) / 2;
        if(tot < x) {
            cout << 2 * k - 1 << '\n';
        } else if(k * (k + 1) / 2 >= x) {
            ll lo = 1, hi = k;
            while(lo < hi) {
                ll mid = (lo + hi) / 2;
                if(mid * (mid + 1) / 2 >= x) hi = mid;
                else lo = mid + 1;
            }
            cout << lo << '\n';
        } else {
            ll lo = 1, hi = k - 1, pre = k * (k + 1) / 2;
            while(lo < hi) {
                ll mid = (lo + hi + 1) / 2;
                if((k - 1 + mid) * (k - 1 - mid + 1) / 2 + pre >= x) lo = mid;
                else hi = mid - 1;
            }
            cout << (k - lo) + k << '\n';
        }
    }
}