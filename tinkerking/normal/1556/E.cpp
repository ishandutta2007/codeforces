#include <bits/stdc++.h>
#define ls (x * 2)
#define rs (x * 2 + 1)
#define mid ((L + R) / 2)
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int n, m;
LL a[2000100], b[2000010];
LL val[2000010];
const int MAXN = 1600010;
struct SegmentTree1 {
    struct Node {
        LL sum, lmax, rmax, smax;
    }T[MAXN];
    Node merge(Node n1, Node n2) {
        Node ret;
        ret.sum = n1.sum + n2.sum;
        ret.lmax = max(n1.lmax, n1.sum + n2.lmax);
        ret.rmax = max(n2.rmax, n2.sum + n1.rmax);
        ret.smax = max(max(n1.smax, n2.smax), n1.rmax + n2.lmax);
        return ret;
    }
    void upd(int x) {
        T[x] = merge(T[x * 2], T[x * 2 + 1]);
    }
    Node query(int x, int L, int R, int ql, int qr) {
        if (L == ql && R == qr) return T[x];
        if (qr <= mid) return query(ls, L, mid, ql, qr);
        if (ql > mid) return query(rs, mid + 1, R, ql, qr);
        return merge(query(ls, L, mid, ql, mid), query(rs, mid + 1, R, mid + 1, qr));
    }
    void build(int x, int L, int R) {
        if (L == R) {
            T[x] = (Node){val[L], max(0LL, val[L]), max(0LL, val[L]), max(0LL, val[L])};
            return;
        }
        build(ls,L,mid);
        build(rs,mid+1,R);
        T[x] = merge(T[ls],T[rs]);
    }
}T1;

struct SegmentTree2 {
    struct Node {
        LL sum, lmin, rmin, smin;
    }T[MAXN];
    Node merge(Node n1, Node n2) {
        Node ret;
        ret.sum = n1.sum + n2.sum;
        ret.lmin = min(n1.lmin, n1.sum + n2.lmin);
        ret.rmin = min(n2.rmin, n2.sum + n1.rmin);
        ret.smin = min(min(n1.smin, n2.smin), n1.rmin + n2.lmin);
        return ret;
    }
    void upd(int x) {
        T[x] = merge(T[x * 2], T[x * 2 + 1]);
    }
    Node query(int x, int L, int R, int ql, int qr) {
        if (L == ql && R == qr) return T[x];
        if (qr <= mid) return query(ls, L, mid, ql, qr);
        if (ql > mid) return query(rs, mid + 1, R, ql, qr);
        return merge(query(ls, L, mid, ql, mid), query(rs, mid + 1, R, mid + 1, qr));
    }
    void build(int x, int L, int R) {
        if (L == R) {
            T[x] = (Node){val[L], min(0LL, val[L]), min(0LL, val[L]), min(0LL, val[L])};
            return;
        }
        build(ls,L,mid);
        build(rs,mid+1,R);
        T[x] = merge(T[ls],T[rs]);
    }
}T2;

int main() {
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&a[i]);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld",&b[i]);
    }
    for (int i = 1; i <= n; i++) {
        val[i] = b[i] - a[i];
    }
    T1.build(1,1,n);
    T2.build(1,1,n);
    while(m--) {
        int L, R;
        scanf("%d%d",&L,&R);
        auto mi = T2.query(1,1,n,L,R);
        if (mi.lmin < 0 || mi.sum != 0) {
            puts("-1");
            continue;
        }
        auto ma = T1.query(1,1,n,L,R);
        LL ans = max(ma.smax, -mi.smin);
        ans = max(0LL, ans);
        printf("%lld\n",ans);
    }
}