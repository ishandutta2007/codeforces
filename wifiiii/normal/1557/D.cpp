#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 600005;
int s[maxn<<2], lz[maxn<<2];
void build(int l,int r,int rt) {
    lz[rt] = s[rt] = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}
void update(int L,int R,int v,int l,int r,int rt) {
    if(L <= l && r <= R) {
        s[rt] = v;
        lz[rt] = v;
        return;
    }
    if(lz[rt]) {
        lz[rt << 1] = lz[rt << 1 | 1] = s[rt << 1] = s[rt << 1 | 1] = lz[rt];
        lz[rt] = 0;
    }
    int m = (l + r) >> 1;
    if(m >= L) update(L,R,v,l,m,rt<<1);
    if(m < R) update(L,R,v,m+1,r,rt<<1|1);
    if(s[rt << 1] == -1 || s[rt << 1 | 1] == -1) s[rt] = -1;
    else if(s[rt << 1] == s[rt << 1 | 1]) s[rt] = s[rt << 1];
    else s[rt] = -1;
}
void query(int L, int R, int l, int r, int rt, vector<int> &appear) {
    if(s[rt] != -1) {
        if(s[rt]) appear.push_back(s[rt]);
        return;
    }
    if(lz[rt]) {
        lz[rt << 1] = lz[rt << 1 | 1] = s[rt << 1] = s[rt << 1 | 1] = lz[rt];
        lz[rt] = 0;
    }
    int m = (l + r) >> 1;
    if(m >= L) query(L, R, l, m, rt<<1, appear);
    if(m < R) query(L, R, m+1, r, rt<<1|1, appear);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> p(m), l(m), r(m);
    vector<int> a;
    for(int i = 0; i < m; ++i) {
        cin >> p[i] >> l[i] >> r[i];
        a.push_back(l[i]);
        a.push_back(r[i]);
    }
    vector<int> ord(m);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](int i, int j) {return p[i] < p[j];});
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    auto f = [&](int x) {return lower_bound(a.begin(), a.end(), x) - a.begin();};
    int N = a.size();
    build(0, N - 1, 1);
    vector<int> dp(n + 1, 1), pre(n + 1, -1);
    dp[0] = 0;
    for(int i : ord) {
        vector<int> appear;
        int L = f(l[i]), R = f(r[i]);
        query(L, R, 0, N - 1, 1, appear);
        for(int u : appear) {
            if(u == p[i]) continue;
            if(dp[u] + 1 > dp[p[i]]) {
                dp[p[i]] = dp[u] + 1;
                pre[p[i]] = u;
            }
        }
        update(L, R, p[i], 0, N - 1, 1);
    }
    auto mx = max_element(dp.begin(), dp.end());
    cout << n - *mx << endl;
    int cur = mx - dp.begin();
    vector<int> use {cur};
    while(pre[cur] != -1) {
        cur = pre[cur];
        use.push_back(cur);
    }
    sort(use.begin(), use.end());
    vector<int> tot(n);
    iota(tot.begin(), tot.end(), 1);
    vector<int> ans;
    set_difference(tot.begin(), tot.end(), use.begin(), use.end(), back_inserter(ans));
    for(int i : ans) cout << i << " "; cout << endl;
}