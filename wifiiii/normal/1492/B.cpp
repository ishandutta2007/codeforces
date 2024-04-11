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
        vector<int> a(n), ra(n), vis(n);
        for(int i = 0; i < n; ++i) {
            cin >> a[i];
            --a[i];
            ra[a[i]] = i;
        }
        int cur = n - 1;
        vector<int> ans;
        for(int i = n - 1; i >= 0; --i) {
            if(vis[i]) continue;
            int pos = ra[i];
            for(int j = pos; j <= cur; ++j) {
                vis[a[j]] = 1;
                ans.push_back(a[j]);
            }
            cur = pos - 1;
        }
        for(int i : ans) cout << 1 + i << " "; cout << endl;
    }
}