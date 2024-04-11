#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10;
char s[maxn][maxn];
int n, m;

void check1(int a, int b, int c, int d) {
    vector<vector<int>> ans;
    vector<int> v(2);
    for (int i = 1; i <= n; ++i) {
        if (i & 1) v = { a, b }; else v = { c, d };
        bool ok = true;
        for (int j = 1; j <= m; ++j) ok &= (s[i][j] == '0' || s[i][j] - '0' == v[j & 1]);
        if (ok) {
            ans.emplace_back((vector<int>){ v[0], v[1] });
            continue;
        }
        if (i & 1) v = { b, a }; else v = { d, c };
        ok = true;
        for (int j = 1; j <= m; ++j) ok &= (s[i][j] == '0' || s[i][j] - '0' == v[j & 1]);
        if (ok) ans.emplace_back((vector<int>){ v[0], v[1] });
        else return;
    }
    for (int i = 0; i < ans.size(); ++i) {
        for (int j = 1; j <= m; ++j) cout << ans[i][j & 1];
        cout << endl;
    }
    exit(0);
}

void check2(int a, int b, int c, int d) {
    vector<vector<int>> ans;
    vector<int> v(2);
    for (int j = 1; j <= m; ++j) {
        if (j & 1) v = { a, b }; else v = { c, d };
        bool ok = true;
        for (int i = 1; i <= n; ++i) ok &= (s[i][j] == '0' || s[i][j] - '0' == v[i & 1]);
        if (ok) {
            ans.emplace_back((vector<int>){ v[0], v[1] });
            continue;
        }
        if (j & 1) v = { b, a }; else v = { d, c };
        ok = true;
        for (int i = 1; i <= n; ++i) ok &= (s[i][j] == '0' || s[i][j] - '0' == v[i & 1]);
        if (ok) ans.emplace_back((vector<int>){ v[0], v[1] });
        else return;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < ans.size(); ++j) cout << ans[j][i & 1];
        cout << endl;
    } 
    exit(0);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) cin >> s[i][j];
    }
    vector<int> v = { 1, 2, 3, 4 };
    do { check1(v[0], v[1], v[2], v[3]); check2(v[0], v[1], v[2], v[3]); } while (next_permutation(v.begin(), v.end()));
    cout << "0" << endl;
    return 0;
}