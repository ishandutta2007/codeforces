#include <iostream>

using namespace std;
using ll = long long;

const ll INF = 1LL << 50;

int main() {
    int N, M;
    cin >> N >> M;

    ll asum[N + 1], bsum[M + 1];
    asum[0] = bsum[0] = 0;
    for (int i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        asum[i + 1] = asum[i] + a;
    }
    for (int j = 0; j < M; ++j) {
        ll b;
        cin >> b;
        bsum[j + 1] = bsum[j] + b;
    }

    ll amin[N + 1], bmin[M + 1];
    fill(amin, amin + N + 1, INF);
    fill(bmin, bmin + M + 1, INF);

    for (int l = 0; l <= N; ++l) {
        for (int r = l + 1; r <= N; ++r) {
            amin[r - l] = min(amin[r - l], asum[r] - asum[l]);
        }
    }

    for (int l = 0; l <= M; ++l) {
        for (int r = l + 1; r <= M; ++r) {
            bmin[r - l] = min(bmin[r - l], bsum[r] - bsum[l]);
        }
    }

    ll x;
    cin >> x;
    int ans = 0;
    for (int w = 1; w <= N; ++w) {
        for (int h = 1; h <= M; ++h) {
            if (amin[w] * bmin[h] <= x) {
                ans = max(ans, w * h);
            }
        }
    }

    cout << ans << endl;
    return 0;
}