#include <cstdlib>
#include <cstdio>
#include <algorithm>
#define maxn 100005
#define rep(i, l, r) for (register int i = l; i <= r; i++) 
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxn, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

char *p1, *p2;;
char buffer[maxn];
template <class T> void read(T& x){
    char ch = gc(); x = 0;
    while (!('0' <= ch && ch <= '9')) ch = gc();
    while ('0' <= ch && ch <= '9') x = (x << 1) + (x << 3) + ch - '0', ch = gc();
}

int n, m;
int a[maxn];
double sum[maxn << 2];
double add[maxn << 2];
double mul[maxn << 2];
int qx, qy;
double qd;

void pushdown(int l, int r, int o){
    if (l == r) return;
    if (mul[o] != 1){
        mul[o << 1] *= mul[o], mul[o << 1 | 1] *= mul[o];
        sum[o << 1] *= mul[o], sum[o << 1 | 1] *= mul[o];
        add[o << 1] *= mul[o], add[o << 1 | 1] *= mul[o];
        mul[o] = 1;
    }
    if (add[o] != 0){
        int mid = ((r - l) >> 1) + l;
        add[o << 1] += add[o], add[o << 1 | 1] += add[o];
        sum[o << 1] += (mid + 1 - l) * add[o], sum[o << 1 | 1] += (r - mid) * add[o];
        add[o] = 0;
    }
}

void pushup(int l, int r, int o){
    if (l == r) return;
    sum[o] = sum[o << 1] + sum[o << 1 | 1];
}

void init(int l, int r, int o){
    mul[o] = 1;
    if (l == r) {
        sum[o] = a[l];
        return;
    }
    int mid = ((r - l) >> 1) + l;
    init(l, mid, o << 1);
    init(mid + 1, r, o << 1 | 1);
    pushup(l, r, o);
}

void Mul(int l, int r, int o){
    pushdown(l, r, o);
    if (qx <= l && r <= qy){
        mul[o] *= qd;
        add[o] *= qd;
        sum[o] *= qd;
        return;
    }
    int mid = ((r - l) >> 1) + l;
    if (qx <= mid) Mul(l, mid, o << 1);
    if (qy > mid) Mul(mid + 1, r, o << 1 | 1);
    pushup(l, r, o);
}

void Add(int l, int r, int o){
    pushdown(l, r, o);
    if (qx <= l && r <= qy){
        add[o] += qd;
        sum[o] += (r - l + 1) * qd;
        return;
    }
    int mid = ((r - l) >> 1) + l;
    if (qx <= mid) Add(l, mid, o << 1);
    if (qy > mid) Add(mid + 1, r, o << 1 | 1);
    pushup(l, r, o);
}

double get(int l, int r, int o){
    pushdown(l, r, o);
    if (qx <= l && r <= qy) return sum[o];
    int mid = ((r - l) >> 1) + l;
    double ans = 0;
    if (qx <= mid) ans += get(l, mid, o << 1);
    if (qy > mid) ans += get(mid + 1, r, o << 1 | 1);
    return ans;
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("eye.in", "r", stdin);
    #endif
    read(n), read(m);
    rep(i, 1, n) read(a[i]);
    init(1, n, 1);
    int op, x, y, z, w;
    rep(i, 1, m){
        read(op);
        if (op == 1){
            read(x), read(y), read(z), read(w);
            int l1 = y - x + 1;
            int l2 = w - z + 1;

            qx = x, qy = y;
            double s1 = get(1, n, 1);
            qd = 1.0 * (l1 - 1) / l1;
            Mul(1, n, 1);

            qx = z, qy = w;
            double s2 = get(1, n, 1);
            qd = 1.0 * (l2 - 1) / l2;
            Mul(1, n, 1);

            qx = x, qy = y, qd = 1.0 / l1 * (1.0 * s2 / l2);
            Add(1, n, 1);

            qx = z, qy = w, qd = 1.0 / l2 * (1.0 * s1 / l1);
            Add(1, n, 1);
        }
        else if (op == 2){
            read(qx), read(qy);
            printf("%.7lf\n", get(1, n, 1));
        }
        else printf("fu*k!\n");
    }
    return 0;
}