#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 201000;

int a[N], b[N], c[N], d[N];

set <pii> st;
set <pii> :: iterator it;
LL res;
int n, m, k, x, s;

LL solve (int x, int y) {
//    cout << x << ' ' << y << endl;
    it = st.lower_bound (pii (y, 2e9 + 10));
    if (it == st.begin ()) return 1LL * x * n;
    it--;
//    cout << (*it).yy << endl;
    return 1LL * x * max (n - (*it).yy, 0LL);
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m >> k >> x >> s;
    for (int i = 1; i <= m; i++) scanf ("%d", &a[i]);
    for (int i = 1; i <= m; i++) scanf ("%d", &b[i]);
    for (int i = 1; i <= k; i++) scanf ("%d", &c[i]);
    for (int i = 1; i <= k; i++) scanf ("%d", &d[i]);
    for (int i = 1; i <= k; i++) {
        st.insert (pii (d[i], c[i]));
    }
    LL res = solve (x, s);
//    cout << res << endl;
    for (int i = 1; i <= m; i++) {
        if (s - b[i] >= 0) res = min (res, solve (a[i], s - b[i]));
    }
    cout << res << endl;
}