#include <iostream>

using namespace std;

template <typename T>
inline T iceil(T n, T d) { return (n + d - 1) / d; }

int main() {
    int N;
    cin >> N;
    int cnt[2] = {0, 0};
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        if (a < 0) ++cnt[0];
        if (a > 0) ++cnt[1];
    }

    for (int k = 0; k < 2; ++k) {
        if (cnt[k] >= iceil(N, 2)) {
            cout << k * 2 - 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}