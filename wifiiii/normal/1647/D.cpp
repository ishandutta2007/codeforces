#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int isprime(ll x) {
    if(x < 2) return 0;
    for(ll i = 2; i * i <= x; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int x, d;
        cin >> x >> d;
        if(x % d || x / d % d) {
            cout << "NO\n";
            continue;
        }
        if(!isprime(d)) {
            int cnt = 0;
            while(x % d == 0) x /= d, ++cnt;
            if((x == 1 || isprime(x)) && cnt == 2) {
                cout << "NO\n";
            } else if(!isprime(x) && x != 1) {
                cout << "YES\n";
            } else {
                if(d % x == 0) {
                    int d2 = d, cnt2 = 0;
                    while(x != 1 && d2 % x == 0) d2 /= x, cnt2++;
                    if(d2 == 1 && (cnt2 - 1) * (cnt - 1) < (x != 1) + cnt2) {
                        cout << "NO\n";
                    } else {
                        cout << "YES\n";
                    }
                } else {
                    cout << "YES\n";
                }
            }
        } else {
            while(x % d == 0) x /= d;
            if(x == 1 || isprime(x)) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}