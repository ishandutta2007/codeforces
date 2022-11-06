#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n; vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    int ind = 0;
    for (; ind < n - 1; ++ind) if (a[ind + 1] <= a[ind]) break;
    for (; ind < n - 1; ++ind) if (a[ind + 1] != a[ind]) break;
    for (; ind < n - 1; ++ind) if (a[ind + 1] >= a[ind]) break;
    cout << (ind == n - 1 ? "YES" : "NO") << endl;
    return 0;
}