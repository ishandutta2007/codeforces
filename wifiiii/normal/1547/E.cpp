#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct node {
    int a, t;
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> ans(n, 2e9);
        vector<node> a(m);
        for(int i = 0; i < m; ++i) cin >> a[i].a, --a[i].a;
        for(int i = 0; i < m; ++i) cin >> a[i].t;
        for(int i = 0; i < m; ++i) ans[a[i].a] = min(ans[a[i].a], a[i].t);
        int cur = 2e9;
        for(int i = 0; i < n; ++i) {
            ans[i] = min(ans[i], cur);
            cur = min(cur, ans[i]);
            ++cur;
        }
        for(int i = n - 1; i >= 0; --i) {
            ans[i] = min(ans[i], cur);
            cur = min(cur, ans[i]);
            ++cur;
        }
        for(int i = 0; i < n; ++i) cout << ans[i] << " ";
        cout << '\n';
    }
}