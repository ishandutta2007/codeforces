#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        ll n, k;
        cin >> n >> k;
        ll res = n - 1, cur = 1, ans = 0;
        while(res) {
            ans += 1;
            res -= cur;
            cur *= 2;
            if(cur > k) {
                ans += (res + k - 1) / k;
                break;
            }
        }
        cout << ans << '\n';
    }
}