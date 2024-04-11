#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> p(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        char c;
        cin >> c;
        if (c == '-') {
            p[i].first = 1;
            cin >> p[i].second;
        }
    }
    vector<int> ans;
    reverse(p.begin(), p.end());
    bool ok = true;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < 2 * n; i++) {
        if (p[i].first == 1) {
            if (!pq.empty() && pq.top() < p[i].second) {
                ok = false;
                break;
            }
            pq.emplace(p[i].second);
        } else {
            if (pq.empty()) {
                ok = false;
                break;
            }
            ans.emplace_back(pq.top());
            pq.pop();
        }
    }
    if (ok) {
        cout << "YES" << '\n';
        reverse(ans.begin(), ans.end());
        for (int i : ans) {
            cout << i << " ";
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}