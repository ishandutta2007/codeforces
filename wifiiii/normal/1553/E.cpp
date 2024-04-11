#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i], --a[i];
        auto calc = [&](int k) {
            vector<int> b = a;
            for(int &i : b) i = (i + k) % n;
            int ret = n;
            vector<int> vis(n);
            for(int i = 0; i < n; ++i) {
                if(vis[i]) continue;
                --ret;
                int cur = i;
                while(!vis[cur]) {
                    vis[cur] = 1;
                    cur = b[cur];
                }
            }
            return ret;
        };
        map<int,int> mp;
        for(int i = 0; i < n; ++i) {
            mp[(n + i - a[i]) % n]++;
        }
        vector<pair<int,int>> v;
        for(auto p : mp) {
            v.push_back(p);
        }
        sort(v.begin(), v.end(), [](auto i,auto j){return i.second>j.second;});
        vector<int> ans;
        for(int i=0;i<min<int>(10,v.size());++i) {
            if(calc(v[i].first) <= m) ans.push_back(v[i].first);
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << " ";
        for(int i : ans) cout << i << " "; cout << endl;
    }
}