#include <bits/stdc++.h>
#define LL long long
#define pii pair <int, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
using namespace std;

const int N = 500010;

pii a[N];
int b[N], bn;
vector <pii> g[N];
multiset <int> st;
multiset <int> :: iterator it;

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, d, m;
    cin >> d >> n >> m;
    for (int i = 1; i <= m; i++) {
        scanf ("%d%d", &a[i].xx, &a[i].yy);
        b[++bn] = a[i].xx;
        if (a[i].xx + n <= d) b[++bn] = a[i].xx + n;
    }
    b[++bn] = 0;
    b[++bn] = d;
    b[++bn] = n;
    a[++m] = pii (0, 0);
    sort (a + 1, a + 1 + m);
    sort (b + 1, b + 1 + bn);
    bn = unique (b + 1, b + 1 + bn) - b - 1;
//    for (int i = 1; i <= bn; i++) cout << b[i] << ' '; cout << endl;
    for (int i = 1; i <= m; i++) {
        if (i > 1 && a[i].xx - a[i - 1].xx > n) {
            cout << -1;
            return 0;
        }
        int id = lower_bound (b + 1, b + 1 + bn, a[i].xx) - b;
        g[id].push_back (pii (a[i].yy, 1));
        if (a[i].xx + n <= d) {
            id = lower_bound (b + 1, b + 1 + bn, a[i].xx + n) - b;
//            cout << id << endl;
            g[id].push_back (pii (a[i].yy, -1));
        }
    }
    if (d - a[m].xx > n) {
        cout << -1;
        return 0;
    }
    LL r = 0;
    for (int i = 1; i <= bn; i++) {
        if (i > 1) {
            r += 1LL * (b[i] - b[i - 1]) * (*st.begin());
//            cout << i << ' ' << b[i] - b[i - 1] << ' ' << (*st.begin()) << endl;
        }
        for (int j = 0; j < g[i].size(); j++) if (g[i][j].yy == 1) {
            st.insert (g[i][j].xx);
//            cout <<"ins" << g[i][j].xx << endl;
        }
        for (int j = 0; j < g[i].size(); j++) if (g[i][j].yy == -1) {
            it = st.find (g[i][j].xx);
            st.erase(it);
//            cout <<"del" << g[i][j].xx << endl;
        }
    }
    cout << r << endl;
}