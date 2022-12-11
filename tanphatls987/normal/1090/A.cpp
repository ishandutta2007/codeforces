#include <bits/stdc++.h>

using namespace std;

int n, a[200005][2];
int main() {
    cin >> n;
    int dem = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i][0];
        for(int j = 1; j <= a[i][0]; j++) {
            int x;
            cin >> x;
            a[i][1] = max(a[i][1], x);
        }
        dem = max(dem, a[i][1]);
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++) ans += 1LL * (dem - a[i][1]) * a[i][0];
    cout << ans;
}