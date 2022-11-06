#include <bits/stdc++.h>
using namespace std;

const int maxn = 3e5 + 10;
int p[maxn];
char c[maxn];
vector<int> g, r, b;

long long solve(const vector<int> &v, int gl, int gr) {
    int s = upper_bound(v.begin(), v.end(), gl) - v.begin();
    int t = prev(lower_bound(v.begin(), v.end(), gr)) - v.begin();
    if (s >= v.size() || v[s] > gr) return 0;
    if (t < 0 || v[t] < gl) return 0;
    int cut = 0;
    if (s < v.size()) cut = max(cut, v[s] - gl);
    if (t >= 0) cut = max(cut, gr - v[t]);
    long long ret = gr - gl;
    for (int i = s; i < t; ++i) {
        cut = max(cut, v[i + 1] - v[i]);
    }
    return ret - cut;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> p[i] >> c[i];
        if (c[i] == 'P') g.push_back(p[i]);
        else if (c[i] == 'R') r.push_back(p[i]);
        else if (c[i] == 'B') b.push_back(p[i]);
    }
    if (g.size() == 0) {
        long long ans = 0;
        if (r.size()) ans += r.back() - r.front();
        if (b.size()) ans += b.back() - b.front();
        cout << ans << endl;
        return 0;
    }
    long long ans = 0;
    int rto = prev(lower_bound(r.begin(), r.end(), g.front())) - r.begin();
    int bto = prev(lower_bound(b.begin(), b.end(), g.front())) - b.begin();
    for (int i = 1; i <= rto; ++i) ans += r[i] - r[i - 1];
    for (int i = 1; i <= bto; ++i) ans += b[i] - b[i - 1];
    if (rto >= 0) ans += g[0] - r[rto]; if (bto >= 0) ans += g[0] - b[bto];
    rto = upper_bound(r.begin(), r.end(), g.back()) - r.begin();
    bto = upper_bound(b.begin(), b.end(), g.back()) - b.begin();
    for (int i = r.size() - 2; i >= rto; --i) ans += r[i + 1] - r[i];
    for (int i = b.size() - 2; i >= bto; --i) ans += b[i + 1] - b[i];
    if (rto < r.size()) ans += r[rto] - g.back(); if (bto < b.size()) ans += b[bto] - g.back();
    for (int i = 0; i < g.size() - 1; ++i) {
        ans += min(2ll * g[i + 1] - 2ll * g[i], solve(r, g[i], g[i + 1]) + solve(b, g[i], g[i + 1]) + g[i + 1] - g[i]);
    }
    cout << ans << endl;
    return 0;
}