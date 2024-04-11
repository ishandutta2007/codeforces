#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    map<string, int> was;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        was[a[i]] = 1;
    }
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        cnt += was[b[i]];
    }
    int k1 = n - cnt / 2, k2 = m - (cnt + 1) / 2;
    if (k1 > k2) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }
    return 0;
}