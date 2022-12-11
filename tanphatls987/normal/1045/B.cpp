#include <bits/stdc++.h>

using namespace std;

const int mod = 1007050321;
int n, m;
int a[500005];
int s[500005];
int t[500005];
vector <int> ans;

bool check(int i) {
    for (int j = 1, k = i; j <= n; ++j, k = k % n + 1) if (s[j] != t[k]) return 0;
    return 1;
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i) s[i] = a[i] - a[i - 1];
    s[1] = a[1] + m - a[n];
    for (int i = 1; i <= n; ++i) {
        t[i] = s[n + 1 - i];
    }
    long long key = 0, base = m + 77, cur = 0, pw = 1;
    for (int i = 1; i <= n; ++i) key = (key * base + s[i]) % mod;
    for (int i = 1; i <= n; ++i) cur = (cur * base + t[i]) % mod;
    for (int i = 1; i < n; ++i) pw = pw * base % mod;
    for (int i = 1; i <= n; ++i) {
        if (key == cur) ans.push_back((a[n] + a[n + 1 - i]) % m);
        cur = ((cur - pw * t[i]) % mod + mod) % mod;
        cur = (cur * base + t[i]) % mod;
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    if (ans.size()) {
        for (auto x: ans) cout << x << ' ';
        cout << endl;
    }
    return 0;
}