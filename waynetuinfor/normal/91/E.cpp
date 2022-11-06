#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e6 + 10, sqsz = 500;
int a[maxn], b[maxn], l[maxn], r[maxn], ans[maxn];
int block, lb[maxn / sqsz + 1], rb[maxn / sqsz + 1], bi[maxn];
vector<int> qry[maxn];
deque<int> dq[maxn / sqsz + 1];

void init(int n) {
    block = 0;
    for (int i = 1; i <= n; ) {
        ++block;
        int j = 0;
        vector<int> v;
        lb[block] = i;
        while (j < sqsz && i + j <= n) bi[i + j] = block, v.push_back(i + j), ++j;
        rb[block] = i + j - 1;
        sort(v.begin(), v.end(), [&](const int &i, const int &j) { return b[i] < b[j]; });
        vector<int> nv;
        for (size_t j = 0; j < v.size(); ++j) {
            size_t p = j;
            int slp = 0, ins = -1;
            while (p < v.size() && b[v[p]] == b[v[j]]) {
                if (a[v[p]] > slp) slp = a[v[p]], ins = v[p];
                ++p;
            }
            nv.push_back(ins);
        }
        v = nv;
        for (size_t j = 0; j < v.size(); ++j) {
            while (dq[block].size() >= 2) {
                int z = dq[block][dq[block].size() - 2], y = dq[block][dq[block].size() - 1], x = v[j];
                if ((a[z] - a[x]) * 1ll * (b[y] - b[z]) <= (a[z] - a[y]) * 1ll * (b[x] - b[z])) dq[block].pop_back();
                else break;
            }
            dq[block].push_back(v[j]);
        }
        i += j;
    }
}

int query(int l, int r, int t) {
    long long mxh = 0;
    int bst = -1;
    if (bi[l] == bi[r]) {
        for (int i = l; i <= r; ++i) if (a[i] + b[i] * 1ll * t > mxh) mxh = a[i] + b[i] * 1ll * t, bst = i;
        return bst;
    }   
    for (int i = l; i <= rb[bi[l]]; ++i) {
        if (a[i] + b[i] * 1ll * t > mxh) mxh = a[i] + b[i] * 1ll * t, bst = i;
    }
    for (int i = lb[bi[r]]; i <= r; ++i) {
        if (a[i] + b[i] * 1ll * t > mxh) mxh = a[i] + b[i] * 1ll * t, bst = i;
    }
    for (int i = bi[l] + 1; i < bi[r]; ++i) {
        while (dq[i].size() >= 2 && a[dq[i][1]] + b[dq[i][1]] * 1ll * t >= a[dq[i][0]] + b[dq[i][0]] * 1ll * t) dq[i].pop_front();
        if (dq[i].size() && a[dq[i][0]] + b[dq[i][0]] * 1ll * t > mxh) mxh = a[dq[i][0]] + b[dq[i][0]] * 1ll * t, bst = dq[i][0];
    }
    return bst;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> b[i];
    for (int i = 0; i < q; ++i) {
        cin >> l[i] >> r[i];
        int t; cin >> t; 
        qry[t].push_back(i);
    }
    init(n);
    for (int i = 0; i <= 1000000; ++i) {
        for (size_t j = 0; j < qry[i].size(); ++j) ans[qry[i][j]] = query(l[qry[i][j]], r[qry[i][j]], i);
    }
    for (int i = 0; i < q; ++i) cout << ans[i] << endl;
    return 0;
}