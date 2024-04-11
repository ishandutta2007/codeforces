#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    ll ans = 0;
    for(int i = 0; i < n; ++i) cin >> a[i], ans += a[i];
    int q;
    cin >> q;
    map<pair<int,int>, int> mp;
    vector<int> b(n);
    while(q--) {
        int s, t, u;
        cin >> s >> t >> u;
        --s, --u;
        if(mp.count({s, t})) {
            int p = mp[{s, t}];
            if(b[p] <= a[p]) ++ans;
            b[p]--;
            mp.erase({s, t});
        }
        if(u != -1) {
            mp[{s, t}] = u;
            b[u]++;
            if(b[u] <= a[u]) --ans;
        }
        cout << ans << '\n';
    }
}