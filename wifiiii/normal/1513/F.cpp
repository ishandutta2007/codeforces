#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct S {
    set<pair<ll,ll>> s;
    void insert(int x, int y) {
        auto it = s.lower_bound({x, y});
        int ok = 1;
        while(it != s.end() && abs(it->first - x) <= abs(it->second - y)) {
            if(y >= it->second) {
                ok = 0;
                break;
            } else {
                it = s.erase(it);
            }
        }
        if(!ok) return;
        if(it != s.begin()) {
            --it;
            while(abs(it->first - x) <= abs(it->second - y)) {
                if(y >= it->second) {
                    ok = 0;
                    break;
                } else {
                    it = s.erase(it);
                    if(it == s.begin()) break;
                    else --it;
                }
            }
        }
        if(ok) s.insert({x, y});
    }
    ll query(int x) {
        auto it = s.lower_bound({x, -1e18});
        ll ans = 1e18;
        if(it != s.end()) ans = min(ans, abs(x - it->first) + it->second);
        if(it != s.begin()) {
            --it;
            ans = min(ans, abs(x - it->first) + it->second);
        }
        return ans;
    }
    int size() {return s.size();}
    int empty() {return s.empty();}
    void clear() {s.clear();}
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> a(n), b(n);
    vector<int> wa(n), wb(n);
    for(int i = 0; i < n; ++i) cin >> a[i].first;
    for(int i = 0; i < n; ++i) cin >> a[i].second;
    b = a;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), [&](auto i, auto j) {return i.second < j.second;});
    ll ans = 0;
    for(int i = 0; i < n; ++i) {
        wa[i] = abs(a[i].first - a[i].second);
        wb[i] = abs(b[i].first - b[i].second);
        ans += wa[i];
    }
    ll mn = 0;
    {
        // second >= first
        S s;
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            while(cur < n && a[cur].first <= b[i].second) {
                // b[i].second - a[cur].first + abs(a[cur].second - b[i].first) - w[i] - w[cur]
                // = abs(b[i].first - a[cur].second) - a[cur].first - w[cur] + b[i].second - w[i]
                s.insert(a[cur].second, -a[cur].first - wa[cur]);
                ++cur;
            }
            if(!s.empty()) mn = min(mn, b[i].second - wb[i] + s.query(b[i].first));
        }
    }
    {
        // second <= first
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        reverse(wa.begin(), wa.end());
        reverse(wb.begin(), wb.end());
        S s;
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            while(cur < n && a[cur].first >= b[i].second) {
                // a[cur].first - b[i].second + abs(a[cur].second - b[i].first) - w[i] - w[cur]
                // = abs(b[i].first - a[cur].second) + a[cur].first - w[cur] - b[i].second - w[i]
                s.insert(a[cur].second, a[cur].first - wa[cur]);
                ++cur;
            }
            if(!s.empty()) mn = min(mn, - b[i].second - wb[i] + s.query(b[i].first));
        }
    }
    ans += mn;
    cout << ans << '\n';
}