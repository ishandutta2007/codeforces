#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 5e5 + 7;
int a[N];

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int summ = 0;
    int k = (n + 1) / 2;
    int all = 0;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
        summ += a[i];
        all += a[i];
    }
    int x;
    cin >> x;
    for (int i = k; i < n; i++) {
        a[i] = x;
        summ += x;
    }
    if (summ > 0) {
        cout << n << endl;
        return 0;
    }
    if (x >= 0) {
        cout << -1 << endl;
        return 0;
    }
    x = abs(x);
    int maxr = n - 1;
    for (int i = 0; i < k; i++) {
        maxr++;
        if (all <= 0) break;
        int kek = all / x;
        if (all % x == 0) kek--;
        maxr = min(maxr, k + kek - 1);
        if (maxr >= n - 1) {
            cout << (n - 1) - i + 1 << endl;
            return 0;
        }
        all -= a[i];
    }
    cout << -1 << endl;
}