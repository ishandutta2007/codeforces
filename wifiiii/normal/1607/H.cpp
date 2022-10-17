#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<tuple<int,int,int>> g[2000005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), c(n);
        for(int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];
        for(int i = 0; i < n; ++i) {
            int l = a[i] - min(a[i], c[i]), r = a[i] - max(0, c[i] - b[i]);
            g[a[i] + b[i] - c[i]].push_back({l, r, i});
        }
        int ans = 0;
        vector<int> res(n);
        for(int i = 0; i < n; ++i) {
            if(g[a[i] + b[i] - c[i]].empty()) continue;
            auto v = g[a[i] + b[i] - c[i]];
            sort(v.begin(), v.end(), [&](auto i, auto j) {return get<1>(i) < get<1>(j);});
            int lst = -1;
            for(auto [l, r, id] : v) {
                if(l > lst) {
                    lst = r;
                    ans += 1;
                }
                res[id] = lst;
            }
            g[a[i] + b[i] - c[i]].clear();
        }
        cout << ans << '\n';
        for(int i = 0; i < n; ++i) {
            cout << a[i] - res[i] << " " << (c[i] - (a[i] - res[i])) << endl;
        }
    }
}