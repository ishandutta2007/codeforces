#include <bits/stdc++.h>
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <int, int>
#define LL long long
#define xx first
#define yy second
using namespace std;

const int N = 100100;

struct segment {
    int sum[N << 2], lazy[N << 2];
    void init () {
        memset (sum, 0, sizeof sum);
        memset (lazy, -1, sizeof lazy);
    }
    void down (int rt, int l, int r) {
        if (lazy[rt] != -1) {
            lazy[ls] = lazy[rt];
            lazy[rs] = lazy[rt];
            int m = l + r >> 1;
            sum[ls] = (m - l + 1) * lazy[rt];
            sum[rs] = (r - m) * lazy[rt];
            lazy[rt] = -1;
        }
    }
    void updata (int rt, int l, int r, int tl, int tr, int c) {
        if (tl <= l && r <= tr) {
            lazy[rt] = c;
            sum[rt] = c * (r - l + 1);
            return;
        }
        down (rt, l, r);
        int m = l + r >> 1;
        if (tr <= m) updata (lson, tl, tr, c);
        else if (m < tl) updata (rson, tl, tr, c);
        else updata (lson, tl, m, c), updata (rson, m + 1, tr, c);
        sum[rt] = sum[ls] + sum[rs];
    }
    int query (int rt, int l, int r, int tl, int tr) {
        if (tl <= l && r <= tr) return sum[rt];
        down (rt, l, r);
        int m = l + r >> 1;
        if (tr <= m) return query (lson, tl, tr);
        else if (m < tl) return query (rson, tl, tr);
        else return query (lson, tl, m) + query (rson, m + 1, tr);
    }
} t[30];

char s[N];
int c[30];

int main () {
//    freopen ("out.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    scanf ("%s", s);
    for (int i = 0; i < 26; i++) t[i].init();
//    cout << 'x' << endl;
    for (int i = 0; i < n; i++) t[s[i] - 'a'].updata (1, 1, n, i + 1, i + 1, 1);
//    cout << 'x' << endl;
    while (q--) {
        int x, y, k;
//        cout << q << endl;
        scanf ("%d%d%d", &x, &y, &k);
//        cout << x << ' ' << y <<' ' << k << endl;
        for (int i = 0; i < 26; i++) c[i] = t[i].query (1, 1, n, x, y), t[i].updata (1, 1, n, x, y, 0);
//        cout << x << ' ' << y <<' ' << k << endl;
//        for (int i = 0; i< 26; i++) if (c[i]) {
//            cout << i << ' '<< c[i] << endl;
//        }
        int now = x;
        if (k) {
            for (int i = 0; i < 26; i++) if (c[i]) {
                t[i].updata (1, 1, n, now, now + c[i] - 1, 1);
                now += c[i];
            }
        } else {
            for (int i = 25; i >= 0; i--) if (c[i]) {
                t[i].updata (1, 1, n, now, now + c[i] - 1, 1);
                now += c[i];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (t[j].query(1, 1, n, i + 1, i + 1)) {
                s[i] = j + 'a';
                break;
            }
        }
    }
    printf ("%s", s);
}