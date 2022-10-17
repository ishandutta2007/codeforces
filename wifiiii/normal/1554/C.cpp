#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        // n ^ x > m, x is minimum
        int ans = 0;
        for(int i = 30; i >= 0; --i) {
            if( (n | ((1 << i) - 1)) <= m ) {
                ans |= 1 << i;
                n |= 1 << i;
            }
        }
        assert(n > m);
        cout << ans << endl;
    }
}