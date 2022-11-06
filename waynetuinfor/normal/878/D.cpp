#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5, maxk = 12;
int a[maxk][maxn], ans[maxn], pos[maxn];
vector<int> ds[maxn], mask[maxn];
vector<pair<int, int>> ask[1 << maxk];

struct query {
    int t, x, y;
    query(int a, int b, int c): t(a), x(b), y(c) {}
};

int main() {
    int n, k, q; scanf("%d %d %d", &n, &k, &q);
    for (int i = 0; i < k; ++i) for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < k; ++i) ds[j].push_back(a[i][j]);
        sort(ds[j].begin(), ds[j].end()), ds[j].resize(unique(ds[j].begin(), ds[j].end()) - ds[j].begin());
        for (int i = 0; i < k; ++i) a[i][j] = lower_bound(ds[j].begin(), ds[j].end(), a[i][j]) - ds[j].begin();
        for (int t = 0; t < k; ++t) {
            int s = 0;
            for (int i = 0; i < k; ++i) {
                if (a[i][j] > t) s ^= (1 << i); 
            }
            mask[j].push_back(s);
        }
    }
    // for (int j = 0; j < n; ++j) {
        // for (int t = 0; t < mask[j].size(); ++t) printf("%d ", mask[j][t]);
        // puts("");
    // }
    // puts("here");
    vector<query> qr;
    int qid = 0;
    for (int i = 0; i < q; ++i) {
        int t, x, y; scanf("%d %d %d", &t, &x, &y);
        qr.emplace_back(t, x, y);
        if (t == 3) {
            for (int j = 0; j < k; ++j) ask[mask[y - 1][j]].emplace_back(x - 1, qid);
            pos[qid++] = y - 1;
        }
    }
    for (int s = 0; s < (1 << k); ++s) {
        vector<int> st;
        for (int i = 0; i < k; ++i) {
            if (s & (1 << i)) st.push_back(1);
            else st.push_back(0);
        }
        for (int i = 0; i < q; ++i) {
            if (qr[i].t == 1) st.push_back(max(st[qr[i].x - 1], st[qr[i].y - 1]));
            if (qr[i].t == 2) st.push_back(min(st[qr[i].x - 1], st[qr[i].y - 1]));
        }
        for (int i = 0; i < ask[s].size(); ++i) ans[ask[s][i].second] += st[ask[s][i].first];
    }
    for (int i = 0; i < qid; ++i) printf("%d\n", ds[pos[i]][ans[i]]); 
    return 0;
}