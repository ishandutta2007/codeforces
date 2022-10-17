#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        set<pair<int,int>> s;
        auto add = [&](int x, int y) {
            auto it = s.lower_bound({x, y});
            while(it != s.end() && it->second >= y) it = s.erase(it);
            if(it == s.begin() || prev(it)->second > y) s.insert({x, y});
        };
        for(int i = 0; i < n; ++i) add(i, a[i]);
        while(m--) {
            int x, y;
            cin >> x >> y;
            --x;
            a[x] -= y;
            if(y > 0) add(x, a[x]);
            cout << s.size() << ' ';
        }
        cout << '\n';
    }
}