#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<vector<int>> a(2 * n, vector<int>(2 * n, -1));
    vector<int> px(n * n), py(n * n);
    vector<vector<int>> sx(2 * n), sy(2 * n);
    vector<int> del(n * n);
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            --x;
            a[i + j][i - j + n] = x;
            px[x] = i + j;
            py[x] = i - j + n;
            sx[i + j].push_back(x);
            sy[i - j + n].push_back(x);
        }
    }
    vector<vector<char>> ans(n, vector<char>(n, 'G'));
    int lx = 0, rx = 2 * n - 1, ly = 0, ry = 2 * n - 1;
    int cur = n * n - 1;
    while(1) {
        while(cur >= 0 && del[cur]) --cur;
        if(cur < 0) break;
        int mx = cur, xx = px[mx], yy = py[mx];
        ans[(xx + yy - n) / 2][(xx - yy + n) / 2] = 'M';
        del[mx] = 1;
        int nlx = max(lx, xx - k), nrx = min(rx, xx + k);
        int nly = max(ly, yy - k), nry = min(ry, yy + k);
        for(int i = lx; i < nlx; ++i) {
            for(int w : sx[i]) del[w] = 1;
        }
        for(int i = nrx + 1; i <= rx; ++i) {
            for(int w : sx[i]) del[w] = 1;
        }
        for(int i = ly; i < nly; ++i) {
            for(int w : sy[i]) del[w] = 1;
        }
        for(int i = nry + 1; i <= ry; ++i) {
            for(int w : sy[i]) del[w] = 1;
        }
        lx = nlx, rx = nrx, ly = nly, ry = nry;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cout << ans[i][j];
        }
        cout << '\n';
    }
}