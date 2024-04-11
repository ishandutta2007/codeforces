#include <bits/stdc++.h>
using namespace std;

const int N = 400000;

array<int, 3> event[N];
int clique[N];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x, w;
        cin >> x >> w;
        event[2 * i] = {x - w, 1, i};
        event[2 * i + 1] = {x + w, -1, i};
    }

    sort(event, event + 2 * n);

    int ans = 0;
    for (int i = 0; i < 2 * n; ++i) {
        auto [x, t, j] = event[i];
        if (t == 1) {
            clique[j] = ans + 1;
        } else {
            ans = max(ans, clique[j]);
        }
    }

    cout << ans << "\n";
}