#include <iostream>

using namespace std;

template <typename T>
T iceil(T n, T d) {
    return (n + d - 1) / d;
}

int main() {
    int N;
    cin >> N;

    int ans = N * 2;
    for (int w = 1; w * w <= N; ++w) {
        int h = iceil(N, w);
        ans = min(ans, h + w);
    }

    cout << ans << endl;
    return 0;
}