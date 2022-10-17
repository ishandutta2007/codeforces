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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        for(int i = 0; i < n; ++i) cin >> b[i];
        int p1 = max_element(a.begin(), a.end()) - a.begin();
        int p2 = max_element(b.begin(), b.end()) - b.begin();
        string ans(n, '0');
        if(p1 == p2) {
            ans[p1] = '1';
            cout << ans << '\n';
        } else {
            vector<int> vis(n), o1(n), o2(n);
            for(int i = 0; i < n; ++i) o1[i] = o2[i] = i;
            sort(o1.begin(), o1.end(), [&](int i, int j) {return a[i] > a[j];});
            sort(o2.begin(), o2.end(), [&](int i, int j) {return b[i] > b[j];});
            int j = 0, k = 0;
            queue<int> q;
            q.push(p1), q.push(p2); vis[p1] = vis[p2] = 1;
            while(!q.empty()) {
                int p = q.front(); q.pop();
                ans[p] = '1';
                while(j < n && (vis[o1[j]] || a[o1[j]] >= a[p] || b[o1[j]] >= b[p])) {
                    if(!vis[o1[j]]) {
                        vis[o1[j]] = 1;
                        q.push(o1[j]);
                    }
                    ++j;
                }
                while(k < n && (vis[o2[k]] || a[o2[k]] >= a[p] || b[o2[k]] >= b[p])) {
                    if(!vis[o2[k]]) {
                        vis[o2[k]] = 1;
                        q.push(o2[k]);
                    }
                    ++k;
                }
            }
            cout << ans << '\n';
        }
    }
}