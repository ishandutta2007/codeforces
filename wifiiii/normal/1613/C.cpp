#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n; ll h;
        cin >> n >> h;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        ll lo = 1, hi = h;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            ll hit = 0, lst = -1;
            for(ll i : a) {
                if(i > lst) {
                    hit += mid;
                } else {
                    hit += i + mid - 1 - lst;
                }
                if(hit >= h) break;
                lst = i + mid - 1;
            }
            if(hit >= h) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << '\n';
    }
}