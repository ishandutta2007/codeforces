#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 200005;
const int maxm = 800005;
int p[maxn], a[maxn];
ll ans[maxn];
ll inv[maxn];
struct BIT {
    int ft[maxn];
    void upd(int x, int y) {
        for (; x < maxn; x += x & -x) ft[x] += y;
    }
    int qry(int x) {
        int res = 0;
        for (; x > 0; x -= x & -x) res += ft[x];
        return res;
    }
    int qry(int l, int r) {
        return qry(r) - qry(l - 1);
    }
} bit;
struct ST {
    ll st[maxm], lzy[maxm];
    void push(int node, int l, int r) {
        st[node] += lzy[node] * (r - l + 1);
        if (l != r) {
            lzy[node * 2] += lzy[node];
            lzy[node * 2 + 1] += lzy[node];
        }
        lzy[node] = 0;
    }
    void upd(int node, int l, int r, int ql, int qr, int x) {
        push(node, l, r);
        if (l > qr || r < ql) return;
        if (ql <= l && r <= qr) {
            lzy[node] += x; push(node, l, r);
            return;
        }
        int mid = l + r >> 1;
        upd(node * 2, l, mid, ql, qr, x); upd(node * 2 + 1, mid + 1, r, ql, qr, x);
        st[node] = st[node * 2] + st[node * 2 + 1];
    }
    ll qry(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (l > qr || r < ql) return 0LL;
        if (ql <= l && r <= qr) return st[node];
        int mid = l + r >> 1;
        return qry(node * 2, l, mid, ql, qr) + qry(node * 2 + 1, mid + 1, r, ql, qr);
    }
} st;
int main() {
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
        a[p[i]] = i;
    }
    ll ssum = 0;
    for (int i = 1; i <= n; i++) {
        inv[i] = inv[i - 1];
        inv[i] += bit.qry(a[i] + 1, n);
        bit.upd(a[i], 1);
        int trg = (i + 1) / 2;
        int bot = 1, top = n, pos = n + 1;
        while (bot <= top) {
            int mid = bot + top >> 1;
            if (bit.qry(1, mid) >= trg) pos = mid, top = mid - 1;
            else bot = mid + 1;
        }
        st.upd(1, 1, n, a[i], n, 1);
        ans[i] += st.qry(1, 1, n, 1, pos - 1);
        ans[i] += (n - pos + 1) * 1LL * i - st.qry(1, 1, n, pos, n);
        ssum += i / 2;
        ans[i] -= ssum;
    }
    for (int i = 1; i <= n; i++) {
        printf("%lld ", ans[i] + inv[i]);
    }
    return 0;
}