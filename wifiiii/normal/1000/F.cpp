#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5+5;

struct node {
    int l,r,mn,pos;
}tr[maxn<<2];
void build(int l, int r, int rt) {
    tr[rt].l = l, tr[rt].r = r;
    if(l == r) {
        tr[rt].mn = 1e9;
        return;
    }
    int m = (l + r) / 2;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
}
void update(int p, int v, int rt) {
    int l = tr[rt].l, r = tr[rt].r;
    if(l == r) {
        tr[rt].mn = v;
        tr[rt].pos = l;
        return;
    }
    int m = (l + r) / 2;
    if(p <= m) update(p, v, rt<<1);
    else update(p, v, rt<<1|1);
    if(tr[rt<<1].mn < tr[rt<<1|1].mn) {
        tr[rt].mn = tr[rt<<1].mn;
        tr[rt].pos = tr[rt<<1].pos;
    } else {
        tr[rt].mn = tr[rt<<1|1].mn;
        tr[rt].pos = tr[rt<<1|1].pos;
    }
}
pair<int,int> query(int L, int R, int rt) {
    int l = tr[rt].l, r = tr[rt].r;
    if(L <= l && r <= R) return {tr[rt].mn, tr[rt].pos};
    int m = (l + r) / 2;
    pair<int,int> ret{500000000, -1};
    if(L <= m) {
        pair<int,int> tmp = query(L, R, rt<<1);
        if(tmp.first < ret.first) {
            ret = tmp;
        }
    }
    if(m < R) {
        pair<int,int> tmp = query(L, R, rt<<1|1);
        if(tmp.first < ret.first) {
            ret = tmp;
        }
    }
    return ret;
}
struct qry {
    int l,r,id;
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> aa = a;
    sort(aa.begin(), aa.end());
    aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
    for(int &i : a) i = lower_bound(aa.begin(), aa.end(), i) - aa.begin();
    vector<int> lst(aa.size(), -1);
    build(0, n-1, 1);
    vector<vector<qry>> qs(n);
    int m;
    cin >> m;
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        qs[r].push_back({l, r, i});
    }
    vector<int> ans(m);
    for(int i = 0; i < n; ++i) {
        if(lst[a[i]] != -1) update(lst[a[i]], 1e9, 1);
        update(i, lst[a[i]], 1);
        lst[a[i]] = i;
        for(auto q : qs[i]) {
            pair<int,int> res = query(q.l, q.r, 1);
            if(res.first < q.l) ans[q.id] = a[res.second];
            else ans[q.id] = -1;
        }
    }
    for(int i = 0; i < m; ++i) {
        if(ans[i] == -1) cout << 0 << '\n';
        else cout << aa[ans[i]] << '\n';
    }
}