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
            cout << "? " << x + 1 << endl;
            int ret;
            cin >> ret;
            return ret - 1;
        };
        vector<int> vis(n), ans(n);
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            vector<int> a;
            int p = ask(i);
            while(!vis[p]) {
                a.push_back(p);
                vis[p] = 1;
                p = ask(i);
            }
            for(int j = 0; j < a.size(); ++j) {
                ans[a[j]] = a[(j + 1) % a.size()];
            }
        }
        cout << "! ";
        for(int i = 0; i < n; ++i) {
            cout << ans[i] + 1 << " ";
        }
        cout << endl;
    }
}