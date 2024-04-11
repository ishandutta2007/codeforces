#include <bits/stdc++.h>
using namespace std;

template<typename T>
void chmin(T& x, const T& y) {
    if (x > y) x = y;
}
template<typename T>
void chmax(T& x, const T& y) {
    if (x < y) x = y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int, int> pii;
#define rep(i, l, r) for (int i = l; i <= r; ++i)
#define per(i, r, l) for (int i = r; i >= l; --i)
#define rep0(i, l, r) for (int i = l; i < r; ++i)
#define gc (c = getchar())
char readc() {
    char c;
    while (isspace(gc))
        ;
    return c;
}
int read() {
    char c;
    while (gc < '-')
        ;
    if (c == '-') {
        int x = gc - '0';
        while (gc >= '0') x = x * 10 + c - '0';
        return -x;
    }
    int x = c - '0';
    while (gc >= '0') x = x * 10 + c - '0';
    return x;
}
#undef gc

int cnt[5], a[20], id[20], pre[20];
int T, n;

signed main() {
#ifdef local
    freopen("1.in", "r", stdin);
#endif
    T = read();
    while (T--) {
        n = read();
        int maxn = 0;
        rep(i, 1, n) {
            a[i] = read();
            maxn = max(maxn, a[i]);
            id[i] = i;
        }
        if (maxn > 3) {
            printf("-1\n");
            continue;
        }
        memset(cnt, 0, sizeof(cnt));
        rep(i, 1, n)++ cnt[a[i]];
        if (cnt[3] > 1 || cnt[2] > 2 || (cnt[2] && cnt[3])) {
            printf("-1\n");
            continue;
        }
        auto cmp = [&](int i, int j) {
            return a[i] > a[j];
        };
        sort(id + 1, id + n + 1, cmp);
        rep(i, 1, n) pre[id[i]] = i;
        vector<vector<int> > ans;
        if (cnt[3]) {
            if (n == 1) {
                printf("2\n1\n3\n");
                continue;
            }
            const int v1[8] = { 0, 2, 1, 3, 1, 2, 0, 3 };
            const int v2[8] = { 0, 0, 1, 0, 0, 1, 1, 1 };
            ans.resize(8);
            for (int i = 0; i < 8; i++) {
                ans[i].resize(n);
                ans[i][0] = v1[i];
                ans[i][1] = v2[i];
            }
            --cnt[1];
            int m = 1;
            while (cnt[1]) {
                int len = (int)ans.size();
                ans.resize(len * 2);
                for (int i = len; i < len + len / 2; i++) ans[i] = ans[i - len / 2];
                for (int i = len + len / 2; i < len * 2; i++) ans[i] = ans[i - len / 2 * 3];
                ++m;
                for (int i = 0; i < len; i++) ans[i][m] = (i + 1) & 1;
                for (int i = len; i < len * 2; i++) ans[i][m] = i & 1;
                ans[0][m] = 0; ans[len / 2 * 3][m] = 1;
                --cnt[1];
            }
        } else if (cnt[2] == 2) {
            const int v1[9] = { 0, 1, 2, 1, 0, 2, 1, 2, 0 };
            const int v2[9] = { 0, 2, 0, 1, 2, 1, 0, 2, 1 };
            ans.resize(9);
            for (int i = 0; i < 9; i++) {
                ans[i].resize(n);
                ans[i][0] = v1[i];
                ans[i][1] = v2[i];
            }
            int m = 1;
            while (cnt[1]) {
                int len = (int)ans.size();
                ans.resize(len * 2);
                for (int i = len; i < len * 2; i++) ans[i] = ans[len * 2 - i - 1];
                ++m;
                for (int i = 0; i < len * 2; i++) ans[i][m] = (i + 1) & 1;
                ans[0][m] = 0;
                ans[len * 2 - 1][m] = 1;
                --cnt[1];
            }
        } else if (cnt[2] == 1) {
            const int v[3] = { 0, 2, 1 };
            ans.resize(3);
            for (int i = 0; i < 3; i++) {
                ans[i].resize(n);
                ans[i][0] = v[i];
            }
            int m = 0;
            while (cnt[1]) {
                int len = (int)ans.size();
                ans.resize(len * 2);
                for (int i = len; i < len * 2; i++) ans[i] = ans[len * 2 - i - 1];
                ++m;
                for (int i = 0; i < len * 2; i++) ans[i][m] = (i + 1) & 1;
                ans[0][m] = 0;
                ans[len * 2 - 1][m] = 1;
                --cnt[1];
            }
        } else {
            ans.resize(1);
            ans[0].resize(n);
            int m = -1;
            while (cnt[1]) {
                int len = (int)ans.size();
                ans.resize(len * 2);
                for (int i = len; i < len * 2; i++) ans[i] = ans[len * 2 - i - 1];
                ++m;
                for (int i = 0; i < len * 2; i++) ans[i][m] = (i + 1) & 1;
                ans[0][m] = 0;
                ans[len * 2 - 1][m] = 1;
                --cnt[1];
            }
        }
        rep(i, 1, (int)ans.size() - 1) {
            int sum = 0;
            rep(j, 0, n - 1) {
                sum += min(ans[i][j], ans[i - 1][j]);
            }
            if (i > 1) assert(sum == 1);
            rep(j, 0, n - 1) {
                printf("%d%c", ans[i][pre[j + 1] - 1], j == n - 1 ? '\n' : ' ');
            }
        }
    }
}