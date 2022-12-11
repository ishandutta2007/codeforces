#include <bits/stdc++.h>
#define int long long

using namespace std;

const int INF = 1e18;

vector <int> f;

void upd(int pos, int d) {
    for (int i = pos; i < (int) f.size(); i += i & (-i))
        f[i] += d;
}

int get(int pos) {
    int res = 0;
    for (int i = pos; i > 0; i -= i & (-i))
        res += f[i];
    return res;
}

void solve() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    f.clear();
    f.assign(n + 3, 0);
    vector <int> st[30];
    for (int i = n - 1; i >= 0; i--) {
        st[s[i] - 'a'].push_back(i + 1);
    }
    for (int i = 1; i <= n; i++)
        upd(i, 1);

    int res = INF;
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int pos = n + 1;
        for (int c = 0; 'a' + c < t[i]; c++) {
            if (!st[c].empty())
                pos = min(pos, st[c].back());
        }
        if (pos != n + 1)
            res = min(res, cur + get(pos) - 1);
        if (st[t[i] - 'a'].empty() || st[t[i] - 'a'].back() > pos)
            break;

        pos = st[t[i] - 'a'].back();
        st[t[i] - 'a'].pop_back();
        cur += get(pos) - 1;
        upd(pos, -1);
    }
    cout << (res == INF ? -1 : res) << "\n";
}

signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) 
        solve();
    return 0;
}