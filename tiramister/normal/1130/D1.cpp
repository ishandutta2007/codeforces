#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
    ll N, M;
    cin >> N >> M;
    vector<int> near(N, N), cnt(N, 0);

    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        ++cnt[a];
        int d = b - a;
        if (d < 0) d = N - (a - b);
        near[a] = min(near[a], d);
    }

    vector<ll> cost(N);
    for (int i = 0; i < N; ++i) {
        if (cnt[i] == 0) continue;
        cost[i] = (cnt[i] - 1) * N + near[i];
    }

    for (int s = 0; s < N; ++s) {
        ll ans = 0;
        for (int i = 0; i < N; ++i) {
            int t = (s + i) % N;
            if (cnt[t] == 0) continue;
            ans = max(ans, i + cost[t]);
        }
        cout << ans << " ";
    }
    cout << endl;
    return 0;
}