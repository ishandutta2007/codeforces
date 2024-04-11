#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        ll lo = 1, hi = 1000001;
        while(lo < hi) {
            ll mid = (lo + hi + 1) / 2;
            if(mid * mid > 2 * n - 1) hi = mid - 1;
            else lo = mid;
        }
        if(lo % 2 == 0) --lo;
        cout << (lo - 1) / 2 << endl;
    }
}