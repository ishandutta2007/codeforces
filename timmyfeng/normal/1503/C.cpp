#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    long long ans = 0;
    vector<array<int, 2>> events;
    for (int i = 0; i < n; ++i) {
        int a, c;
        cin >> a >> c;
        events.push_back({a, 1});
        events.push_back({a + c, -1});
        ans += c;
    }

    sort(events.begin(), events.end());
    int count = 0, prv = events[0][0];
    for (auto [a, c] : events) {
        if (count == 0) {
            ans += a - prv;
        }
        count += c;
        prv = a;
    }

    cout << ans << "\n";
}