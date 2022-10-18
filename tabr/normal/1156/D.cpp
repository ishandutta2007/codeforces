#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for (int i = (a); i < (b); i++)

int n;
vector<vector<int>> p(2, vector<int>(200010)), siz(2, vector<int>(200010, 1));

int get(int x, int c) {
    if (p[c][x] == x)
        return x;
    return p[c][x] = get(p[c][x], c);
}

void merge(int x, int y, int c) {
    x = get(x, c);
    y = get(y, c);
    if (siz[c][x] < siz[c][y])
        swap(x, y);
    p[c][y] = x;
    siz[c][x] += siz[c][y];
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    rep(i, 0, 200010) {
        p[0][i] = p[1][i] = i;
    }
    cin >> n;
    rep(i, 0, n - 1) {
        int x, y, c;
        cin >> x >> y >> c;
        x--, y--;
        merge(x, y, c);
    }
    ll ans = 0;
    rep(i, 0, n) {
        if (p[0][i] == i)
            ans += (ll)siz[0][i] * (ll)(siz[0][i] - 1);
        if (p[1][i] == i)
            ans += (ll)siz[1][i] * (ll)(siz[1][i] - 1);
        ans += (ll)(siz[0][get(i, 0)] - 1) * (ll)(siz[1][get(i, 1)] - 1);
    }
    cout << ans << endl;

    return 0;
}