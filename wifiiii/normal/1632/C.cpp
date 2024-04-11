#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = b - a;
        auto f = [&](int a, int b) -> int {
            int ret = 0;
            for(int i = 20; i >= 0; --i) {
                if((a >> i & 1) || (ret + (1 << i) - 1 < b)) ret += 1 << i;
            }
            return ret - b;
        };
        for(int i = a; i <= b; ++i) {
            ans = min(ans, (i - a) + f(i, b) + 1);
        }
        cout << ans << '\n';
    }
}