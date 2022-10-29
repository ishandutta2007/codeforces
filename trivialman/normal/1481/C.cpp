#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
const LL P = 1e9 + 7;
const LL INF = 1e18;
const int N = 1e5 + 5;
mt19937 rng(time(0));

int T, n, m;
int a[N], b[N], c[N];
set<int> remain[N];

int main() {
    cin >> T;
    while (T--) {
        scanf("%d%d", &n, &m);
        rep(i, 1, n) scanf("%d", a + i);
        rep(i, 1, n) scanf("%d", b + i);
        rep(i, 1, m) scanf("%d", c + i);

        //case1: c[m] is not in b
        int pos = 0;
        bool flag = false;
        rep(i, 1, n) if (c[m] == b[i]) {
            flag = true;
            pos = i;
            break;
        }
        if (!flag) {
            printf("NO\n");
            continue;
        }

        //case2 no enough painters
        rep(i, 1, n) remain[i].clear();
        rep(i, 1, n) if (a[i] != b[i]) remain[b[i]].insert(i);
        vector<int> ans(m + 1);
        rrep(i, m, 1) if (remain[c[i]].size()) {
            int x = *remain[c[i]].begin();
            remain[c[i]].erase(x);
            ans[i] = x;
            if (i == m)
                pos = x;
        }
        else {
            ans[i] = pos;
        }
        flag = true;
        rep(i, 1, n) if (remain[i].size()) flag = false;
        if (flag) {
            printf("YES\n");
            rep(i, 1, m) printf("%d ", ans[i]);
            printf("\n");
        } else
            printf("NO\n");
    }
    return 0;
}