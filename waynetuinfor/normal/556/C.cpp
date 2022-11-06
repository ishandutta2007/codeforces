#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
vector<int> a[maxn];
int pos[maxn], ptr[maxn], id[maxn];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    int st = -1;
    long long ans = 0;
    for (int i = 0; i < k; ++i) {
        int m; cin >> m;
        a[i].resize(m);
        for (int j = 0; j < m; ++j) {
            cin >> a[i][j];
            pos[a[i][j]] = j;
            id[a[i][j]] = i;
            if (a[i][j] == 1) st = i;
        }
        ans += a[i].size() - 1 + a[i].size();
    }
    int need = 2;
    int prv = 0;
    while (need <= n && id[need] == id[1]) ++need, ans -= 2;
    --ans;
    cout << ans << endl;
    return 0;
}