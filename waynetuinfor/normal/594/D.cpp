#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, mod = 1e9 + 7;

inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline int sub(int a, int b) { return a - b < 0 ? a - b + mod : a - b; }
inline int mul(int a, int b) { return a * 1ll * b % mod; }

int a[maxn], inv[maxn], prod[maxn];
int l[maxn], r[maxn], pre[maxn], ans[maxn];
bool v[maxn];
vector<int> pr, divs[maxn];

void init() {
    inv[1] = 1;
    for (int i = 2; i < maxn; ++i) inv[i] = mul(inv[mod % i], mod - mod / i);
    for (int i = 2; i < maxn; ++i) if (!v[i]) {
        divs[i].push_back(i);
        for (int j = i + i; j < maxn; j += i) divs[j].push_back(i), v[j] = true;
    } 
}

int fpow(int a, int n) {
    int ret = 1;
    for (; n; n >>= 1) {
        if (n & 1) ret = mul(ret, a);
        a = mul(a, a);
    }
    return ret;
}

struct fenwick {
    int data[maxn];
    void init() { fill(data, data + maxn, 1); }
    void add(int p, int v) { for (; p < maxn; p += p & -p) data[p] = mul(data[p], v); }
    int qry(int p, int v = 1) { for (; p; p -= p & -p) v = mul(v, data[p]); return v; } 
} bit;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    init();
    prod[0] = 1;
    for (int i = 1; i <= n; ++i) prod[i] = mul(prod[i - 1], a[i]);
    int q; cin >> q; 
    vector<int> query;
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
        query.push_back(i);
    }
    sort(query.begin(), query.end(), [&](const int &a, const int &b) { return r[a] < r[b]; });
    int p = 1;
    bit.init();
    for (int i : query) {
        while (p <= r[i]) {
            for (int j : divs[a[p]]) {
                if (pre[j]) bit.add(pre[j], mul(j, inv[j - 1]));
                bit.add(p, mul(j - 1, inv[j]));
                pre[j] = p;
            }
            ++p;
        }
        ans[i] = mul(bit.qry(r[i]), fpow(bit.qry(l[i] - 1), mod - 2));
        ans[i] = mul(ans[i], mul(prod[r[i]], fpow(prod[l[i] - 1], mod - 2)));
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << endl;
    return 0;
}