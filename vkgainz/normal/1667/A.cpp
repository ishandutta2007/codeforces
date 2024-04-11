#include <algorithm>
#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <queue>
#include <numeric>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 1e18;
    for (int i = 0; i < n; i++) {
        long long curr = 0;
        long long lst = 0;
        for (int j = i - 1; j >= 0; j--) {
            curr += lst / a[j] + 1;
            lst = (lst / a[j] + 1) * 1LL * a[j];
        }
        lst = 0;
        for (int j = i + 1; j < n; j++) {
            curr += lst / a[j] + 1;
            lst = (lst / a[j] + 1) * 1LL * a[j];
        }
        ans = min(ans, curr);
    }
    cout << ans;
}