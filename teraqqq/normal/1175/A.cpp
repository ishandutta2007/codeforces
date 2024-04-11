#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
ll n, k;

int main() {
    for(cin >> t; t--; ) {
        cin >> n >> k;
        ll res = 0;
        while(n != 0) {
            if(n % k == 0) n /= k, ++res;
            else res += n % k, n -= n % k;
        }

        cout << res << endl;
    }
}