#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<ll> a(101), b(101);
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a[x] += 1;
        }
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            b[x] += 1;
        }
        ll lo = 0, hi = 1e12;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            a[100] += mid;
            ll tot = (mid + n) - ((mid + n) / 4);
            ll ta = tot, tb = tot, aa = 0, bb = 0;
            for(int i = 100; i >= 0; --i) {
                ll p = min(ta, a[i]);
                ta -= p;
                aa += 1ll * i * p;
                if(!ta) break;
            }
            for(int i = 100; i >= 0; --i) {
                ll p = min(tb, b[i]);
                tb -= p;
                bb += 1ll * i * p;
                if(!tb) break;
            }
            a[100] -= mid;
            if(aa >= bb) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
}