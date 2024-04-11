#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int sum[N][2];
    sum[0][0] = sum[0][1] = 0;
    for (int i = 1; i <= N; ++i) {
        int a;
        cin >> a;
        for (int j = 0; j < 2; ++j) {
            sum[i][j] = sum[i - 1][j] + (i % 2 == j ? a : 0);
        }
    }

    int ans = 0;
    for (int n = 1; n <= N; ++n) {
        int even = sum[n - 1][0] + (sum[N][1] - sum[n][1]);
        int odd = sum[n - 1][1] + (sum[N][0] - sum[n][0]);
        if (even == odd) ++ans;
    }
    cout << ans << endl;
    return 0;
}