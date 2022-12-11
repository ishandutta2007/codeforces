#include <iostream>

using namespace std;

const int MAX_N = 1e5;
int arr[MAX_N];
long double ans = -1;

int my_bs(int n, int k) {
    int l = -1, r = n, m;
    while (r - l > 1) {
        m = (l + r) / 2;
        if (arr[m] <= k) l = m;
        else r = m;
    }
    return l;
}

int main() {
    cout.precision(12);
    int n, u;
    cin >> n >> u;
    for (int i = 0; i < n; i++) {
        scanf("%d ", &arr[i]);
    }
    int j, k;
    for (int i = 0; i < n - 2; i++) {
        j = i + 1;
        k = my_bs(n, arr[i] + u);
        if (k <= j) continue;
        ans = max(ans, ((long double) (arr[k] - arr[j])) / (arr[k] - arr[i]));
    }
    if (ans < -0.5) cout << -1 << endl;
    else cout << fixed << ans << endl;
    return 0;
}