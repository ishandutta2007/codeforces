#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        auto solve = [&](int qwq) {
            int m = *max_element(a.begin(), a.end()) + qwq;
            ll lo = 0, hi = 1e15;
            while(lo < hi) {
                ll mid = (lo + hi) / 2;
                ll cnt1 = (mid + 1) / 2, cnt2 = mid / 2;
                int ok = 1;
                for(ll i : a) {
                    i = m - i;
                    ll p = min(i / 2, cnt2);
                    cnt2 -= p;
                    i -= 2 * p;
                    p = min(i, cnt1);
                    cnt1 -= p;
                    i -= p;
                    if(i > 0) {
                        ok = 0;
                        break;
                    }
                }
                if(ok) hi = mid;
                else lo = mid + 1;
            }
            return lo;
        };
        ll ans = 1e18;
        for(int i = 0; i <= 2; ++i) {
            ans = min(ans, solve(i));
        }
        cout << ans << '\n';
    }
}