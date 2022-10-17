#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    int ans = 1e9;
    for(int i = 0; i + 1 < n; ++i) {
        int x = a[i], y = a[i + 1];
        if(x > y) swap(x, y);
        int cnt = 0;
        if(2 * x >= y) {
            cnt = (x + y + 2) / 3;
        } else {
            cnt = (y + 1) / 2;
        }
        ans = min(ans, cnt);
    }
    for(int i = 0; i + 2 < n; ++i) {
        int x = a[i], y = a[i + 2];
        if(x % 2 && y % 2) ans = min(ans, x / 2 + y / 2 + 1);
    }
    sort(a.begin(), a.end());
    ans = min(ans, (a[0] + 1) / 2 + (a[1] + 1) / 2);
    cout << ans << '\n';
}