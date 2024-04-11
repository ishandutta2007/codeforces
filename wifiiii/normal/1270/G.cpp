#include<bits/stdc++.h>

typedef long long ll;
using namespace std;


int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), vis(n + 1);
        for(int i = 1; i <= n; ++i) cin >> a[i];
        int cur = 1;
        while(!vis[cur]) {
            vis[cur] = 1;
            cur = cur - a[cur];
        }
        vector<int> ans;
        int s = cur;
        cur = cur - a[cur];
        ans.push_back(s);
        while(cur != s) {
            ans.push_back(cur);
            cur = cur - a[cur];
        }
        cout << ans.size() << '\n';
        for(int i : ans) cout << i << " "; cout << '\n';
    }
}