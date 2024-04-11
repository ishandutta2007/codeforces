#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int MOD = 1e9+7;

int rev(int a, int m = MOD) {
    return a == 1 ? 1 : m - (ll)m*rev(m%a,a)/a;
}

int solve(const int n, const int m, const int p,
           const int x0, const int y0,
           const int x1, const int y1) {
    int dx = 1, dy = 1;
    vector<char> clean;

    const int q = 1 - p + MOD;

    vector was(n+1, vector(m+1, array { -1, -1, -1, -1 }));

    int loop = -1;

    int cx = x0, cy = y0;
    for (int i = 0; true; ++i) {
        clean.push_back(cx == x1 || cy == y1);

        const int j0 = (dx + 1) + (dy + 1) / 2;
        was[cx][cy][j0] = i;

        // cout << cx << " " << cy << endl;

        if (cx == n && dx == +1) dx = -1;
        if (cx == 1 && dx == -1) dx = +1;
        if (cy == m && dy == +1) dy = -1;
        if (cy == 1 && dy == -1) dy = +1;

        cx += dx;
        cy += dy;

        const int j = (dx + 1) + (dy + 1) / 2;
        if (was[cx][cy][j] != -1) {
            loop = was[cx][cy][j];
            break;
        }
    }

    const int k = size(clean);

    int a = 1, b = 0;
    for (int i = loop; i < k; ++i) {
        if (clean[i]) {
            a = (ll) q * a % MOD;
            b += a;
            if (b >= MOD) b -= MOD;
        } else {
            b += a;
            if (b >= MOD) b -= MOD;
        }
    }

    int x = (ll) b * rev((MOD + 1 - a) % MOD) % MOD;
    for (int i = loop; i--; ) {
        if (clean[i]) {
            x = (ll) q * (x + 1) % MOD;
        } else {
            ++x;
            if (x >= MOD) x -= MOD;
        }
    }

    return x;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t;
    while (t--) {
        int n, m, rb, cb, rd, cd, p;
        cin >> n >> m >> rb >> cb >> rd >> cd >> p;
        int res = solve(n, m, (ll) p * rev(100) % MOD, rb, cb, rd, cd);
        cout << res << endl;
    }
}