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
        auto calc = [&](int x) {
            int ret = 1;
            for(int i = 2; i * i <= x; ++i) {
                if(x % i == 0) {
                    int cnt = 0;
                    while(x % i == 0) ++cnt, x /= i;
                    cnt &= 1;
                    if(cnt) ret *= i;
                }
            }
            ret *= x;
            return ret;
        };
        map<int, int> vis;
        int ans = 1;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            x = calc(x);
            if(vis.count(x)) {
                vis.clear();
                ++ans;
            }
            vis[x] = 1;
        }
        cout << ans << '\n';
    }
}