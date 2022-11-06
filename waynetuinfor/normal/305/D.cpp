#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;
int t[maxn], s[maxn];
bool v[maxn];

void imp() { cout << "0" << endl; exit(0); }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
    t[0] = 1;
    for (int i = 1; i < maxn; ++i) t[i] = t[i - 1] * 2 % mod;
    vector<int> ed;
    while (m--) {
        int a, b; cin >> a >> b;
        if (b != a + 1 && b - a - k != 1) imp();
        if (b != a + 1) ed.push_back(a), ++s[a], v[a] = true;
    }
    if (ed.size() > 0 && ed.front() + k + 1 <= ed.back()) imp();
    for (int i = 1; i <= n; ++i) s[i] += s[i - 1];
    int ans = (ed.size() > 0) ^ 1;
    for (int i = 1; i <= n; ++i) if (i + k + 1 <= n && s[i - 1] == 0 && s[n] - s[i + k] == 0) {
        int to = i + k + 1;
        int opt = min(k, n - i - k - 1);
        // cout << "i = " << i << endl;
        // cout << "opt = " << opt << endl;
        (ans += t[opt - s[to] + s[i]]) %= mod;
    }
    cout << ans << endl;
    return 0; 
}