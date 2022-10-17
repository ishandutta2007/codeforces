#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> vis(n + 1);
        for(int i = 0; i < m; ++i) {
            int x, y, z;
            cin >> x >> y >> z;
            vis[y] = 1;
        }
        for(int i = 1; i <= n; ++i) {
            if(!vis[i]) {
                for(int j = 1; j <= n; ++j) {
                    if(i == j) continue;
                    cout << i << " " << j << '\n';
                }
                break;
            }
        }
    }
}