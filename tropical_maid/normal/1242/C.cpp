#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

/*
Author : Tropical_maid
Created : 2019/11/07, 00:22:09
*/

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;

int k;
vector<int> A[20];
vector<pll> all;
llong sum[20];

struct solution {
    int from, to, val;
};

vector<solution> ans[1 << 15];
bool po[1 << 15];
int pr[1 << 15];

bool vis[20];

int C[20], P[20];

void solve(int b) {
    if (pr[b] == 0) {
        for (auto i : ans[b]) {
            C[i.from] = i.val;
            P[i.from] = i.to;
        }
        return;
    }
    solve(pr[b]);
    solve(b ^ pr[b]);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> k;
    llong asum = 0;
    for (int i = 1; i <= k; ++i) {
        int n;
        cin >> n;
        while (n--) {
            int x;
            cin >> x;
            A[i].push_back(x);
            all.emplace_back(x, i);
            asum += x;
            sum[i] += x;
        }
        sort(A[i].begin(), A[i].end());
    }
    if (asum % k != 0) {
        printf("No\n");
        return 0;
    }
    asum /= k;
    sort(all.begin(), all.end());
    for (int i = 1; i <= k; ++i) {
        for (int j : A[i]) {
            for (int t = 1; t <= k; ++t) vis[t] = 0;
            vector<solution> sol;
            bool pos = 1;
            llong v = j, p = i;
            while (1) {
                llong prv = v - sum[p] + asum;
                auto it = lower_bound(all.begin(), all.end(), pll(prv, 0));
                if (it == all.end() || it->fs != prv) {
                    pos = 0;
                    break;
                }
                sol.push_back({ it->se, p, prv });
                p = it->se;
                v = it->fs;
                if (vis[p]) {
                    pos = 0;
                    break;
                }
                vis[p] = 1;
                if (p == i) {
                    if (j != v) pos = 0;
                    break;
                }
            }
            if (!pos) continue;
            int b = 0;
            for (int t = 1; t <= k; ++t) if (vis[t]) b |= 1 << t - 1;
            ans[b] = sol;
            po[b] = 1;
        }
    }
    po[0] = 1;
    for (int i = 0; i < (1 << k); ++i) {
        if (po[i]) continue;
        for (int j = i; j > 0; j = i & (j - 1)) {
            if (po[j] && po[i - j]) {
                po[i] = 1;
                pr[i] = j;
                break;
            }
        }
    }
    if (!po[(1 << k) - 1]) {
        printf("No\n");
        return 0;
    }
    solve((1 << k) - 1);
    printf("Yes\n");
    for (int i = 1; i <= k; ++i) printf("%d %d\n", C[i], P[i]);
    return 0;
}