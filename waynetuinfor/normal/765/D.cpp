#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10;
int f[maxn], g[maxn], h[maxn], b[maxn];
bool v[maxn];
vector<int> a;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> f[i];
    for (int i = 1; i <= n; ++i) {
        if (f[f[i]] && f[f[i]] != f[i]) return cout << "-1" << endl, 0;
    }
    for (int i = 1; i <= n; ++i) if (!v[f[i]]) {
        a.push_back(f[i]); v[f[i]] = true;
    } 
    int m = (int)a.size();
    for (int i = 0; i < a.size(); ++i) {
        b[a[i]] = i + 1;
    }
    for (int i = 1; i <= n; ++i) g[i] = b[f[i]];
    for (int i = 1; i <= m; ++i) h[i] = a[i - 1];
    cout << m << endl;
    for (int i = 1; i <= n; ++i) cout << g[i] << ' '; cout << endl;
    for (int i = 1; i <= m; ++i) cout << h[i] << ' '; cout << endl;
    return 0;
}