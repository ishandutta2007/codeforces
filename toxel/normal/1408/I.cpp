#include <bits/stdc++.h>

const int BIT = 17;
const int N = 1 << BIT;
const int moder = 998244353;

struct poly {
    int a[BIT];

    poly() : a() {}

    int &operator[](const int &n) { return a[n]; }

    poly operator+(const poly &p) const {
        poly ret;
        for (int i = 0; i < BIT; ++i) {
            ret[i] = a[i] + p.a[i];
            ret[i] -= ret[i] >= moder ? moder : 0;
        }
        return ret;
    }

    poly operator-(const poly &p) const {
        poly ret;
        for (int i = 0; i < BIT; ++i) {
            ret[i] = a[i] - p.a[i];
            ret[i] += ret[i] < 0 ? moder : 0;
        }
        return ret;
    }

    poly operator*(const poly &p) const {
        poly ret;
        for (int i = 0; i < BIT; ++i) {
            for (int j = 0; i + j < BIT; ++j) {
                ret[i + j] = (ret[i + j] + 1ll * a[i] * p.a[j]) % moder;
            }
        }
        return ret;
    }

    poly operator*(const int &p) const {
        poly ret;
        for (int i = 0; i < BIT; ++i) {
            ret[i] = 1ll * a[i] * p % moder;
        }
        return ret;
    }
};

int powermod(int a, int exp) {
    int ret = 1;
    for (; exp > 0; exp >>= 1) {
        if (exp & 1) {
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

void FWT_XOR(std::vector<poly> &a, int length, int type) {
    int len = -1;
    for (int x = length; x; ++len, x >>= 1);
    for (int i = 1; i <= len; ++i) {
        for (int j = 0; j < length; j += 1 << i) {
            for (int k = j, szk = 1 << i - 1; k < j + szk; ++k) {
                poly s = a[k], t = a[k + szk];
                a[k] = s + t;
                a[k + szk] = s - t;
            }
        }
    }
    if (type == 1) return;
    int inv = powermod(length, moder - 2);
    for (int i = 0; i < length; ++i) {
        a[i] = a[i] * inv;
    }
}

int a[N];
int cnt[N];
int fac[BIT], inv[BIT], invf[BIT], bitcnt[N];
std::vector<int> vec[N << 1];

int n, k, c;

std::vector<poly> solve(int sit, int l, int r) {
    if (l == r) {
        std::vector<poly> ret(1);
        ret[0][0] = 1;
        return ret;
    }
    int mid = (l + r) / 2;
    std::vector<poly> vec1 = solve(sit << 1, l, mid);
    std::vector<poly> vec2 = solve(sit << 1 | 1, mid + 1, r);
    int len = vec1.size() << 1;
    vec1.resize(len), vec2.resize(len);
    if (cnt[sit << 1 | 1] & 1){
        for (int i = 0; i <= k; ++ i){
            for (int j = 0; j < len / 2; ++ j){
                std::swap(vec2[j][i], vec2[j + len / 2][i]);
            }
        }
    }
    cnt[sit] = cnt[sit << 1] + cnt[sit << 1 | 1];
    FWT_XOR(vec1, len, 1);
    FWT_XOR(vec2, len, 1);
    for (int i = 0; i < len; ++ i){
        vec1[i] = vec1[i] * vec2[i];
    }
    auto update = [&](int u) {
        ++ cnt[sit];
        u &= len - 1;
        std::vector<poly> vec3(len);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j <= k; ++j) {
                vec3[i][j] = bitcnt[i & (u - j)] & 1 ? -invf[j] : invf[j];
                vec3[i][j] += vec3[i][j] < 0 ? moder : 0;
            }
        }
        for (int i = 0; i < len; ++ i){
            vec1[i] = vec1[i] * vec3[i];
        }
    };
    for (auto u : vec[sit << 1]) {
        if (u - k >= l) {
            update(u);
        } else {
            vec[sit].emplace_back(u);
        }
    }
    for (auto u : vec[sit << 1 | 1]) {
        if (u - k >= l) {
            update(u);
        } else {
            vec[sit].emplace_back(u);
        }
    }
    FWT_XOR(vec1, len, 0);
    return vec1;
}

int main() {
    fac[0] = invf[0] = 1;
    for (int i = 1; i < BIT; ++i) {
        fac[i] = 1ll * i * fac[i - 1] % moder;
        inv[i] = i == 1 ? 1 : moder - 1ll * (moder / i) * inv[moder % i] % moder;
        invf[i] = 1ll * invf[i - 1] * inv[i] % moder;
    }
    for (int i = 1; i < N; ++i) {
        bitcnt[i] = bitcnt[i >> 1] + (i & 1);
    }
    scanf("%d%d%d", &n, &k, &c);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        vec[a[i] + (1 << c)].emplace_back(a[i]);
    }
    std::vector<poly> vvec = solve(1, 0, (1 << c) - 1);
    for (int i = 0; i < 1 << c; ++i) {
        int ans = 1ll * vvec[i][k] * fac[k] % moder;
        ans = 1ll * ans * powermod(powermod(n, k), moder - 2) % moder;
        printf("%d%c", ans, " \n"[i == (1 << c) - 1]);
    }
    return 0;
}

/*
4 1 16
1 2 3 4
 */