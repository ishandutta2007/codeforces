#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int mod;
vector<int> BIT(N, 0);

void Add(int x, int val) {
    for (; x < N; x += x & -x) BIT[x] = (BIT[x] + val + mod) % mod;
}

void Add(int l, int r, int val) {
    Add(l, val);
    Add(r + 1, -val);
}

int Get(int x) {
    int res = 0;
    for (; x > 0; x -= x & -x) res += BIT[x], res %= mod;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m >> mod;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Add(i, i, a[i]);
    }
    vector<int> b(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
        Add(i, i + n - m, b[i]);
    }
    for (int i = 1; i <= n; i++) {
        cout << Get(i) << " ";
    }
    return 0;
}