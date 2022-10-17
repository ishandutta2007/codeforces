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
        for(int i = 0; i < k - 3; ++i) cout << 1 << " ";
        n -= k - 3;
        if(n > 0) {
            if(n % 2) {
                cout << 1 << " " << n / 2 << " " << n / 2 << endl;
            } else {
                if(n % 4 == 0) {
                    cout << n / 4 << " " << n / 4 << " " << n / 2 << endl;
                } else {
                    cout << 2 << " " << n / 2 - 1 << " " << n / 2 - 1 << endl;
                }
            }
        }
    }
}