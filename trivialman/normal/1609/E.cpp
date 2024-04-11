#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
const int N = 1e5 + 5;

struct dat {
    int a, b, c, ab, bc, abc;
} tr[N * 3];
int T, n, m, q, x;
char s[N];

void merge(dat &x, const dat &y, const dat &z) {
    x.a = y.a + z.a;
    x.b = y.b + z.b;
    x.c = y.c + z.c;
    x.ab = min(y.ab + z.b, y.a + z.ab);
    x.bc = min(y.bc + z.c, y.b + z.bc);
    x.abc = min(y.a + z.abc, min(y.ab + z.bc, y.abc + z.c));
}

void upd(int i, char ch) {
    i += m - 1;
    tr[i] = {0, 0, 0, 0, 0, 0};
    (ch == 'a' ? tr[i].a : (ch == 'b' ? tr[i].b : tr[i].c)) = 1;
    while (i > 1) {
        i >>= 1;
        merge(tr[i], tr[i << 1], tr[i << 1 | 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> q;
    cin >> (s + 1);

    for (m = n + 1; m != (m & -m); m += m & -m);
    rep(i, 1, n) upd(i, s[i]);
    rep(i, 1, q) {
        char ch;
        cin >> x >> ch;
        upd(x, ch);
        cout << tr[1].abc << endl;
    }
    return 0;
}