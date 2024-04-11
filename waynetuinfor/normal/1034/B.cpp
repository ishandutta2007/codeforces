#include <bits/stdc++.h>
using namespace std;

set<vector<vector<int>>> s;
int ans = 0;

void dfs(vector<vector<int>> v, int res) {
    if (s.count(v)) return;
    s.insert(v);
    if (res > ans) {
        ans = res;
        // printf("update %d\n", ans);
    }
    int cnt = 0;
    for (int i = 0; i < v.size() && cnt < 2; ++i) {
        for (int j = 0; j < v[0].size() && cnt < 2; ++j) {
            if (v[i][j] == 1) continue;
            v[i][j] = 1;
            ++cnt;
            for (int x = 0; x < v.size(); ++x) {
                for  (int y = 0; y < v[0].size(); ++y) {
                    if (v[x][y] == 1) continue;
                    if (abs(x - i) + abs(y - j) != 3) continue;
                    v[x][y] = 1;
                    dfs(v, res + 2);
                    v[x][y] = 0;
                }
            }
            v[i][j] = 0;
        }
    }
}

int solve(int n, int m) {
    vector<vector<int>> v(n, vector<int>(m, 0));
    dfs(v, 0);
    return ans;
}

int solve1(int m) {
    int ans = (m / 6) * 6;
    if (m % 6 == 4) ans += 2;
    else if (m % 6 == 5) ans += 4;
    return ans;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    if (n > m) swap(n, m);
    if (n == 1) {
        printf("%d\n", solve1(m));
        return 0;
    }
    if (n == 2) {
        if (m < 3) puts("0");
        if (m == 3) puts("4");
        if (m == 4) puts("8");
        if (m == 5) puts("10");
        if (m == 6) puts("12");
        if (m == 7) puts("12");
        if (m == 8) puts("16");
        if (m == 9) puts("18");
        if (m == 10) puts("20");
        if (m == 11) puts("22");
        if (m == 12) puts("24");
        if (m > 12) printf("%d\n", 2 * m);
        return 0;
    }
    if (n & 1) {
        if (m & 1) printf("%lld\n", n * 1ll * m - 1);
        else printf("%lld\n", n * 1ll * m);
    } else {
        printf("%lld\n", n * 1ll * m);
    }
}