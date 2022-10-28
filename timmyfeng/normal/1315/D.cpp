#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> cat(n);
    for (auto& i : cat) {
        cin >> i.first;
    }
    for (auto& i : cat) {
        cin >> i.second;
    }

    sort(cat.begin(), cat.end());
    long long sol = 0;
    int ndx = 0;
    int pos = 0;
    priority_queue<pair<int, int>> pq;
    while (ndx < n || !pq.empty()) {
        if (pq.empty()) {
            pos = cat[ndx].first;
        } else {
            pos++;
        }
        while (ndx < n && cat[ndx].first <= pos) {
            pq.emplace(cat[ndx].second, cat[ndx].first);
            ndx++;
        }
        sol += (long long) pq.top().first * (pos - pq.top().second);
        pq.pop();
    }
    cout << sol << '\n';
}