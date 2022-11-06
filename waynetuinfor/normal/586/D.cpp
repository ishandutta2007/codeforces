#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 5;
string s[3];
int st;
bool v[3][maxn], mem[3][maxn];

struct Train {
    char c;
    int l, r, row;
}; vector<Train> tr;

bool dp(int, int);
bool check(int, int);
bool valid(int, int);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t; while (t--) {
        int n, k; cin >> n >> k; tr.clear();
        for (int i = 0; i < 3; ++i) cin >> s[i];
        for (int i = 0; i < 3; ++i) for (int j = 0; j < n; ++j) {
            if (s[i][j] >= 'A' && s[i][j] <= 'Z') {
                int ind = j;
                while (ind < n && s[i][ind] == s[i][j]) ++ind;
                tr.push_back((Train){ s[i][j], j, ind - 1, i });
                j = ind - 1;
            }
        }
        for (int i = 0; i < 3; ++i) for (int j = 0; j < n; ++j) {
            if (s[i][j] == 's') st = i;
        }
        // for (auto t : tr) cout << t.row << ' ' << t.l << ' ' << t.r << endl;
        bool ans = false;
        memset(v, false, sizeof(v)); memset(mem, false, sizeof(mem));
        for (int i = 0; i < 3; ++i) ans |= dp(i, n - 1);
        cout << (ans ? "YES" : "NO") << endl;
    }
    return 0;
}

bool dp(int r, int n) {
    // cout << "dp[r][n]"
    if (n == 0) return r == st;
    if (v[r][n]) return mem[r][n];
    if (!check(r, n)) return false;
    mem[r][n] = false;
    if (r == 0) {
        if (valid(r, n - 1)) mem[r][n] |= dp(r, n - 1);
        if (valid(r + 1, n - 1)) mem[r][n] |= dp(r + 1, n - 1);
    }
    if (r == 1) {
        if (valid(r, n - 1)) mem[r][n] |= dp(r, n - 1);
        if (valid(r + 1, n - 1)) mem[r][n] |= dp(r + 1, n - 1);
        if (valid(r - 1, n - 1)) mem[r][n] |= dp(r - 1, n - 1);
    }
    if (r == 2) {
        if (valid(r, n - 1)) mem[r][n] |= dp(r, n - 1);
        if (valid(r - 1, n - 1)) mem[r][n] |= dp(r - 1, n - 1);
    }
    v[r][n] = true;
    // cout << "dp(" << r << ", " << n << ") = " << mem[r][n] << endl;
    return mem[r][n];
}

bool check(int r, int n) {
    for (auto t : tr) if (t.row == r) {
        if (t.l - 2 * (n - 1) <= n && t.r - 2 * (n - 1) >= n) return false;
        if (t.l - 2 * n <= n && t.r - 2 * n >= n) return false;
    }
    return true;
}

bool valid(int r, int n) {
    for (auto t : tr) if (t.row == r) {
        if (t.l - 2 * n <= n + 1 && t.r - 2 * n >= n + 1) return false;
    }
    return true;
}