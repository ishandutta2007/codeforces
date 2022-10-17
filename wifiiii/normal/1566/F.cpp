#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        a.push_back(1e10);
        a.push_back(-1e10);
        sort(a.begin(), a.end());
        vector<pair<ll,ll>> ps(m);
        for(int i = 0; i < m; ++i) {
            cin >> ps[i].first >> ps[i].second;
        }
        sort(ps.begin(), ps.end());
        ll b0 = -a[0], b1 = -2 * a[0];
        for(int i = 1; i < a.size(); ++i) {
            ll x1 = a[i-1], x2 = a[i];
            auto it = lower_bound(ps.begin(), ps.end(), pair<ll,ll>{x1, 1e9});
            vector<pair<ll,ll>> tmp;
            while(it != ps.end() && it->first < x2) {
                if(it->first > x1 && it->second < x2) {
                    tmp.push_back(*it);
                }
                ++it;
            }
            vector<ll> smn(tmp.size());
            if(tmp.size()) {
                smn.back() = tmp.back().second;
                for(int j = (int)tmp.size() - 2; j >= 0; --j) {
                    smn[j] = min(smn[j+1], tmp[j].second);
                }
            }
            ll nb0 = 1e18, nb1 = 1e18;
            for(int j = 0; j <= tmp.size(); ++j) {
                ll l = j ? tmp[j-1].first : a[i-1];
                ll r = j < tmp.size() ? smn[j] : a[i];
                nb1 = min(nb1, -2 * a[i] + a[i] - r + min(l + b0, 2 * l + b1));
                nb0 = min(nb0, -a[i] + 2 * (a[i] - r) + min(l + b0, 2 * l + b1));
            }
            b0 = nb0, b1 = nb1;
        }
        cout << min(a.back() + b0, 2 * a.back() + b1) << '\n';
    }
}