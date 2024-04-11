#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int n;
int a[200000];

int64_t solve() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    if (a[0] == a[n - 1]) {
        return n / 2;
    }
    int64_t ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (a[i] != a[i + 1]) {
            ans = max(ans, ((i + 1ll) * (n - i - 1)));
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << solve() << endl;
    }
}