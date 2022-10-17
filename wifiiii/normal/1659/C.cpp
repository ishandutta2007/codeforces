#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> p(n);
        for(int i = 0; i < n; ++i) cin >> p[i];
        ll sum = 0;
        for(int i = 0; i < n; ++i) sum += 1ll * p[i] * b;
        int pre = 0;
        for(int i = 0; i < n; ++i) {
            // pre -> p[i]
            ll cost = 1ll * (p[i] - pre) * a;
            // i + 1 ... n - 1 (n - 1 - i) * (p[i] - pre) * b
            ll profit = 1ll * b * (n - 1 - i) * (p[i] - pre);
            if(profit > cost) {
                sum -= profit - cost;
                pre = p[i];
            } else {
                break;
            }
        }
        cout << sum << '\n';
    }
}