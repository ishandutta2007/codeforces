#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int t, l, r;
    cin >> t;
    int n;
    int ans[1000];
    for (int i = 0; i < t; i++) {
        cin >> n;
        for (int j = 0; j < n; j++) {
            ans[j] = 0;
        }
        deque <int> q;
        for (int j = 0; j < n; j++) {
            cin >> l >> r;
            while (!q.empty() && q[0] < l) {
                q.pop_front();
            }
            if (q.empty()) {
                ans[j] = l;
                q.push_back(l);
                continue;
            }
            if (q.size() + l <= r) {
                ans[j] = l + q.size();
                q.push_back(ans[j]);
            }
        }
        for (int j = 0; j < n; j++) {
            cout << ans[j] << ' ';
        }
        cout << endl;
    }
    return 0;
}