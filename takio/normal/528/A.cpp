#include <bits/stdc++.h>
#define xx first
#define yy second
#define pii pair <int, int>
#define LL long long
using namespace std;

set <int> x, y;
set <int> ::iterator it11, it22;
int cnt1[200100], cnt2[200100];

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, m, q;
    cin >> n >> m >> q;
    x.clear(), y.clear();
    x.insert(0);
    x.insert(n);
    y.insert(0);
    y.insert(m);
    cnt1[n]++, cnt2[m]++;
    int mx1 = n, mx2 = m;
    char s;
    int t;
    while (q--) {
        getchar();
        scanf ("%c%d", &s, &t);
        if (s == 'V') {
            it11 = x.lower_bound(t);
            it22 = it11;
            it11--;
            int t1 = (*it11), t2 = (*it22);

            cnt1[t2 - t1]--;
            cnt1[t2 - t]++;
            cnt1[t - t1]++;
            x.insert(t);
        } else {
            it11 = y.lower_bound(t);
            it22 = it11;
            it11--;
            int t1 = (*it11), t2 = (*it22);

            cnt2[t2 - t1]--;
            cnt2[t2 - t]++;
            cnt2[t - t1]++;
            y.insert(t);
        }
        while (!cnt1[mx1] && mx1 > 1) mx1--;
        while (!cnt2[mx2] && mx2 > 1) mx2--;
//        cout << (*it1) << ' ' << (*it2) << endl;
        printf ("%I64d\n", 1LL * mx1 * mx2);
    }
}