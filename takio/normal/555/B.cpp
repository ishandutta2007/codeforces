#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define piii pair <pii, LL>
#define pb push_back
#define xx first
#define yy second
using namespace std;

const int N = 200100;
const LL INF = 1e18;
int n, m, res[N];
LL l[N], r[N];
pii a[N];
piii q[N];
set <pii> st;
set <pii> :: iterator it;

int solve () {
    if (m < n - 1) return 0;
    int now = 1;
    for (int i = 1; i <= m; i++) {
//        cout << q[i].l <<' ' << q[i].r <<' ' << q[i].id << endl;
        while (now < n && q[now].xx.xx <= a[i].xx) {
            st.insert (pii (q[now].xx.yy, q[now].yy));
//            cout << q[now].xx.yy << ' ' << q[now].yy << endl;
            now++;
        }
//        if (now >= n) return 0;
        if (!st.empty ()) {
            it = st.begin ();
            if ((*it).xx < a[i].xx) {
                return 0;
            }
            res[(*it).yy] = a[i].yy;
            st.erase (it);
        }
    }
    for (int i = 1; i < n; i++) {
        if (res[i] == 0) return 0;
    }
    cout << "Yes\n";
    for (int i = 1; i < n; i++) {
        printf ("%d ", res[i]);
    }
    return 1;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        scanf ("%I64d%I64d", &l[i], &r[i]);
        if (i > 1) q[i - 1] = piii (pii (l[i] - r[i - 1], r[i] - l[i - 1]), i - 1);
    }
    for (int i = 1; i <= m; i++) {
        scanf ("%I64d", &a[i].xx);
        a[i].yy = i;
    }
    sort (a + 1, a + 1 + m);
    sort (q + 1, q + n);
    if (!solve ()) {
        cout << "No";
    }
}