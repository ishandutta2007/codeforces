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
        vector<int> a(n);
        priority_queue<pair<int,int>> q;
        vector<pair<int,int>> ans;
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            if(a[i]) q.push({a[i], i});
        }
        while(q.size() > 1) {
            auto [d, i] = q.top(); q.pop();
            auto [d2, i2] = q.top(); q.pop();
            ans.push_back({i, i2});
            if(d - 1) q.push({d - 1, i});
            if(d2 - 1) q.push({d2 - 1, i2});
        }
        cout << ans.size() << '\n';
        for(auto [u, v] : ans) cout << u + 1 << " " << v + 1 << endl;
    }
}