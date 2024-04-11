#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 300005;
int mn[maxn<<2];
void build(int l,int r,int rt) {
    mn[rt] = 1e9;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
}
void update(int L,int R,int v,int l,int r,int rt) {
    if(L <= l && r <= R) {
        mn[rt] = min(mn[rt], v);
        return;
    }
    int m = (l + r) >> 1;
    if(m >= L) update(L,R,v,l,m,rt<<1);
    if(m < R) update(L,R,v,m+1,r,rt<<1|1);
}
int query(int p,int l,int r,int rt) {
    if(l == r) return mn[rt];
    int m = (l + r) >> 1;
    if(p <= m) return min(mn[rt], query(p, l, m, rt<<1));
    return min(mn[rt], query(p, m+1, r, rt<<1|1));
}
int mx[maxn<<2];
void build2(int l, int r, int rt) {
    mx[rt] = -1;
    if(l == r) return;
    int m = (l + r) >> 1;
    build2(l,m,rt<<1);
    build2(m+1,r,rt<<1|1);
}
void update2(int p, int v, int l, int r, int rt) {
    if(l == r) {
        mx[rt] = max(mx[rt], v);
        return;
    }
    int m = (l + r) / 2;
    if(p <= m) update2(p, v, l, m, rt << 1);
    else update2(p, v, m + 1, r, rt << 1 | 1);
    mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
}
int query2(int L, int R, int l, int r, int rt) {
    if(L > R) return -1;
    if(L <= l && r <= R) {
        return mx[rt];
    }
    int m = (l + r) / 2, ret = -1;
    if(L <= m) ret = max(ret, query2(L, R, l, m, rt<<1));
    if(m < R) ret = max(ret, query2(L, R, m+1, r, rt<<1|1));
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    vector<int> aa = a;
    sort(aa.begin(), aa.end());
    aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
    auto f = [&](int x) {return lower_bound(aa.begin(), aa.end(), x) - aa.begin();};
    int N = aa.size();
    int m;
    cin >> m;
    vector<vector<pair<int,int>>> q1(n), q2(n);
    for(int i = 0; i < m; ++i) {
        int l, r;
        cin >> l >> r;
        --l, --r;
        q1[r].push_back({l, i});
        q2[l].push_back({r, i});
    }
    vector<int> ans(m, 1e9);
    build(0, n-1, 1);
    build2(0, N-1, 1);
    for(int i = 0; i < n; ++i) {
        {
            int tmp = f(a[i]), up = N - 1, pos = -1;
            while((pos = query2(tmp, up, 0, N - 1, 1)) != -1) {
                // i -> pos : a[pos] - a[i]
                assert(a[pos] >= a[i]);
                update(0, pos, a[pos] - a[i], 0, n-1, 1);
                int nxt = upper_bound(aa.begin(), aa.end(), (a[pos] + a[i] - 1) / 2) - aa.begin() - 1;
                if(up == nxt) break;
                up = nxt;
            }
        }
        {
            int tmp = f(a[i]), down = 0, pos = 1;
            while((pos = query2(down, tmp, 0, N - 1, 1)) != -1) {
                // i -> pos : a[i] - a[pos]
                assert(a[i] >= a[pos]);
                update(0, pos, a[i] - a[pos], 0, n-1, 1);
                int nxt = f((a[pos] + a[i] + 2) / 2);
                if(down == nxt) break;
                down = nxt;
            }
        }
        for(auto p : q1[i]) {
            ans[p.second] = min(ans[p.second], query(p.first, 0, n - 1, 1));
        }
        update2(f(a[i]), i, 0, N - 1, 1);
    }
    for(int i = 0; i < m; ++i) cout << ans[i] << "\n";
}