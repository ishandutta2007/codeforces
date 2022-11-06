#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 10;
int a[maxn], t[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, tt; cin >> n >> tt; 
    for (int i = 0; i < n; ++i) cin >> a[i] >> t[i];
    vector<int> ord(n); iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int &i, const int &j) { return a[i] > a[j]; });
    int ans = 0;
    {
        priority_queue<pair<int, int>> pq;
        int pqt = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[ord[j]] == a[ord[i]]) {
                pq.emplace(t[ord[j]], ord[j]);
                pqt += t[ord[j]];
                // cout << "push j = " << ord[j] << endl;
                ++j;
            }
            while (pq.size() && (pqt > tt || pq.size() > a[ord[i]])) pqt -= pq.top().first, pq.pop();
            // cout << "pq.size() = " << pq.size() << endl;
            // ans = max(ans, min(a[i], (int)pq.size()));
            ans = max(ans, (int)pq.size());
        }
    }
    {
        priority_queue<pair<int, int>> pq;
        int pqt = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i;
            while (j < n && a[ord[j]] == a[ord[i]]) {
                pq.emplace(t[ord[j]], ord[j]);
                pqt += t[ord[j]];
                // cout << "push j = " << ord[j] << endl;
                ++j;
            }
            while (pq.size() && (pqt > tt || pq.size() > a[ord[i]])) pqt -= pq.top().first, pq.pop();
            // cout << "pq.size() = " << pq.size() << endl;
            // ans = max(ans, min(a[i], (int)pq.size()));
            if (ans == pq.size()) {
                cout << ans << endl;
                cout << ans << endl;
                while (ans--) cout << pq.top().second + 1 << ' ', pq.pop(); cout << endl;
            }
        }
    }
    return 0;
}