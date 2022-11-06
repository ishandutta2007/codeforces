#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;
set<int> pos[3];
int fw[3][maxn], f[256];

void add(int *fw, int p, int v) {
    for (int i = p + 1; i < maxn; i += i & -i)
        fw[i] += v;
}

int sum(int *fw, int p) {
    int res = 0;
    for (int i = p + 1; i; i -= i & -i)
        res += fw[i];
    return res;
}

int query(int *fw, int l, int r) {
    return sum(fw, r) - sum(fw, l - 1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    f['P'] = 0, f['R'] = 1, f['S'] = 2;
    int n, q; cin >> n >> q;
    string s; cin >> s;
    for (int i = 0; i < n; ++i) {
        pos[f[s[i]]].insert(i);
        add(fw[f[s[i]]], i, 1);
    }
    function<int(void)> solve = [&]() {
        int res = 0;
        for (int s = 0; s < 3; ++s) {
            int r = (s + 2) % 3, p = (s + 1) % 3;
            if ((int)pos[r].size() == 0) {
                res += (int)pos[s].size();
                continue;
            }
            if ((int)pos[p].size() == 0) continue;
            res += (int)pos[s].size();
            res -= max(0, query(fw[s], *pos[r].begin(), *pos[p].begin()));
            res -= max(0, query(fw[s], *pos[p].rbegin(), *pos[r].rbegin()));
        }
        return res;
    };
    cout << solve() << "\n";
    for (int i = 0; i < q; ++i) {
        int p; char c;
        cin >> p >> c;
        --p;
        add(fw[f[s[p]]], p, -1);
        pos[f[s[p]]].erase(p);
        s[p] = c;
        add(fw[f[s[p]]], p, 1);
        pos[f[s[p]]].insert(p);
        cout << solve() << "\n";
    }
    return 0;
}