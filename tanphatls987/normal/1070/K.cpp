#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[100005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> k;
    int s = 0, c = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
    if (s % k) return cout << "No" << endl, 0;
    s /= k;
    vector <int> ans;
    ans.push_back(0);
    for (int i = 1; i <= n; ++i) {
        c += a[i];
        if (c == s) {
            ans.push_back(i);
            c = 0;
        }
        else if (c > s) return cout << "No" << endl, 0;
    }
    if (ans.size() != k + 1) return cout << "No" << endl, 0;
    cout << "Yes" << endl;
    for (int i = 1; i <= k; ++i) cout << ans[i] - ans[i-1] << ' ';
    cout << endl;
    return 0;
}