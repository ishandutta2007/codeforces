#include <bits/stdc++.h>
using namespace std;
using ll = long long;
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    priority_queue<pair<int, int>> pq;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] != a[i - 1]) {
            if (i) {
                pq.push({cnt, a[i - 1]});
            }
            cnt = 1;
        } else {
            cnt++;
        }
        if (i == n - 1) {
            pq.push({cnt, a[i]});
        }
    }

    for (int i = n; i > 0; i--) {
        pair<int, int> el = pq.top();
        int mx = el.first;
        cnt = ceil(sqrt(i));
        for (; cnt >= mx - 1; cnt--) {
            if (i % cnt == 0) {
                break;
            }
        }
        int s = cnt, t = i / cnt;
        if (s >= mx && t >= mx) {
            cnt = 0;
            vector<vector<int>> ans(s, vector<int>(t));
            while (!pq.empty()) {
                int val = pq.top().second;
                int lp = pq.top().first;
                pq.pop();
                for (int ii = 0; ii < lp; ii++) {
                    ans[cnt % s][(cnt / s + cnt % s) % t] = val;
                    cnt++;
                }
            }
            cout << i << '\n';
            cout << s << ' ' << t << '\n';
            for (int p = 0; p < s; p++) {
                for (int q = 0; q < t; q++) {
                    cout << ans[p][q] << ' ';
                }
                cout << '\n';
            }
            break;
        }
        pq.pop();
        if (mx > 1) {
            el.first--;
            pq.push(el);
        }
    }
    return 0;
}