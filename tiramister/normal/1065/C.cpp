#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int h[N + 1];
    for (int i = 0; i < N; ++i) cin >> h[i];
    h[N] = 200010;
    sort(h, h + N + 1);

    int itr = 0, ans = 0, add = 0;
    for (int H = h[0]; itr < N; ++H) {
        while (h[itr] <= H) ++itr;
        add += N - itr;
        if (add > K) {
            // 1
            ++ans;
            add = N - itr;
        }
    }
    if (add > 0) ++ans;
    cout << ans << endl;
    return 0;
}