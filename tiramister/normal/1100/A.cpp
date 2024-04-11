#include <cmath>
#include <iostream>
#include <numeric>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int a[N], s[K];
    fill(s, s + K, 0);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        s[i % K] += a[i];
    }

    int sum = accumulate(a, a + N, 0);
    int ans = 0;
    for (int k = 0; k < K; ++k) {
        ans = max(ans, abs(sum - s[k]));
    }

    cout << ans << endl;
    return 0;
}