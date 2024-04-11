#include <iostream>
#include <cmath>
#include <map>

using namespace std;

using ll = long long;
using ld = long double;

const ll MOD = 998244353;

template <typename T>
T gcd(T a, T b) {
    if (a < b) return gcd(b, a);
    return b == 0 ? a : gcd(b, a % b);
}

template <typename T, typename U>
T mypow(T b, U n) {
    if (n == 0) return 1;
    if (n == 1) return b;
    if (n % 2 == 0) {
        return mypow(b * b, n / 2);
    } else {
        return mypow(b, n - 1) * b;
    }
}

int main() {
    int N;
    cin >> N;
    map<ll, int> s;
    for (int i = 0; i < N; ++i) {
        ll b;
        cin >> b;
        if (!s.count(b)) s[b] = 0;
        ++s[b];
    }

    N = s.size();
    ll a[N], c[N];
    {
        int i = 0;
        for (auto p : s) {
            a[i] = p.first;
            c[i] = p.second;
            ++i;
        }
    }

    ll ans = 1;
    map<ll, int> cnt;
    for (int i = 0; i < N; ++i) {
        bool divided = false;

        for (int k = 4; k >= 2; --k) {
            ll p = roundl(powl((ld)a[i], (ld)1 / k));
            if (mypow(p, k) == a[i]) {
                divided = true;
                if (!cnt.count(p)) cnt[p] = 0;
                cnt[p] += k * c[i];
                break;
            }
        }
        if (divided) continue;

        for (int j = 0; j < N; ++j) {
            if (i == j) continue;
            ll g = gcd(a[i], a[j]);
            if (g == 1) continue;

            divided = true;
            if (!cnt.count(g)) cnt[g] = 0;
            cnt[g] += c[i];

            if (!cnt.count(a[i] / g)) cnt[a[i] / g] = 0;
            cnt[a[i] / g] += c[i];
            break;
        }
        if (divided) continue;

        ans *= (c[i] + 1) * (c[i] + 1);
        ans %= MOD;
    }

    for (auto p : cnt) {
        ans *= p.second + 1;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}