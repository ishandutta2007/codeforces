#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
const int mod = 998244353;
using matrix = vector<vector<int>>;

matrix mult(matrix &a, matrix &b) {
    int n = (int)a.size();
    matrix c(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                c[i][j] += a[i][k] * 1ll * b[k][j] % (mod - 1);
                if (c[i][j] >= mod - 1)
                    c[i][j] -= mod - 1;
            }
        }
    }
    return c;
}

int fpow(int a, int n, int z) {
    int res = 1;
    while (n) {
        if (n & 1) res = res * 1ll * a % z;
        a = a * 1ll * a % z;
        n >>= 1;
    }
    return res;
}

template <typename T> tuple<T, T, T> extgcd(T a, T b) {
    if (!b) return make_tuple(a, 1, 0);
    T d, x, y;
    tie(d, x, y) = extgcd(b, a % b);
    return make_tuple(d, y, x - (a / b) * y);
}

int bsgs(int a, int b, int p) {
    // return L such that a^L = b (mod p)
    if (p == 1) {
        if (!b) return a != 1;
        return -1;
    }
    if (b == 1) {
        if (a) return 0;
        return -1;
    }
    if (a % p == 0) {
        if (!b) return 1;
        return -1;
    }
    int num = 0, d = 1;
    while (true) {
        int r = __gcd(a, p);
        if (r == 1) break;
        if (b % r) return -1;
        ++num;
        b /= r, p /= r;
        d = (1ll * d * a / r) % p;
    }
    for (int i = 0, now = 1; i < num; ++i, now = 1ll * now * a % p) {
        if (now == b) return i;
    }
    int m = ceil(sqrt(p)), base = 1;
    map<int, int> mp;
    for (int i = 0; i < m; ++i) {
        if (mp.find(base) == mp.end()) mp[base] = i;
        else mp[base] = min(mp[base], i);
        base = 1ll * base * a % p;
    }
    for (int i = 0; i < m; ++i) {
        // can be modified to fpow if p is prime
        int r, x, y; tie(r, x, y) = extgcd(d, p);
        x = (1ll * x * b % p + p) % p;
        if (mp.find(x) != mp.end()) return i * m + mp[x] + num;
        d = 1ll * d * base % p;
    }
    return -1;
}

int main() {
    int k; scanf("%d", &k);
    vector<int> b(k);
    for (int i = 0; i < k; ++i) scanf("%d", &b[i]);
    int n, m; scanf("%d%d", &n, &m);
    vector<vector<int>> mt(k, vector<int>(k)), mz(k, vector<int>(k));
    for (int i = 0; i < k; ++i) {
        if (i + 1 < k) {
            mt[i][i + 1] = 1;
            continue;
        }
        int z = 0;
        for (int j = i; j >= 0; --j)
            mt[i][j] = b[z++];
    }
    int p = n - k;
    for (int i = 0; i < k; ++i) mz[i][i] = 1;
    while (p > 0) {
        if (p & 1) mz = mult(mz, mt);
        mt = mult(mt, mt);
        p >>= 1;
    }
    int pw = n == k ? 1 : n > k ? mz[k - 1][k - 1] : 0;
    int kpw = bsgs(3, m, mod);
    if (kpw < 0) {
        puts("-1");
        return 0;
    }
    int d, x, y; 
    tie(d, x, y) = extgcd(pw, mod - 1);
    if (kpw % d) {
        puts("-1");
        return 0;
    }
    long long ans = x * 1ll * (kpw / d) % (mod - 1);
    while (ans < 0) ans += (mod - 1) / d;
    ans %= (mod - 1);
    printf("%d\n", fpow(3, ans, mod));
    return 0;
}