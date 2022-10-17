#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        if(k > (n - 1) / 2) {
            cout << -1 << endl;
            continue;
        }
        vector<int> a(n, -1);
        vector<int> vis(n + 1);
        int p = n - 1, l = 0;
        for(int i = 1, j = 0; j < k; i += 2, j += 1) {
            a[i] = p--;
            vis[a[i]] = 1;
        }
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            if(a[i] != -1) continue;
            while(vis[cur]) ++cur;
            a[i] = cur;
            vis[cur] = 1;
        }
        for(int i = 0; i < n; ++i) cout << a[i] + 1 << " "; cout << endl;
    }
}