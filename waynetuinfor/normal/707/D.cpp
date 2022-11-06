#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000 + 10, maxq = 1e5 + 10;
vector<int> G[maxq], cnt, fl;
vector<vector<int>> cur;
int ans[maxq], n, m, q, sum;

struct query {
    int a, b, c;
};

vector<query> qry;

void dfs(int now, int fa) {
    bool go = false;
    if (now) {
        int r = qry[now].b, c = qry[now].c;
        if (qry[now].a == 1) {
            if (!(cur[r][c] ^ fl[r])) {
                go = true;
                ++sum; cnt[r]++;
                cur[r][c] ^= 1;
            }
        } else if (qry[now].a == 2) {
            if ((cur[r][c] ^ fl[r])) {
                go = true;
                --sum; cnt[r]--;
                cur[r][c] ^= 1;
            }
        } else if (qry[now].a == 3) {
            fl[r] ^= 1;
            go = true;
            sum -= cnt[r]; sum += m - cnt[r];
            cnt[r] = m - cnt[r];
        }
        ans[now] = sum;
    }
    for (int u : G[now]) if (u != fa) {
        dfs(u, now);
    }
    if (now && go) {
        int r = qry[now].b, c = qry[now].c;
        if (qry[now].a == 1) {
            --sum; cnt[r]--;
            cur[r][c] ^= 1;
        } else if (qry[now].a == 2) {
            ++sum; cnt[r]++;
            cur[r][c] ^= 1;
        } else if (qry[now].a == 3) {
            fl[r] ^= 1;
            sum -= cnt[r]; sum += m - cnt[r];
            cnt[r] = m - cnt[r];
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m >> q;
    qry = vector<query>(q + 1);
    int fa = 0;
    for (int i = 1; i <= q; ++i) {
        cin >> qry[i].a;
        if (qry[i].a == 1 || qry[i].a == 2) cin >> qry[i].b >> qry[i].c;
        else cin >> qry[i].b;
        if (qry[i].a == 4) fa = qry[i].b;
        else fa = i - 1;
        G[fa].emplace_back(i); G[i].emplace_back(fa);
    }
    cur.resize(n + 1);
    cnt.resize(n + 1); fl.resize(n + 1);
    for (int i = 0; i < n + 1; ++i) cur[i].resize(m + 1);
    dfs(0, -1);
    for (int i = 1; i <= q; ++i) cout << ans[i] << endl;
    return 0;
}