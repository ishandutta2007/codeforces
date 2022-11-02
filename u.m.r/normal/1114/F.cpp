#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 4e5 + 10;
const int MM = 1e9 + 7;

ll pw(ll p, ll q) {
    ll ret = 1;
    for (; q; q >>= 1) {
        if (q & 1) ret = ret * p % MM;
        p = p * p % MM;
    }
    return ret;
}

int M;

class LazySeg {
public:
    struct Node_s {
        ll A, cnt;
        ll sum, faq;
    } tree[MAXN * 4]; // sum * A ^ cnt

    void pushdown(int u) {
        if (u >= M || tree[u].A == 1) return ;
        int p = u * 2, q = p + 1;
        tree[u].sum = tree[u].faq;
        tree[p].A = (tree[p].A * tree[u].A) % MM;
        tree[p].faq = tree[p].faq * pw(tree[u].A, tree[p].cnt) % MM;
        tree[q].A = (tree[q].A * tree[u].A) % MM;
        tree[q].faq = tree[q].faq * pw(tree[u].A, tree[p].cnt) % MM;
        tree[u].A = 1;
    }

    void Update(int u, int L, int R, int l, int r, ll x) {
        if (l == L && r == R) {
            tree[u].A = (tree[u].A * x) % MM;
            tree[u].faq = (tree[u].sum * pw(tree[u].A, tree[u].cnt)) % MM;
            return ;
        }
        pushdown(u);
        int M = (L + R) / 2;
        if (r <= M) Update(u * 2, L, M, l, r, x);
        else if (l > M) Update(u * 2 + 1, M + 1, R, l, r, x);
        else {
            Update(u * 2, L, M, l, M, x);
            Update(u * 2 + 1, M + 1, R, M + 1, r, x);
        }
        tree[u].faq = tree[u].sum = (tree[2 * u].faq) * (tree[2 * u + 1].faq) % MM;
    }

    ll Query(int u, int L, int R, int l, int r) {
        if (l == L && r == R) {
            tree[u].faq = (tree[u].sum * pw(tree[u].A, tree[u].cnt)) % MM;
            return tree[u].faq;
        }
        pushdown(u);
        int M = (L + R) / 2;
        if (r <= M) return Query(u * 2, L, M, l, r);
        else if (l > M) return Query(u * 2 + 1, M + 1, R, l, r);
        else {
            return (Query(u * 2, L, M, l, M) * Query(u * 2 + 1, M + 1, R, M + 1, r)) % MM;
        }
    }
} powt;

class OrSeg {
public:
    struct Node_s {
        ll lz, msk;
    } tree[MAXN * 4];

    void pushdown(int u) {
        if (u >= M) return ;
        int p = u * 2, q = p + 1;
        tree[u].msk |= tree[u].lz;
        tree[p].lz |= tree[u].lz;
        tree[q].lz |= tree[u].lz;
        tree[u].lz = 0;
    }

    void Update(int u, int L, int R, int l, int r, ll x) {
        if (l == L && r == R) {
            tree[u].lz |= x;
            return ;
        }
        pushdown(u);
        int M = (L + R) / 2;
        if (r <= M) Update(u * 2, L, M, l, r, x);
        else if (l > M) Update(u * 2 + 1, M + 1, R, l, r, x);
        else {
            Update(u * 2, L, M, l, M, x);
            Update(u * 2 + 1, M + 1, R, M + 1, r, x);
        }
        tree[u].msk |= tree[u * 2].msk | tree[u * 2].lz | tree[u * 2 + 1].msk | tree[u * 2 + 1].lz;
    }

    ll Query(int u, int L, int R, int l, int r) {
        if (l == L && r == R) {
            return tree[u].lz | tree[u].msk;
        }
        pushdown(u);
        int M = (L + R) / 2;
        if (r <= M) return Query(u * 2, L, M, l, r);
        else if (l > M) return Query(u * 2 + 1, M + 1, R, l, r);
        else {
            return (Query(u * 2, L, M, l, M) | Query(u * 2 + 1, M + 1, R, M + 1, r));
        }
    }
} mskt;

vector<int> pm;
int idx[555];
ll inv[555];
char s[555];

void solve(int casi){
    for (int i = 2; i <= 300; i++) {
        int flag = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                flag = 0;
            }
        }
        if (flag) {
            idx[i] = pm.size();
            pm.emplace_back(i);
            inv[i] = pw(i, MM - 2);
        }
        else idx[i] = -1;
    }
    // cerr << pm.size() << endl;
    int n, Q;
    scanf("%d%d", &n, &Q);
    for (M = 1; M < n; M *= 2);
    for (int i = 1; i <= 2 * M; i++) mskt.tree[i].msk = mskt.tree[i].lz = 0;
    for (int i = 1; i <= 2 * M; i++) {
        powt.tree[i].sum = powt.tree[i].A = powt.tree[i].faq = 1;
    }
    for (int i = M; i <= 2 * M; i++) powt.tree[i].cnt = 1;
    for (int i = M - 1; i >= 1; i--) {
        powt.tree[i].cnt = powt.tree[i * 2].cnt + powt.tree[i * 2 + 1].cnt;
    }
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        ll msk = 0;
        for (auto &p : pm) {
            if (x % p == 0) {
                msk |= (1ll << idx[p]);
            }
        }
        mskt.Update(1, 1, M, i, i, msk);
        powt.Update(1, 1, M, i, i, x);
    }
    while (Q--) {
        int l, r;
        scanf("%s%d%d", s, &l, &r);
        if (s[0] == 'M') {
            int x;
            scanf("%d", &x);
            ll msk = 0;
            for (auto &p : pm) {
                if (x % p == 0) {
                    msk |= (1ll << idx[p]);
                }
            }
            mskt.Update(1, 1, M, l, r, msk);
            powt.Update(1, 1, M, l, r, x);
        }
        else {
            ll ans = powt.Query(1, 1, M, l, r);
            ll msk = mskt.Query(1, 1, M, l, r);
            // cout << "!! " << ans << endl;
            for (int i = 0; i < 62; i++) {
                if ((msk >> i) & 1) {
                    // cout << "?? " << pm[i] << endl;
                    ans = ans * inv[pm[i]] % MM * (pm[i] - 1) % MM;
                }
            }
            printf("%lld\n", ans);
        }
    }
}

int main(){
    int T = 1;
    for (int i = 1; i <= T; i++)
        solve(i);
    return 0;
}