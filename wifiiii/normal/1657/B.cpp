#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    // freopen("in.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--) {
        int n, b, x, y;
        cin >> n >> b >> x >> y;
        ll ans = 0;
        int now = 0;
        for(int i = 1; i <= n; ++i) {
            if(now + x <= b) now += x;
            else now -= y;
            ans += now;
        }
        cout << ans << '\n';
    }
}