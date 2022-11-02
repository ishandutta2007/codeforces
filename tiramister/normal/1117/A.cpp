#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) cin >> a[i];

    int m = *max_element(a, a + N);
    int ans = 0, l = 0;
    for (int i = 0; i < N; ++i) {
        ++l;
        if (a[i] < m) l = 0;
        ans = max(ans, l);
    }

    cout << ans << endl;
    return 0;
}