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
        vector<int> vis(n + 1), a, b;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            if(x <= n && !vis[x]) {
                vis[x] = 1;
            } else {
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end());
        for(int i = 1; i <= n; ++i) if(!vis[i]) b.push_back(i);
        int ok = 1;
        for(int i = 0; i < a.size(); ++i) {
            if((a[i] - 1) / 2 < b[i]) {
                ok = 0;
                break;
            }
        }
        if(ok) cout << a.size() << '\n';
        else cout << -1 << '\n';
    }
}