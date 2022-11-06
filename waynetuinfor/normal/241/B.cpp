#include <bits/stdc++.h>
using namespace std;

const int maxn = 5e4 + 10, maxd = 31;
const int mod = 1e9 + 7;
int a[maxn], n;
long long m;

inline int mul(int a, int b) { return a * 1ll * b % mod; }
inline int add(int a, int b) { return a + b >= mod ? a + b - mod : a + b; }
inline void cadd(int &a, int b) { a = add(a, b); }
inline void cmul(int &a, int b) { a = mul(a, b); }

struct trie {
    trie *ch[2];
    int cnt, dp[2][maxd];
    trie(): cnt(0) { ch[0] = ch[1] = nullptr; memset(dp, 0, sizeof(dp)); }
    void pull() {
        cnt = 0;
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < 2; ++i) if (ch[i]) {
            cnt += ch[i]->cnt;
            for (int j = 0; j < maxd; ++j) {
                cadd(dp[0][j], ch[i]->dp[0][j]);
                cadd(dp[1][j], ch[i]->dp[1][j]);
            }
        }
    }
    void insert(int v, int d) {
        if (d < 0) {
            ++cnt;
            for (int i = 0; i < maxd; ++i) {
                if ((1ll << i) & v) cadd(dp[1][i], 1);
                else cadd(dp[0][i], 1);
            }
            return;
        }
        int b = v >> d & 1;
        if (!ch[b]) ch[b] = new trie();
        ch[b]->insert(v, d - 1);
        pull();
    }
    long long queryc(int a, int v, int d) {
        if (d < 0) return 0;
        int ab = a >> d & 1;
        int vb = v >> d & 1;
        // cout << "a = " << a << " v = " << v << " d = " << d << " ab = " << ab << " vb = " << vb << endl;
        int ret = 0;
        if (vb == 1) return (ch[ab ^ 1] ? ch[ab ^ 1]->queryc(a, v, d - 1) : 0);
        ret += (ch[ab ^ 1] ? ch[ab ^ 1]->cnt : 0);
        if (ch[ab]) ret += ch[ab]->queryc(a, v, d - 1);
        return ret;
    }
    long long querys(int a, int v, int d) {
        if (d < 0) return mul(cnt, v % mod);
        int ab = a >> d & 1;
        int vb = v >> d & 1;
        int ret = 0;
        // cout << "a = " << a << " v = " << v << " d = " << d << " ab = " << ab << " vb = " << vb << endl;
        if (vb == 1) return (ch[ab ^ 1] ? ch[ab ^ 1]->querys(a, v, d - 1) : 0); 
        // if (ch[ab ^ 1]) cout << "bang" << endl;
        if (ch[ab ^ 1]) for (int i = 0; i < maxd; ++i) {
            if ((1ll << i) & a) cadd(ret, mul((1ll << i) % mod, ch[ab ^ 1]->dp[0][i]));
            else cadd(ret, mul((1ll << i) % mod, ch[ab ^ 1]->dp[1][i]));
            // cout << endl;
        }
        if (ch[ab]) cadd(ret, ch[ab]->querys(a, v, d - 1));
        return ret;
    }
} *tr;

bool check(long long v) {
    // cout << "check v = " << v << endl;
    long long c = 0;
    for (int i = 1; i <= n; ++i) {
        // cout << "a[i] = " << a[i] << " query = " << tr->queryc(a[i], v, maxd) << endl;
        c += tr->queryc(a[i], v, maxd);
    }   
    // cout << "c = " << c << endl;
    c >>= 1;
    return c <= m - 1;
}

int32_t main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    tr = new trie();
    for (int i = 1; i <= n; ++i) cin >> a[i], tr->insert(a[i], maxd);
    int b = maxd; long long kth = (1ll << b); while (b--) if (kth - (1ll << b) >= 0) if (check(kth - (1ll << b))) kth -= (1ll << b);
    int ans = 0;
    for (int i = 1; i <= n; ++i) cadd(ans, tr->querys(a[i], kth + 1, maxd));
    long long c1 = 0, c2 = 0;
    for (int i = 1; i <= n; ++i) c1 += tr->queryc(a[i], kth - 1, maxd), c2 += tr->queryc(a[i], kth, maxd);
    c1 >>= 1; c2 >>= 1;
    // cout << "c = " << c << endl;
    cmul(ans, 500000004ll);
    cadd(ans, mul((m - c2) % mod, kth % mod));
    cout << ans << endl;
    return 0;
}