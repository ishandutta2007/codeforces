#include <bits/stdc++.h>
#define LL long long
#define pii pair <LL, LL>
#define xx first
#define yy second
using namespace std;

const int N = 501000;

int x[N], y[N];
char s[N][2];

set <pii> st;
set <pii> :: iterator it;
int n, p, q;

int solve () {
    st.clear();
//    st.insert (pii (q, 0));
    for (int i = 1; i <= n; i++) {
        if (p == x[i]) st.insert (pii (y[i], s[i][0]));
    }
    it = st.lower_bound (pii (q, 0));
    if (it != st.end() && (*it).yy != 'B') return 1;
    if (it != st.begin()) {
        it--;
        if ((*it).yy != 'B') return 1;
    }

    st.clear();
//    st.insert (pii (p, q));
    for (int i = 1; i <= n; i++) {
        if (q == y[i]) st.insert (pii (x[i], s[i][0]));
    }
    it = st.lower_bound (pii (p, 0));
    if (it != st.end() && (*it).yy != 'B') return 1;
    if (it != st.begin()) {
        it--;
        if ((*it).yy != 'B') return 1;
    }

    st.clear();
//    st.insert (pii (p, q));
    for (int i = 1; i <= n; i++) {
        if (q + p == y[i] + x[i]) {
            st.insert (pii (x[i] - y[i], s[i][0]));
//            cout << i << endl;
        }
    }
    it = st.lower_bound (pii (p - q, 0));
    if (it != st.end() && (*it).yy != 'R') return 1;
    if (it != st.begin()) {
        it--;
        if ((*it).yy != 'R') return 1;
    }

    st.clear();
//    st.insert (pii (p, q));
    for (int i = 1; i <= n; i++) {
        if (q - p == y[i] - x[i]) st.insert (pii (x[i] + y[i], s[i][0]));
    }
    it = st.lower_bound (pii (p + q, 0));
    if (it != st.end() && (*it).yy != 'R') return 1;
    if (it != st.begin()) {
        it--;
        if ((*it).yy != 'R') return 1;
    }
    return 0;
}

int main () {
//    freopen ("in.txt", "r", stdin);
    cin >> n;
//    cout <<  n << endl;
    cin >> p >> q;
    for (int i = 1; i <= n; i++) {
        scanf ("%s%d%d", s[i], &x[i], &y[i]);
    }
    if (solve ()) cout << "YES";
    else cout << "NO";
}