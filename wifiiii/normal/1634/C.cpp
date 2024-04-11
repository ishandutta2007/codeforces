#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(n % 2 == 0) {
            cout << "YES" << '\n';
            for(int j = 1; j <= n / 2; ++j) {
                for(int i = (j - 1) * 2 * k + 1; i <= j * 2 * k; i += 2) cout << i << ' '; cout << '\n';
                for(int i = (j - 1) * 2 * k + 2; i <= j * 2 * k; i += 2) cout << i << ' '; cout << '\n';
            }
        } else if(k == 1) {
            cout << "YES" << '\n';
            for(int i = 1; i <= n; ++i) cout << i << '\n';
        } else {
            cout << "NO\n";
        }
    }
}