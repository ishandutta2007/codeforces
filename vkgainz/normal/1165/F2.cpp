#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>
#include <set>
#include <map>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    vector<int> k(n);
    vector<int> d(m), t(m);
    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> d[i] >> t[i];
        --t[i];
    }
    int lo = 0, hi = 4e5;
    for (int j = 0; j < 20; j++) {
        int mid = (lo + hi) / 2;
        vector<pair<int, int>> lst(n);
        for (int i = 0; i < n; i++) {
            lst[i].first = -1;
            lst[i].second = k[i];
        }
        for (int i = 0; i < m; i++) {
            if (d[i] <= mid) {
                lst[t[i]].first = max(lst[t[i]].first, d[i]);
            } 
        }
        sort(lst.begin(), lst.end());
        int curr = 0;
        int lstDay = 0;
        for (int i = 0; i < n; i++) {
            if (lst[i].first != -1) {
                curr += lst[i].first - lstDay;
                int r = min(curr, lst[i].second);
                lst[i].second -= r, curr -= r;
                lstDay = lst[i].first;
            }
        }
        curr += mid - lstDay;
        int left = 0;
        for (int i = 0; i < n; i++) {
            left += lst[i].second * 2;
        }
        if (left <= curr) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    cout << lo << "\n";
}