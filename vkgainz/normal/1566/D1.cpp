#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <set>

using namespace std;

bool cmp(pair<int, int> &x, pair<int, int> &y) {
    if (x.first != y.first) return x.first < y.first;
    return x.second > y.second;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> a(n * m);
        vector<int> pos(n * m);
        for (int i = 0; i < n * m; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 0; i < n * m; i++) {
            pos[a[i].second] = i;
        }
        vector<int> fill(n * m);
        int ans = 0;
        for (int i = 0; i < n * m; i++) {
            for (int j = 0; j < pos[i]; j++) {
                ans += fill[j];
            }
            ++fill[pos[i]];
        }
        cout << ans << "\n";
    }
}