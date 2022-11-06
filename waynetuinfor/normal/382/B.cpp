#include <bits/stdc++.h>
using namespace std;

const int maxn = 2000 + 10;
const long long inf = 1e18 + 10;
long long a, b, w, x, c;
long long t[maxn], nxt[maxn], tot;
vector<long long> sum;
vector<int> pre;
bool v[maxn];

bool check(long long x) {
    // cout << "x = " << x << endl;
    long long tmp = x;
    long long s = 0;
    for (int i = 0; i < pre.size() && tmp > 0; ++i) {
        s += min(tmp, (long long)t[pre[i]] - 1);
        tmp -= max(0, (int)t[pre[i]]);
    }
    long long m = tmp / tot;
    s += m * (tot - (int)sum.size());
    tmp -=  m * tot;
    int ind = 0;
    while (ind < sum.size() && tmp > 0) {
        s += min(tmp, (long long)sum[ind] - 1);
        tmp -= max(0, (int)sum[ind]);
        ++ind;
    }
    // cout << "s = " << s << endl;
    return c - s <= a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> a >> b >> w >> x >> c;
    for (int i = 0; i <= 2 * w; ++i) {
        int tmp = i;
        while (tmp >= x) ++t[i], tmp -= x;
        nxt[i] = tmp + w - x;
        ++t[i];
    }
    // for (int i = 0; i <= w; ++i) cout << nxt[i] << ' '; cout << endl;
    int cur = b;
    vector<int> vec;
    while (true) {
        if (v[cur]) {
            int j = 0;
            while (j < vec.size() && vec[j] != cur) ++j;
            for (int i = 0; i < j; ++i) pre.push_back(vec[i]), tot -= t[vec[i]];
            for (int i = j; i < vec.size(); ++i) sum.push_back(t[vec[i]]);
            break;
        }
        vec.push_back(cur);
        v[cur] = true;
        tot += t[cur];
        cur = nxt[cur];
    }
    // cout << "tot = " << tot << endl;
    // cout << "Sz = " << sum.size() << endl;
    // for (int i : sum) cout << i << ' '; cout << endl;
    long long d = 1LL, ans = inf; while (d < inf) d <<= 1;
    while (d >>= 1) if (ans - d >= 0) if (check(ans - d)) ans -= d;
    cout << ans << endl;
    return 0;
}