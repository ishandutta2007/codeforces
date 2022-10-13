#include <bits/stdc++.h>
using namespace std;

bool intersect(pair<int, int> x, pair<int, int> y) {
    int a = x.first, b = x.second;
    x = {min(a, b), max(a, b)};
    a = y.first, b = y.second;
    y = {min(a, b), max(a, b)};
    return (x.first < y.first && y.second > x.second && y.first < x.second) || (y.first < x.first && y.second > x.first && y.second < x.second);
}

int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        vector<bool> vis(2 * n);
        vector<pair<int, int>> in(k);
        for(int i = 0; i < k; i++) {
            int x, y; cin >> x >> y;
            --x, --y;
            in[i] = {x, y};
            vis[x] = true, vis[y] = true;
        }
        vector<int> left;
        for(int i = 0; i < 2 * n; i++) {
            if(!vis[i])
                left.push_back(i);
        }
        for(int i = 0; i < n - k; i++) {
            in.push_back({left[i], left[i + n - k]});
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = i + 1; j < n; j++)
                if(intersect(in[i], in[j]))
                    ++ans;
        cout << ans << "\n";
    }
}