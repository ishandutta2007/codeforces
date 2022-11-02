#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e5 + 10;
const int MM = 998244353;

int n, m;
int a[MAXN];
int dp[MAXN];

void updS(int &x, int y) {
    x -= y;
    if (x < 0) x += MM;
}

void updA(int &x, int y) {
    x += y;
    if (x >= MM) x -= MM;
}

namespace Block {
    const int Bibi = 1024;
    const int N = 1e5 + 10;
    const int B = N / Bibi + 10;
    int val[N];
    int cnt;
    struct block {
        int l, r;
        ll lazy_tag = 0;
        ll presum_tag = 0;
        int cnt[N * 2];
        void update(int l, int r, int v) {
            if (v == 1) {
                for (int i = l; i <= r; i++) {
                    updS(cnt[val[i]], dp[i]);
                    val[i]++;
                }
            }
            else {
                for (int i = l; i <= r; i++) {
                    val[i]--;
                    updA(cnt[val[i]], dp[i]);
                }
            }
        }
        int query(int v) {
            v = v - lazy_tag;
            if (v < 0) return 0;
            v += N;
            return (cnt[v] + presum_tag) % MM;
        }
    } b[B];
    void init(int n) {
        // [1, Bibi], [Bibi + 1, 2 * Bibi]
        cnt = (n - 1) / Bibi + 1;
        for (int i = 1; i <= cnt; i++) {
            b[i].r = min(n, i * Bibi);
            b[i].l = (i - 1) * Bibi + 1;
        }
        for (int i = 1; i <= n; i++) val[i] = N;
    }
    int get_block(int x) {
        return (x - 1) / Bibi + 1;
    }
    void update(int l, int r, int v) {
        if (l > r) return ;
        int p = get_block(l), q = get_block(r);
        if (p == q) b[p].update(l, r, v);
        else {
            b[p].update(l, b[p].r, v);
            b[q].update(b[q].l, r, v);
            for (int i = p + 1; i < q; i++) {
                b[i].lazy_tag += v;
            }
        }
    }
    int query(int v) {
        ll ans = 0;
        for (int i = 1; i <= cnt; i++) {
            ans += b[i].query(v);
        }
        return (ans % MM);
    }
}

int pre[MAXN], ppre[MAXN];

void solve(int casi){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pre[i] = ppre[i] = 0;
    }
    Block::init(n);
    dp[1] = 1;
    for (int i = 1; i <= n; i++) {
        int v = a[i];
        Block::b[Block::get_block(i)].presum_tag += dp[i];
        Block::update(pre[v] + 1, i, 1);
        Block::update(ppre[v] + 1, pre[v], -1);
        ppre[v] = pre[v];
        pre[v] = i;
        dp[i + 1] = Block::query(m);
    }
    printf("%d\n", dp[n + 1]);
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}