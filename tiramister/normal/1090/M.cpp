#include <iostream>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int a[N + 2];
    for (int i = 1; i <= N; ++i) cin >> a[i];
    a[0] = a[1], a[N + 1] = a[N];

    int ans = 0, l = 0;
    for (int i = 1; i <= N + 1; ++i) {
        if (a[i] == a[i - 1]) {
            ans = max(ans, l);
            l = 0;
        }
        ++l;
    }

    cout << ans << endl;
    return 0;
}