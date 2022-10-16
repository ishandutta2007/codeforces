#include <bits/stdc++.h>

using namespace std;
using ll = long  long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

const int N  = 1000;
int n, k, m, g[N][N];

void solve(int l, int r, int col) {
    if (l >= r) return;
    m = max(m, col);

    for (int i = l; i < r; ++i)
    for (int j = i + 1; j < r; ++j) g[i][j] = col;

    int full =  r - l;
    if (r - l > k) {
        for (int i = 0, j = l; i < k; ++i) {
            int len = (full + i) / k;
            solve(j, j + len, col+1);
            j += len;
        }
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    solve(0, n, 1);

    cout << m << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) cout << g[i][j] << ' ';
    }
    cout << endl;
}