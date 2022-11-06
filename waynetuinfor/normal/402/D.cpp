#include <bits/stdc++.h>
using namespace std;

const int maxn = 5000 + 10;
int a[maxn], g[maxn];
bool v[31625];
vector<int> p;
set<int> b;

void sieve() {
    for (int i = 2; i < 31625; ++i) {
        if (!v[i]) p.push_back(i);
        for (int j = 0; i * p[j] < 31625; ++j) {
            v[i * p[j]] = true;
            if (i % p[j] == 0) break;
        }
    }
}

pair<int, int> count(int gcd) {
    pair<int, int> ret = make_pair(0, 0);
    for (int i : p) {
        if (gcd == 1) break;
        int cnt = 0;
        while (gcd % i == 0) gcd /= i, ++cnt;
        if (b.count(i)) ret.second += cnt;
        else ret.first += cnt;
    }
    if (gcd > 1) {
        if (b.count(gcd)) ret.second++;
        else ret.first++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    sieve();
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) {
        int p; cin >> p; b.insert(p);
    }
    g[1] = a[1];
    for (int i = 2; i <= n; ++i) g[i] = __gcd(g[i - 1], a[i]);
    for (int i = n; i >= 1; --i) {
        pair<int, int> res = count(g[i]);
        if (res.second > res.first) {
            for (int j = 1; j <= i; ++j) a[j] /= g[i];
            for (int j = 1; j <= i; ++j) g[j] /= g[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        pair<int, int> res = count(a[i]);
        ans += res.first - res.second;
    }
    cout << ans << endl;
    return 0;
}