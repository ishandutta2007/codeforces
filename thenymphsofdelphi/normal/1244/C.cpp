#include <bits/stdc++.h>
 
using namespace std;
 
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, p, w, d;
    cin >> n >> p >> w >> d;
    if (p % __gcd(w, d)) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i <= w; i++){
        if ((p - i * d) % w == 0) {
            if ((p - i * d) / w + i <= n && (p - i * d) / w >= 0) {
                cout << (p - i * d) / w << ' ' << i << ' ' << n - (p - i * d) / w - i;
            } else {
                cout << -1;
            }
            return 0;
        }
    }
    return 0;
}