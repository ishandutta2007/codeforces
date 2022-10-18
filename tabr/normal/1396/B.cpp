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
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<int> a(n);
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            pq.emplace(a[i]);
        }
        pq.emplace(0);
        int x = 0, y = 0;
        string ans;
        while (true) {
            pq.emplace(x);
            x = pq.top();
            pq.pop();
            if (x == 0) {
                ans = "HL";
                break;
            }
            x--;
            pq.emplace(y);
            y = pq.top();
            pq.pop();
            if (y == 0) {
                ans = "T";
                break;
            }
            y--;
        }
        cout << ans << '\n';
    }
    return 0;
}