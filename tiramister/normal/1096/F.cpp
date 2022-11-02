#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

const ll MOD = 998244353;

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b % MOD;
    if (n % 2 == 0) {
        return mypow(b * b % MOD, n / 2);
    } else {
        return mypow(b, n - 1) * b % MOD;
    }
}


class BIT {
public:
    explicit BIT(ll N, ll v) : V_NUM(N) {
        data.resize(N);
        fill(data.begin(), data.end(), v);
    }

    ll query(ll i) {
        ll ret = 0;
        while (i > 0) {
            ret += data[i];
            i -= (i & -i);
        }
        return ret;
    }

    void update(ll i, ll v) {
        while (i < V_NUM) {
            data[i] += v;
            i += (i & -i);
        }
    }

    ll V_NUM;
    vector<ll> data;
};

ll inv(ll n) {
    return mypow(n, MOD - 2);
}

int main() {
    ll N;
    cin >> N;

    int a[N];
    bool appear[N + 1];
    fill(appear, appear + N + 1, false);
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
        if (a[i] > 0) appear[a[i]] = true;
    }

    vector<int> rest;
    for (int i = 1; i <= N; ++i) {
        if (!appear[i]) rest.push_back(i);
    }

    ll M = rest.size();
    ll ans = M * (M - 1) % MOD * inv(4) % MOD;

    BIT bit(N + 1, 0);
    ll buf = 0, neg = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (a[i] > 0) {
            ans += bit.query(a[i]);
            ans %= MOD;

            ll less = upper_bound(rest.begin(), rest.end(), a[i]) - rest.begin();
            buf += less * neg % MOD;
            buf += (M - less) * (M - neg) % MOD;
            buf %= MOD;

            bit.update(a[i], 1);
        } else {
            ++neg;
        }
    }

    ans += buf * inv(M);
    ans %= MOD;
    cout << ans << endl;
    return 0;
}