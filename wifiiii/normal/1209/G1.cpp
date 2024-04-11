#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 200000;
struct node {
    int l, r, cnt;
    bool operator < (const node & n) const {
        return l < n.l;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n), l(maxn, -1), r(maxn, -1), cnt(maxn);
    for(int i = 0; i < n; ++i) {
        cin >> a[i]; --a[i];
        if(l[a[i]] == -1) l[a[i]] = i;
        r[a[i]] = i;
        cnt[a[i]] += 1;
    }
    vector<node> ps;
    for(int i = 0; i < maxn; ++i) {
        if(l[i] != -1) {
            ps.push_back({l[i], r[i], cnt[i]});
        }
    }
    sort(ps.begin(), ps.end());
    vector<int> par(ps.size()), msz(ps.size());
    for(int i = 0; i < ps.size(); ++i) par[i] = i;
    function<int(int)> find = [&](int x) {
        return x == par[x] ? x : par[x] = find(par[x]);
    };
    int lst = -1, lst_id = -1;
    for(int i = 0; i < ps.size(); ++i) {
        if(ps[i].l <= lst) {
            par[find(i)] = find(lst_id);
            msz[find(i)] = max(msz[find(i)], ps[i].cnt);
            lst = max(ps[i].r, lst);
        } else {
            msz[find(i)] = max(msz[find(i)], ps[i].cnt);
            lst = ps[i].r;
            lst_id = i;
        }
    }
    int ans = n;
    for(int i = 0; i < ps.size(); ++i) {
        if(i == find(i)) ans -= msz[i];
    }
    cout << ans << '\n';
}