#include <iostream>

using namespace std;

const int N = 2e5 + 7;
bool f[2][N];
int n, cnt;

int good(int pos) {
    if (pos < 0 || pos >= n) return 0;
    if (!f[0][pos] && !f[1][pos]) return 0;
    if (pos == n - 1) return 1;
    if (f[0][pos] && f[0][pos + 1]) return 1;
    if (f[1][pos] && f[1][pos + 1]) return 1;
    return 0;
}

void ch(int r, int pos) {
    cnt -= good(pos) + good(pos - 1);
    f[r][pos] = !f[r][pos];
    cnt += good(pos) + good(pos - 1);
}

int main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> n >> q;
    cnt = n;
    for (int i = 0; i < n; i++) {
        f[0][i] = f[1][i] = 1;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        ch(a, b);
        cout << (cnt == n ? "Yes" : "No") << "\n";
    }
    return 0;
}