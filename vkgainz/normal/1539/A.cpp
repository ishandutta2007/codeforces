#include<bits/stdc++.h>
using namespace std;

int main() {
    int k; cin >> k;
    while(k--) {
        int n, x, t; cin >> n >> x >> t;
        int mv = t / x;
        if(mv > n) {
            cout << n * 1LL * (n - 1) / 2 << "\n";
            continue;
        }
        //n - 1 - p < mv ==> p = n - mv
        //for i = 0 to i = n - mv - 1 add mv
        long long ans = (n - mv) * 1LL * mv;
        //for i = n - mv to n - 1 add n - 1 - i
        ans += ((mv) * 1LL * (mv - 1)) / 2;
        cout << ans << "\n";
    }
}