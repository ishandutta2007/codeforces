#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, g, b;
        cin >> n >> g >> b;
        ll lo = 1, hi = 1e18;
        while(lo < hi) {
            ll mid = (lo + hi) / 2;
            ll high = mid / (g + b) * g + min<int>(mid % (g + b), g);
            if(mid >= n && high >= (n + 1) / 2) hi = mid;
            else lo = mid + 1;
        }
        cout << lo << endl;
    }
}