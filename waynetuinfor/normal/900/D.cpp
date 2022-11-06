#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

vector<int> pr;

void sieve() {
    bitset<32000> v;
    for (int i = 2; i < 32000; ++i) {
        if (!v[i]) pr.push_back(i);
        for (int j = 0; i * pr[j] < 32000; ++j) {
            v[i * pr[j]] = true;
            if (i % pr[j] == 0) break;
        }
    }
}


int main() {
    sieve();
    int x, y; cin >> x >> y;
    int dx = x;
    if (y % x) return cout << "0" << endl, 0;
    int m = y / x;
    vector<int> f;
    int ind = 0;
    while (m > 1 && ind < pr.size()) {
        if (m % pr[ind] == 0) f.push_back(pr[ind]);
        while (m % pr[ind] == 0) m /= pr[ind];
        ++ind;
    }
    if (m > 1) f.push_back(m);
    int sz = f.size();
    int ans = 0;
    for (int s = 0; s < (1 << sz); ++s) {
        int d = 1;
        for (int i = 0; i < sz; ++i) {
            if ((1 << i) & s) d *= f[i];
        }
        int k = y / x / d;
        if (!(__builtin_popcount(s) & 1)) ans = add(ans, fpow(2, k - 1));
        else ans = sub(ans, fpow(2, k - 1));
    }
    cout << ans << endl;
    // sort(f.begin(), f.end()); f.resize(unqiue(f.begin()))
    return 0;
}