#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> a, psum, b;


void reset() {
    for(int i = 0; i < psum.size(); i++) 
        fill(psum[i].begin(), psum[i].end(), 0);
}
void set_psum(int xa, int ya, int xb, int yb) {
    xa = max(xa, 1);
    ya = max(ya, 1);
    xb = min(xb, n);
    yb = min(yb, m);

    //cout << xa << " " << ya << " " << xb << " " << yb << '\n';
    psum[xa][ya]++; psum[xb + 1][ya]--;
    psum[xa][yb + 1]--; psum[xb + 1][yb + 1]++;
}
int get(int xa, int ya, int xb, int yb) {
    xa = max(xa, 1);
    ya = max(ya, 1);
    xb = min(xb, n);
    yb = min(yb, m);
    if (xa > xb || ya > yb) return 0;
    xa--, ya--;
    return psum[xb][yb] + psum[xa][ya] - psum[xa][yb] - psum[xb][ya];
}
void finalize() {
    for(int i = 1; i < a.size(); i++)
        for(int j = 1; j < a[i].size(); j++) 
            psum[i][j] += psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
}
bool check(int rad) {
    reset();
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= m + 1; j++) if (a[i][j] == 0) {
            set_psum(i - rad, j - rad, i + rad, j + rad);
        }
    /*
    cout << "Check " << rad << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cout << psum[i][j] << " ";
        cout << '\n';
    }*/
    finalize();
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) {
            b[i][j] = psum[i][j] == 0;
        }
    reset();
    for(int i = 1; i <= n; i++) 
        for(int j = 1; j <= m; j++) psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1] + b[i][j];

    /*
    cout << "Check " << rad << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cout << psum[i][j] << " ";
        cout << '\n';
    }

    cout << "Check " << rad << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cout << (b[i][j] ? 'X' : '.');
        cout << '\n';
    }*/
    for(int i = 0; i <= n + 1; i++)
        for(int j = 0; j <= m + 1; j++) if (a[i][j] == 1) {
            if (!get(i - rad, j - rad, i + rad, j + rad))
                return 0;
        }
    return 1;
}
void solve() {
    int L = 1, R = max(n, m);
    while (L <= R) {
        int mid = (L + R) / 2;
        if (check(mid)) L = mid + 1;
        else R = mid - 1;
    }
    assert(check(R));
    cout << R << '\n';
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) cout << (b[i][j] ? 'X' : '.');
        cout << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    a = vector<vector<int>>(n + 2, vector<int>(m + 2, 0));
    b = psum = a;

    for(int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for(int j = 1; j <= m; j++) a[i][j] = s[j - 1] == 'X';
    }
    solve();
}