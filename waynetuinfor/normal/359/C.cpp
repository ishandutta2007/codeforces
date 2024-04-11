#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 10, mod = 1e9 + 7;
const long long inf = 1e18;
int a[maxn], cnt[maxn];

int mul(int a, int b) { return (long long)a * (long long)b % mod; }

int fpow(int a, long long n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x; cin >> n >> x;
    long long s = 0;
    bool same = true;
    for (int i = 1; i <= n; ++i) cin >> a[i], s += a[i];
    long long g = inf;
    for (int i = 1; i <= n; ++i) {
        g = min(g, s - a[i]);
    }
    vector<int> vec;
    for (int i = 1; i <= n; ++i) vec.push_back(s - a[i] - g);
    sort(vec.begin(), vec.end());
    int ind = 0;
    for (int i = 0; i < maxn - 1; ++i) {
        while (ind < vec.size() && vec[ind] == i) {
            ++cnt[i]; cnt[i + 1] += cnt[i] / x;
            cnt[i] %= x;
            ++ind;
        }
    }
    int add = 0;
    for (int i = 0; i < maxn; ++i) {
        cnt[i + 1] += cnt[i] / x; cnt[i] %= x;
        if (cnt[i]) {
            add = i;
            break;
        } 
    }
    cout << fpow(x, min(g + add, s)) << endl;
    return 0;
}