#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    int a[101];
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int t;
    cin >> t;
    sort(a, a + n);
    int j = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        while (j < n - 1 && a[j + 1] - a[i] <= t) j++;
        ans = max(ans, j - i + 1);
        j = max(j, i + 1);
    }
    cout << ans << endl;
}