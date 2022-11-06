#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 5;
char a[maxn], b[maxn], s[maxn];
int p[maxn], rev[maxn];

bool dfs(int i, int k, int n, bool x, bool y) {
    if (x && y) return true;
    if (i == n) return true;
    bool res = false;
    if (p[s[i] - 'a'] != -1) {
        if (!x && p[s[i] - 'a'] < a[i] - 'a') return false;
        if (!y && p[s[i] - 'a'] > b[i] - 'a') return false;
        return dfs(i + 1, k, n, x || (p[s[i] - 'a'] > a[i] - 'a'), y || (p[s[i] - 'a'] < b[i] - 'a'));
    }
    for (int j = 0; j < k; ++j) {
        if (rev[j] != -1) continue;
        if (!x && j < a[i] - 'a') continue;
        if (!y && j > b[i] - 'a') continue; 
        p[s[i] - 'a'] = j;
        rev[j] = s[i] - 'a';
        res |= dfs(i + 1, k, n, x || (j > a[i] - 'a'), y || (j < b[i] - 'a'));
        if (res) return true;
        p[s[i] - 'a'] = -1;
        rev[j] = -1;
    }
    return false;
}

int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int k; scanf("%d", &k);
        scanf("%s%s%s", s, a, b);
        int n = strlen(a);
        for (int i = 0; i < k; ++i) p[i] = -1;
        for (int i = 0; i < k; ++i) rev[i] = -1;
        bool ans = dfs(0, k, n, false, false);
        if (!ans) {
            puts("NO");
            continue;
        }
        vector<int> unused;
        for (int i = 0; i < k; ++i) {
            if (rev[i] == -1) unused.push_back(i);
        }
        for (int i = 0; i < k; ++i) {
            if (p[i] == -1) {
                p[i] = unused.back();
                unused.pop_back();
            }
        }
        puts("YES");
        for (int i = 0; i < k; ++i) printf("%c", (char)(p[i] + 'a'));
        puts("");
    }
    return 0;
}