#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
vector <pair <int, int>> v;
//int up[N], lw[N], dup[N], dlw[N];

pair <int, int> check(int d) {
    /*for (int i = 0; i < N; i++) {
        up[i] = N - 1;
        lw[i] = 0;
        dup[i] = 10 * N;
        dlw[i] = -10 * N;
    }*/
    int l = 0, r = N - 1, uu = N - 1, dd = 0, nu = 10 * N, nd = -10 * N;
    for (int i = 0; i < (int) v.size(); i++) {
        auto [x, y] = v[i];
        l = max(l, x - d);
        r = min(r, x + d);
        dd = max(dd, y - d);
        uu = min(uu, y + d);
        nu = min(nu, y + d - x);
        nd = max(nd, y - d - x);
    }
    if (l > r || dd > uu) return {-1, -1};
    for (int x = l; x <= r; x++) {
        int curd = max(dd, nd + x);
        int curu = min(uu, nu + x);
        if (curd <= curu && (x != 0 || curu != 0)) return {x, curu};
    }
    return {-1, -1};
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int a = 0, b = 0;
        for (int j = 0; j < (int) s.length(); j++) {
            if (s[j] == 'N') a++;
            else b++;
        }
        v.push_back({a, b});
    }
    int l = -1, r = 2 * N, mid;
    pair <int, int> res;
    while (r - l > 1) {
        mid = (l + r) / 2;
        auto kek = check(mid);
        if (kek.first != -1) {
            res = kek;
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << endl;
    for (int i = 0; i < res.first; i++) cout << "N";
    for (int i = 0; i < res.second; i++) cout << "B";
}