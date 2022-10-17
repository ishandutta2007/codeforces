#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        auto intersect = [](int x1, int y1, int x2, int y2) {
            if(x1 > y1) swap(x1, y1);
            return (x1 < x2 && x2 < y1) ^ (x1 < y2 && y2 < y1);
        };
        vector<int> match(2 * n, -1);
        vector<pair<int,int>> es;
        for(int i = 0; i < k; ++i) {
            int x, y;
            cin >> x >> y;
            --x, --y;
            match[x] = 1;
            match[y] = 1;
            if(x > y) swap(x, y);
            es.push_back({x, y});
        }
        int last = -1;
        for(int i = 0; i < 2 * n; ++i) {
            if(match[i] == -1) {
                if(last == -1) last = i;
                else {
                    es.push_back({last, i});
                    last = -1;
                }
            }
        }
        assert(es.size() == n);
        for(int p = 0; p < n; ++p) {
            for(int i = k; i < n; ++i) {
                for(int j = i + 1; j < n; ++j) {
                    if(!intersect(es[i].first, es[i].second, es[j].first, es[j].second)) {
                        if(intersect(es[i].first, es[j].first, es[i].second, es[j].second)) {
                            swap(es[i].second, es[j].first);
                        } else if(intersect(es[i].first, es[j].second, es[j].first, es[i].second)) {
                            swap(es[i].second, es[j].second);
                        } else {
                            assert(0);
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                ans += intersect(es[i].first, es[i].second, es[j].first, es[j].second);
            }
        }
        cout << ans << '\n';
    }
}