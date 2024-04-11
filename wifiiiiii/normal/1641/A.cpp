#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a.begin(), a.end());
        vector<int> vis(n);
        int j = 0, cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(vis[i]) continue;
            while(j < n && a[j] < 1ll * a[i] * x) ++j;
            if(j < n && a[j] == 1ll * a[i] * x) {
                vis[j] = 1;
                cnt++;
                j++;
            }
        }
        cout << n - 2 * cnt << '\n';
    }
}