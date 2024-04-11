#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        auto ask = [&](int l, int r) {
            cout << "? " << l << " " << r << endl;
            ll ret;
            cin >> ret;
            return ret;
        };
        int lo = 1, hi = n;
        while(lo < hi) {
            int mid = (lo + hi) / 2;
            if(ask(mid, n)) lo = mid + 1;
            else hi = mid;
        }
        // [1, lo]
        ll right_length = ask(1, n) - ask(1, lo - 1) + 1;
        // k = lo, j = k - right_length + 1
        ll k = lo, j = k - right_length + 1;
        // [1, j - 1]
        ll left_length = ask(1, j - 1) - ask(1, j - 2) + 1;
        ll i = j - left_length;
        cout << "! " << i << " " << j << " " << k << endl;
    }
}