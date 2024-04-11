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
        if(n < 2 * k - 1) {
            cout << -1 << '\n';
        } else {
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    if(k && i == j && i % 2 == 0) {
                        --k;
                        cout << 'R';
                    } else {
                        cout << '.';
                    }
                }
                cout << '\n';
            }
        }
    }
}