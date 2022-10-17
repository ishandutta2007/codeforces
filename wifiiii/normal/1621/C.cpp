#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        auto ask = [&](int x) {
            cout << "? " << x << endl;
            int ret;
            cin >> ret;
            return ret;
        };
        vector<int> vis(n + 1), ans(n + 1);
        for(int i = 1; i <= n; ++i) {
            if(vis[i]) continue;
            int p = ask(i);
            vector<int> a;
            while(!vis[p]) {
                vis[p] = 1;
                a.push_back(p);
                p = ask(i);
            }
            for(int j = 0; j < a.size(); ++j) {
                ans[a[j]] = a[(j + 1) % a.size()];
            }
        }
        cout << "! ";
        for(int i = 1; i <= n; ++i) cout << ans[i] << " "; cout << endl;
    }
}