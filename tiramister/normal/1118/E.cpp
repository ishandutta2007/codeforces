#include <iostream>

using namespace std;

using ll = long long;

int main() {
    ll N, K;
    cin >> N >> K;

    if (K * (K - 1) < N) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    int x = 1, y = 2;
    for (int i = 0; i < N; ++i) {
        cout << x << " " << y << endl;
        swap(x, y);
        if (i % 2 == 1) {
            ++y;
            if (y > K) {
                ++x;
                y = x + 1;
            }
        }
    }
    return 0;
}