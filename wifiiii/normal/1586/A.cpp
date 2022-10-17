#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int isprime(int x) {
    if(x < 2) return 0;
    for(int i = 2; i * i <= x; ++i) {
        if(x % i == 0) return 0;
    }
    return 1;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int sum = 0;
        for(int i = 0; i < n; ++i) cin >> a[i], sum += a[i];
        if(!isprime(sum)) {
            cout << n << '\n';
            for(int i = 1; i <= n; ++i) {
                cout << i << " ";
            }
            cout << '\n';
        } else {
            for(int i = 1; i <= n; ++i) {
                if(!isprime(sum - a[i - 1])) {
                    cout << n - 1 << '\n';
                    for(int j = 1; j <= n; ++j) {
                        if(i == j) continue;
                        cout << j << " ";
                    }
                    cout << '\n';
                    break;
                }
            }
        }
    }
}