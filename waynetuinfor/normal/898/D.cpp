#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10;
int a[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    deque<int> dq;
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        while (dq.size() && dq[0] <= a[i] - m) dq.pop_front();
        dq.push_back(a[i]);
        if (dq.size() >= k) ++ans, dq.pop_back();
    }
    cout << ans << endl;
}