#include <iostream>

using namespace std;

int main() {
    int N, M, K;
    cin >> N >> M >> K;
    int a[N];
    for (int i = N - 1; i >= 0; --i) cin >> a[i];

    int used = 0, cap = K;
    for (int i = 0; i < N; ++i) {
        if (cap < a[i]) {
            ++used;
            if (used == M) {
                cout << i << endl;
                return 0;
            }
            cap = K;
        }
        cap -= a[i];
    }
    cout << N << endl;
    return 0;
}