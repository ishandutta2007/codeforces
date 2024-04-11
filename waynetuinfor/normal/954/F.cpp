#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

struct matrix {
    int a[4][4];
    matrix() { memset(a, 0, sizeof(a)); }
    friend ostream &operator<<(ostream &s, const matrix &r) {
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) s << r.a[i][j] << ' ';
            s << endl;
        }
        return s;
    }
};

matrix matmul(const matrix &a, const matrix &b) {
    matrix r;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            for (int k = 0; k < 4; ++k) r.a[i][j] = (r.a[i][j] + a.a[i][k] * 1ll * b.a[k][j] % mod) % mod;
        }
    }
    return r;
}

matrix fpow(matrix a, long long n) {
    matrix r;
    for (int i = 0; i < 4; ++i) r.a[i][i] = 1;
    for (; n; n >>= 1, a = matmul(a, a)) if (n & 1) r = matmul(r, a);
    return r;
}

int cnt[4];
int v[4] = { 0, 0, 1, 0 };
int nv[4] = { 0, 0, 0, 0 };

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n;
    long long m; cin >> n >> m;
    vector<pair<long long, int>> vec;
    for (int i = 0; i < n; ++i) {
        int a; long long l, r; cin >> a >> l >> r;
        vec.emplace_back(l, a), vec.emplace_back(r + 1, -a);
    }
    sort(vec.begin(), vec.end());
    matrix l;
    for (int i = 1; i <= 3; ++i) {
        for (int j = 1; j <= 3; ++j) {
            if (abs(i - j) < 2) l.a[i][j] = 1;
        }
    }
    long long prv = 1;
    for (int i = 0; i < vec.size(); ) {
        int j = i;
        while (j < vec.size() && vec[j].first == vec[i].first) {
            if (vec[j].second > 0) ++cnt[vec[j].second];
            else --cnt[-vec[j].second];
            ++j;
        }
        matrix k;
        for (int p = 1; p <= 3; ++p) {
            for (int q = 1; q <= 3; ++q) {
                if (cnt[q] == 0 && abs(p - q) < 2) k.a[q][p] = 1;
            }
        }
        memset(nv, 0, sizeof(nv));
        // cout << "i = " << vec[i].first << " prv = " << prv << endl;
        // cout << "before:\n"; cout << l << endl;
        l = fpow(l, vec[i].first - 1 - prv);
        // cout << "after:\n"; cout << l << endl;
        for (int p = 1; p <= 3; ++p) {
            for (int q = 1; q <= 3; ++q) nv[p] = (nv[p] + l.a[p][q] * 1ll * v[q] % mod) % mod;
        }
        for (int p = 1; p <= 3; ++p) v[p] = nv[p];
        // for (int i = 1; i <= 3; ++i) cout << v[i] << ' '; cout << endl;
        l = k;
        prv = vec[i].first - 1;
        i = j;
    }
    l = fpow(l, m - prv);
    memset(nv, 0, sizeof(nv));
    for (int p = 1; p <= 3; ++p) {
        for (int q = 1; q <= 3; ++q) nv[p] = (nv[p] + l.a[p][q] * 1ll * v[q] % mod) % mod;
    }
    cout << nv[2] << endl;
}