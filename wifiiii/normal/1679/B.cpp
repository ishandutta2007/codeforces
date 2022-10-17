#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> tim(n);
    int s = -1, t = 0;
    ll sum = 0;
    for(int i : a) sum += i;
    while(q--) {
        int op;
        cin >> op;
        if(op == 1) {
            int p, x;
            cin >> p >> x;
            --p;
            if(tim[p] != t) {
                a[p] = s;
                tim[p] = t;
            }
            sum -= a[p];
            a[p] = x;
            sum += a[p];
        } else {
            int x;
            cin >> x;
            s = x;
            sum = 1ll * n * x;
            ++t;
        }
        cout << sum << '\n';
    }
}