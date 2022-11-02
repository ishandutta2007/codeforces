#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];
    sort(a, a + N);

    int sum = accumulate(a, a + N, 0);
    int ans = sum;
    for (int x = 2; x <= 100; ++x) {
        int b = 0;
        for (int i = 0; i < N; ++i) {
            if (a[i] % x == 0) b = a[i] / x;
        }
        ans = min(ans, sum - (b - a[0]) * (x - 1));
    }

    cout << ans << endl;
    return 0;
}