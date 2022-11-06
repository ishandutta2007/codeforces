#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int a[maxn], cnt[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k, m; cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        ++cnt[a[i] % m];
    }
    for (int i = 0; i < m; ++i) if (cnt[i] >= k) {
        int g = 0;
        cout << "Yes" << endl;
        for (int j = 0; j < n && g < k; ++j) {
            if (a[j] % m == i) cout << a[j] << ' ', ++g;
        } 
        cout << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;
}