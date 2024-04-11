#include <bits/stdc++.h>
using namespace std;

struct seg_tree {
    vector<int> seg;
    vector<int> lazy;
    int sz;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        seg.resize(2 * sz);
        lazy.resize(2 * sz);
    }
    void push(int x, int lx, int rx, int v) {
        seg[x] += v;
        if(rx - lx != 1) {
            lazy[2 * x + 1] += v;
            lazy[2 * x + 2] += v;
        }
    }
    void prop(int x, int lx, int rx) {
        push(x, lx, rx, lazy[x]);
        lazy[x] = 0;
    }
    void upd(int l, int r, int v, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(lx >= l && rx <= r) {
            push(x, lx, rx, v);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m), upd(l, r, v, 2 * x + 2, m, rx);
        seg[x] = max(seg[2 * x + 1], seg[2 * x + 2]);
    }
    void upd(int l, int r, int v) { upd(l, r, v, 0, 0, sz); }
    int query(int l, int r, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return 0;
        if(lx >= l && rx <= r) return seg[x];
        int m = (lx + rx) / 2;
        return max(query(l, r, 2 * x + 1, lx, m), query(l, r, 2 * x + 2, m, rx));
    }
    int query(int l, int r) { return query(l, r, 0, 0, sz); }
};

vector<int> st, sz;
int t;
vector<vector<int>> stor;

void dfs(int curr, int par) {
    st[curr] = t++;
    sz[curr] = 1;
    for(int next : stor[curr]) {
        if(next == par) continue;
        dfs(next, curr);
        sz[curr] += sz[next];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> stack;
    stor.resize(n);
    vector<int> to_dfs;
    for(int i = n - 1; i >= 0; i--) {
        while(!stack.empty() && a[stack.back()] <= a[i])
            stack.pop_back();
        if(!stack.empty())
            stor[stack.back()].push_back(i);
        else
            to_dfs.push_back(i);
        stack.push_back(i);
    }
    vector<int> ans(n - k + 1);
    seg_tree in;
    in.init(n);
    st.resize(n), sz.resize(n);
    for(int x : to_dfs) dfs(x, -1);
    for(int i = 0; i < n; i++) {
        if(i >= k) {
            in.upd(st[i - k], st[i - k] + 1, -1000000000);
        }
        in.upd(st[i], st[i] + sz[i], 1);
        if(i >= k - 1)
            ans[i - (k - 1)] = in.query(0, n);
    }
    for(int i = 0; i < n - k + 1; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}