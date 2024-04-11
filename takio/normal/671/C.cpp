#include <bits/stdc++.h>
#define LL long long
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pii pair <int, int>
#define xx first
#define yy second
using namespace std;

const int N = 200100, INF = 1e9;
int l[2][N], r[2][N];
set <pii> st;
set <pii> :: iterator it;

void updata (int x, int p) {
    if (!l[0][x] || l[0][x] > p) {
        l[1][x] = l[0][x];
        l[0][x] = p;
    } else if (!l[1][x] || l[1][x] > p) l[1][x] = p;
    if (!r[0][x] || r[0][x] < p) {
        r[1][x] = r[0][x];
        r[0][x] = p;
    } else if (!r[1][x] || r[1][x] < p) r[1][x] = p;
}

LL area;

void solve (int x, int p) {
    if (x > p) return;
//    cout << x << ' ' << p << endl;
    it = st.lower_bound (pii (x, INF));
    it--;
    if ((*it).yy >= p) return;
    int nx = x, np = (*it).yy;
//    cout << nx << ' ' << np << endl;
//    cout << (*it).xx << ' ' << (*it).yy << endl;
    if ((*it).xx != x) it++;
    while (it != st.end()) {
//        cout << nx << ' ' << np << ' ' << (*it).xx << ' ' << (*it).yy << endl;
        area += 1LL * ((*it).xx - nx) * (p - np);
        nx = (*it).xx;
        np = (*it).yy;
        if (np > p) break;
        st.erase(it++);
    }
    st.insert(pii(x, p));
}

int main () {
//    freopen ("in.txt", "r", stdin);
    int n, a;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        scanf ("%d", &a);
        for (int j = 1; j * j <= a; j++) if (a % j == 0) {
            updata (j, i);
            if (j * j != a) updata (a / j, i);
        }
    }
    for (int i = 1; i < N; i++) {
        st.insert (pii (i, i - 1));
    }
    LL res = 0;
    for (int i = N - 1; i >= 1; i--) {
        LL tmp = area;
        if (l[0][i] && r[0][i] && l[0][i] != r[0][i]) {
//            cout << i << ' ' << l[0][i] << ' ' << l[1][i] << ' ' << r[0][i] << ' ' << r[1][i] << endl;
            solve (l[1][i] + 1, n);
            solve (1, r[1][i] - 1);
            solve (l[0][i] + 1, r[0][i] - 1);
        }
        res += (area - tmp) * i;
//        if (area) cout << area << endl;
    }
    cout << res << endl;
}