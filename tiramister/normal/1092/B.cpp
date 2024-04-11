#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }

    sort(a, a + N);

    int ans = 0;
    for (int i = 0; i < N; i += 2) {
        ans += a[i + 1] - a[i];
    }

    cout << ans << endl;
    return 0;
}