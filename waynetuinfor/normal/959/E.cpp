#include <bits/stdc++.h>
using namespace std;

const int maxn = 100;

struct djset {
    int p[maxn];
    void init() { for (int i = 0; i < maxn; ++i) p[i] = i; }
    int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
    void merge(int x, int y) { p[find(x)] = find(y); }
} djs;

int solve(int n) {
    djs.init();
    vector<tuple<int, int, int>> ed;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) ed.emplace_back((i ^ j), i, j);
    }
    sort(ed.begin(), ed.end());
    int ans = 0;
    map<int, int> cc;
    for (auto e : ed) {
        int c, a, b; tie(c, a, b) = e;
        if (djs.find(a) == djs.find(b)) continue;
        ans += c;
        ++cc[c];
        djs.merge(a, b);
    }
    for (auto i : cc) cout << i.first << ": " << i.second << ", "; cout << endl;
    return ans;
}

int main() {
    long long n; cin >> n;
    long long ans = 0;
    for (long long t = 1; ; t <<= 1) {
        long long s = t + 1;
        if (s > n) break;
        // long long c = (n - s + 1) / (t * 2);
        // long long p = (1 + c) * c / 2;
        // long long q = p * (t * 2);
        // q += (c + 1) * ((n - s + 1) % (t * 2));
        long long q = ((n - s + 1) % (t + t) == 0 ? (n - s + 1) / (t + t) : (n - s + 1) / (t + t) + 1);
        // cout << "t = " << t << " c = " << c << " p = " << p << " q = " << q << endl;
        ans += t * q;
    }
    cout << ans << endl;
}