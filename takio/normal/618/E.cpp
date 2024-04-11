#include <bits/stdc++.h>
#define LL long long
#define ULL unsigned long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 300100;
const double pi = acos (-1.0);

struct mat {
    double a[3][3];
    mat () {
        memset (a, 0, sizeof a);
    }
    void one () {
        memset (a, 0, sizeof a);
        a[0][0] = a[1][1] = a[2][2] = 1;
    }
    void w () {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j< 3; j++) cout << a[i][j] << ' ';
            cout << endl;
        } cout << endl;
    }
}A, B, C;

mat sum[N << 2], lazy[N << 2];
int ok[N << 2];

mat mul (mat A, mat B) {
    mat C;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                C.a[i][j] += A.a[i][k] * B.a[k][j];
            }
        }
    }
    return C;
}

void build (int rt, int l, int r) {
//    for (int i = 0; i < 3; i++) lazy[rt].a[i][i] = 1;
    lazy[rt].one ();
    if (l == r) {
        sum[rt].a[0][0] = l - 1;
        sum[rt].a[0][1] = 0;
        sum[rt].a[0][2] = 1;
        return;
    }
    int m = l + r >> 1;
    build (lson);
    build (rson);
}

void down (int rt) {
    if (ok[rt]) {
        ok[rt] = 0;
        sum[ls] = mul (sum[ls], lazy[rt]);
        sum[rs] = mul (sum[rs], lazy[rt]);
        lazy[ls] = mul (lazy[ls], lazy[rt]);
        lazy[rs] = mul (lazy[rs], lazy[rt]);
        ok[ls] = ok[rs] = 1;
        lazy[rt].one ();
    }
}

void updata (int rt, int l, int r, int tl, int tr, mat t) {
//    cout << l << ' ' << r << ' ' << tl << ' ' << tr << endl;
    if (tl <= l && r <= tr) {
        sum[rt] = mul (sum[rt], t);
        lazy[rt] = mul (lazy[rt], t);
        ok[rt] = 1;
        return;
    }
    down (rt);
    int m = l + r >> 1;
    if (tr <= m) updata (lson, tl, tr, t);
    else if (m < tl) updata (rson, tl, tr, t);
    else updata (lson, tl, m, t), updata (rson, m + 1, tr, t);
}

mat query (int rt, int l, int r, int x) {
    if (l == r) {
        return sum[rt];
    }
//    cout << l << ' ' << r << endl;
//    if (ok[rt]) {
//        cout << l << ' ' << r << endl;
//        lazy[rt].w();
//    }
    down (rt);
    int m = l + r >> 1;
    if (x <= m) return query (lson, x);
    return query (rson, x);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, x, y, z;
    cin >> n >> m;
    n++;
    build (1, 1, n);
//    A = query (1, 1, n, n);
//    printf ("%.10f %.10f\n", A.a[0][0], A.a[0][1]);
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d%d", &x, &y, &z);
        if (x == 1) {
            A = query (1, 1, n, y);
            B = query (1, 1, n, y + 1);
            double dx = B.a[0][0] - A.a[0][0];
            double dy = B.a[0][1] - A.a[0][1];
            double dz = sqrt (dx * dx + dy * dy);
//            mat C;
            C.one ();
            C.a[2][0] = z * dx / dz;
            C.a[2][1] = z * dy / dz;
//            C.w ();
            updata (1, 1, n, y + 1, n, C);
        } else {
            A = query (1, 1, n, y);
            double dx = A.a[0][0], dy = A.a[0][1];
            A.one ();
            A.a[2][0] = -dx;
            A.a[2][1] = -dy;
            B.one ();
            double d = pi * z / 180;
//            cout << d << endl;
            B.a[0][0] = cos (d);
            B.a[0][1] = -sin (d);
            B.a[1][0] = sin (d);
            B.a[1][1] = cos (d);
            C.one ();
            C.a[2][0] = dx;
            C.a[2][1] = dy;
            A = mul (mul (A, B), C);
//            A.w ();
            updata (1, 1, n, y + 1, n, A);
//            A = mul (query (1, 1, n, n), A);
//            printf ("%.10f %.10f\n", A.a[0][0], A.a[0][1]);
        }
        A = query (1, 1, n, n);
        printf ("%.10f %.10f\n", A.a[0][0], A.a[0][1]);
    }
}