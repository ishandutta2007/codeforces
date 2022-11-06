#include <bits/stdc++.h>
#define mid ((L + R) / 2)
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

const int MAXN = 200010;
int N, Q;
char s[MAXN], t[MAXN];

int tag[8 * MAXN], sum[8 * MAXN];

void pushdown(int x, int L, int R) {
    if (tag[x] != -1) {
        sum[x * 2] = (mid - L + 1) * tag[x];
        sum[x * 2 + 1] = (R - mid) * tag[x];
        tag[x * 2] = tag[x];
        tag[x * 2 + 1] = tag[x];
        tag[x] = -1;
    }
}

void maintain(int x) {
    sum[x] = sum[x * 2] + sum[x * 2 + 1];
}

int getsum(int x, int L, int R, int ql, int qr) {
    if (ql == L && qr == R) {
        return sum[x];
    }
    pushdown(x, L, R);
    if (qr <= mid) return getsum(x * 2, L, mid, ql, qr);
    if (ql > mid) return getsum(x * 2 + 1, mid + 1, R, ql, qr);
    return getsum(x * 2, L, mid, ql, mid) + getsum(x * 2 + 1, mid + 1, R, mid + 1, qr);
}

void update(int x,int L,int R,int ql,int qr,int val) {
    if (L == ql && R == qr) {
        tag[x] = val;
        sum[x] = (R - L + 1) * val;
        return;
    }
    pushdown(x, L, R);
    if (qr <= mid) update(x * 2, L, mid, ql, qr, val);
    else if (ql > mid) update(x * 2 + 1, mid + 1, R, ql, qr, val);
    else {
        update(x * 2, L, mid, ql, mid, val);
        update(x * 2 + 1, mid + 1, R, mid + 1, qr, val);
    }
    maintain(x);
}

void build(int x,int L,int R) {
    tag[x] = -1;
    if (L == R) {
        sum[x] = s[L] - '0';
        return;
    }
    build(x*2, L, mid);
    build(x*2+1, mid+1, R);
    maintain(x);
}

int l[200010], r[200010];

int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d",&N,&Q);
        scanf("%s", t + 1);
        scanf("%s", s + 1);
        for (int i=1;i<=Q;i++) {
            scanf("%d%d",&l[i],&r[i]);
        }
        build(1, 1, N);
        bool ok = true;
        for (int i=Q;i>=1;i--) {
            int L = l[i], R = r[i], len;
            len = (R - L + 1);
            int S = getsum(1, 1, N, L, R);
            if (len % 2 == 0 && S == len / 2) {
                ok = false;
            }
            if (S <= len / 2) {
                update(1, 1, N, L, R, 0);
            } else {
                update(1, 1, N, L, R, 1);
            }
        }
        for (int i=1;i<=N;i++) {
            if (getsum(1, 1, N, i, i) != t[i] - '0') {
                ok = false;
            }
        }
        puts(ok ? "YES" : "NO");
    }
}