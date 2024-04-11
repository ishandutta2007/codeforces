#include <bits/stdc++.h>

#define debug 0

std::string mat[10][10];
int cnt[10];
int a[10], tot;
bool vis[10][10];
std::vector<std::string> ans;

void check() {
    int m = (int)ans.size();
    printf("[check] %d\n", m - 1);
    for (int i = 0; i < m - 1; ++i) {
        assert(ans[i][0] == ans[i + 1][0] || ans[i][1] == ans[i + 1][1]);
    }
    for (int i = 0; i < m; ++i) {
        for (int j = i + 1; j < m; ++j) {
            assert(ans[i] != ans[j]);
        }
    }
}

void solve(int n) {
    for (int i = 1; i <= 8; ++i) {
        for (int j = 1; j <= 8; ++j) {
            mat[i][j] = std::string(1, (char)('a' + j - 1)) + std::to_string(i);
           // printf("%s%c", mat[i][j].c_str(), " \n"[j == 8]);
        }
    }
    ans.clear();
    for (int i = 0; i < 10; ++i) cnt[i] = 0;
    int sz = n;
    cnt[8] = 1;
    --n;
    for (int i = 1; i <= 8 && n; ++i) {
        if (n >= 8) {
            cnt[i] += 8;
            n -= 8;
        } else {
            cnt[i] += n;
            n = 0;
        }
    }
    int j = 1;
    for (int i = 1; i <= 8; ++i) {
        if (!cnt[i]) continue;
        ans.push_back(mat[i][j]);
        tot = 0;
        for (int k = 1; k <= 8; ++k) {
            if (k != j) {
                a[++tot] = k;
            }
        }
        if (i != 8 && cnt[i] == 8) std::swap(a[tot], a[tot - 1]);
        for (int k = 1; k <= tot && k < cnt[i]; ++k) {
            ans.push_back(mat[i][a[k]]);
            j = a[k];
        }
    }
    ans.push_back(mat[8][8]);

    if (debug) {
        check();
    } else {
        for (int i = 0; i <= sz; ++i) {
            printf("%s%c", ans[i].c_str(), " \n"[i == sz]);
        }
    }
}

int main() {
    if (debug) {
        for (int n = 2; n <= 63; ++n) {
            solve(n);
        }
    } else {
        int n;
        scanf("%d", &n);
        solve(n);
    }
    return 0;
}