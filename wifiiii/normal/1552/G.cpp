#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    if(n == 1) return cout << "ACCEPTED" << endl, 0;
    vector<ll> a;
    for(int i = 0; i < k; ++i) {
        int m;
        cin >> m;
        ll x = 0;
        for(int j = 0; j < m; ++j) {
            int p;
            cin >> p;
            --p;
            x |= 1ll << p;
        }
        a.push_back(x);
    }
    function<void(int,ll,ll)> dfs = [&](int p, ll cur, ll vis) {
        if(p == k) {
            if(vis != (1ll << n) - 1 || __builtin_popcountll(cur + 1) != 1) {
                cout << "REJECTED" << endl;
                exit(0);
            }
            return;
        }
        int cnt_one = __builtin_popcountll(cur & a[p]);
        int cnt_first_visit = __builtin_popcountll(~vis & a[p]);
        vis |= a[p];
        ll nxt = cur & ~a[p], mask = a[p];
        for(int i = 0; i <= cnt_one + cnt_first_visit; ++i) {
            if(i >= cnt_one) dfs(p + 1, nxt, vis);
            ll low_bit = mask & -mask;
            mask ^= low_bit;
            nxt ^= low_bit;
        }
    };
    dfs(0, 0, 0);
    cout << "ACCEPTED" << endl;
}