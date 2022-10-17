#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;
        if(m > 1ll * n * (n - 1) / 2 || m < n - 1) cout << "NO" << endl;
        else if(k <= 1) cout << "NO" << endl;
        else if(k == 2) {
            if(n == 1) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else if(k == 3) {
            if(m == 1ll * n * (n - 1) / 2) cout << "YES" << endl;
            else cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}