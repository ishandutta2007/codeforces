#include <bits/stdc++.h>
#define int long long

using namespace std;

const int K = 70, N = 1e5 + 7, INF = 1e9 + 7;
int a[N];
int mini[K];

int get(int pos) {
    return mini[pos + 35];
}

void st(int pos, int val, bool flag = 0) {
    if (flag) mini[pos + 35] = min(mini[pos + 35], val);
    else mini[pos + 35] = val;
}

void relax(int pos1, int pos2) {
    mini[pos1 + 35] = min(mini[pos1 + 35], mini[pos2 + 35]);
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = -30; i <= 30; i++) st(i, INF);
    int res = 0;
    int pref = 0;
    st(-30, 0);
    for (int i = 1; i <= n; i++) {
        pref += a[i];
        for (int j = -30; j < a[i]; j++) {
            relax(a[i], j);
            st(j, INF);
        }
        for (int j = -30; j <= 30; j++) {
            res = max(res, pref - get(j) - j);
        }
        st(-30, pref, 1);
    }
    cout << res << endl;
}