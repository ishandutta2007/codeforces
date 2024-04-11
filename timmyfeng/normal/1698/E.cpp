#include <bits/stdc++.h>
using namespace std;

vector<int> inv(vector<int> p) {
    vector<int> q(p.size(), -1);
    for (int i = 0; i < p.size(); ++i) {
        if (p[i] != -1)
            q[p[i]] = i;
    }
    return q;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;

    while (t--) {
        int n, s; cin >> n >> s;

        vector<int> a(n), b(n);
        for (auto &i : a) cin >> i, --i;
        for (auto &i : b) cin >> i, i -= (i > 0);
        
        a = inv(a), b = inv(b);

        vector<int> pos(n, -1);
        for (int i = 0; i < n; ++i)
            if (b[i] != -1) pos[b[i]] = i;

        long long answer = 1;
        int prefix = count(b.end() - s, b.end(), -1);
        for (int i = n - 1; i >= 0; --i) {
            prefix += (i >= s && b[i - s] == -1);
            if (pos[a[i]] == -1) {
                answer = answer * max(0, prefix) % 998244353;
                --prefix;
            } else {
                answer *= (i - pos[a[i]] <= s);
            }
        }

        cout << answer << "\n";
    }
}