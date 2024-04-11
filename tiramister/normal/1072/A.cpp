#include <iostream>

using namespace std;

int main() {
    int W, H, K;
    cin >> W >> H >> K;

    int ans = 0;
    for (int i = 0; i < K; ++i) {
        int w = W - i * 4, h = H - i * 4;
        ans += w * h - (w - 2) * (h - 2);
    }

    cout << ans << endl;
    return 0;
}