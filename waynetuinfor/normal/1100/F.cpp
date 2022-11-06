#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e5 + 5;
vector<int> bs[maxn];
int c[maxn], ans[maxn], r[maxn];
vector<int> qr[maxn];

void add(int p, int v) {
    for (int i = p + 1; i < maxn; i += i & -i) {
        int x = v;
        for (int j = 0; j < (int)bs[i].size(); ++j)
            x = min(x, bs[i][j] ^ x);
        if (x) bs[i].push_back(x);
    }
}

vector<int> query(int p) {
    vector<int> res;
    for (int i = p + 1; i; i -= i & -i) {
        for (int j = 0; j < (int)bs[i].size() && res.size() < 20; ++j) {
            int x = bs[i][j];
            for (int k = 0; k < (int)res.size(); ++k)
                x = min(x, res[k] ^ x);
            if (x) res.push_back(x);
        }
    }
    return res;
}


int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
    int q; scanf("%d", &q);
    for (int i = 0; i < q; ++i) {
        int l; scanf("%d%d", &l, &r[i]);
        --l, --r[i];
        qr[l].push_back(i);
    }
    for (int i = n - 1; i >= 0; --i) {
        add(i, c[i]);
        for (int j = 0; j < (int)qr[i].size(); ++j) {
            vector<int> b = query(r[qr[i][j]]);
            for (int k = 0; k < (int)b.size(); ++k)
                ans[qr[i][j]] = max(ans[qr[i][j]], ans[qr[i][j]] ^ b[k]);
        }
    }
    for (int i = 0; i < q; ++i) printf("%d\n", ans[i]);
    return 0;
}