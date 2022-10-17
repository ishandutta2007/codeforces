#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> aa(n);
        for(int i = 0; i < n; ++i) cin >> aa[i];
        int lo = 1, hi = 1e9;
        while(lo < hi) {
            vector<ll> a = aa;
            int mid = (lo + hi + 1) / 2, ok = 1;
            for(int i = n - 1; i >= 2; --i) {
                if(a[i] >= mid) {
                    ll d = min(aa[i] / 3, (a[i] - mid) / 3);
                    a[i - 2] += 2 * d;
                    a[i - 1] += d;
                    a[i] -= 3 * d;
                }
            }
            for(int i = 0; i < n; ++i) {
                if(a[i] < mid) {
                    ok = 0;
                    break;
                }
            }
            if(ok) lo = mid;
            else hi = mid - 1;
        }
        cout << lo << '\n';
    }
}