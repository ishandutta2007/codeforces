#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t = 1;
//    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n), vis(n+1);
        for(int i = 0; i < n; ++i) cin >> a[i], vis[a[i]] = 1;
        vector<int> b, c;
        for(int i = 1; i <= n; ++i) if(!vis[i]) b.push_back(i);
        for(int i = 0; i < n; ++i) if(!a[i]) c.push_back(i);
        assert(b.size() == c.size());
        sort(b.begin(), b.end());
        vector<int> ans = a;
        while(1) {
            shuffle(b.begin(), b.end(), mrand);
            int ok = 1;
            for(int i = 0; i < c.size(); ++i) {
                ans[c[i]] = b[i];
                if(c[i] + 1 == b[i]) ok = 0;
            }
            if(ok) {
                break;
            }
        }
        for(int i : ans) cout << i << " "; cout << endl;
    }
}