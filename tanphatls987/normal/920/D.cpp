#include <bits/stdc++.h>

using namespace std;

const int N = 5e3 + 10;
const int inf = 1e9 + 10;

int n, k, need;
int a[N];
bool f[N][N];
bool t[N][N];

int drop[N];

void pour(int fro, int to, int am) {
    if (am) {
        cout << am << " " << fro << " " << to << '\n';
    }
}

void solve() {
    f[0][0] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < k; j++) {
            int fro = (j - (a[i] % k) + k) % k;
            f[i][j] = f[i - 1][j];
            if (f[i - 1][fro]) {
                f[i][j] = 1;
                t[i][j] = 1;
            }
        }
    }
    //cout << f[n][need % k] << '\n';
    if (!f[n][need % k]) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    vector<int> use;
    for(int i = n; i >= 1; i--) {
        if (t[i][(k + need % k) % k]) {
            need -= a[i];
            use.push_back(i);
        }
    }
    //cout << need << '\n';
    for(auto i : use) drop[i] = 1;
    for(auto i : use) if (i != use[0]) 
        pour(i, use[0], (a[i] + k - 1) / k);
    
    if (need > 0) {
        int st = 1;
        while (drop[st]) st++;
        for(int i = st + 1; i <= n; i++) if (!drop[i]) 
            pour(i, st, (a[i] + k - 1) / k);
        pour(st, use[0], need / k);
    } else if (need < 0) {
        pour(use[0], (use[0] == 1) + 1, (-need) / k); 
    }
}
int main() {
    cin >> n >> k >> need;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0;
    for(int i = 1; i <= n; i++) sum += a[i];
    if (sum < need) {
        cout << "NO";
        return 0;
    }
    if (need % k == 0) {
        cout << "YES\n";
        for(int i = 2; i <= n; i++)
            pour(i, 1, (a[i] + k - 1) / k);
        pour(1, 2, need / k);
        return 0;
    }
    solve();
}