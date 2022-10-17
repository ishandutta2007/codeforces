#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n == 0) {
            cout << 0 << ' ';
        } else {
            int ans = 123;
            for(int i = 0; i <= 16; ++i) {
                if((n + i) % 32768 != 0) {
                    ans = min(ans, i + 15 - __builtin_ctz((n + i) % 32768));
                } else {
                    ans = min(ans, i);
                }
            }
            cout << ans << ' ';
        }
    }
}