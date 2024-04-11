#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node {
    int a, c, id;
    bool operator < (const node & n) const {
        return a < n.a;
    }
};
const int maxn = 100005;
ll mn[maxn<<2];
void update(int p,ll v,int l,int r,int rt) {
    if(l == r) {
        mn[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if(p<=m) update(p,v,l,m,rt<<1);
    else update(p,v,m+1,r,rt<<1|1);
    mn[rt]=min(mn[rt<<1],mn[rt<<1|1]);
}
ll query(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) return mn[rt];
    int m = (l + r) >> 1;
    ll ret = 1e18;
    if(m >= L) ret=min(ret,query(L,R,l,m,rt<<1));
    if(m < R) ret=min(ret,query(L,R,m+1,r,rt<<1|1));
    return ret;
}
ll solve(vector<node> a) {
    if(a.size() == 1) return a.back().c;
    vector<ll> dp(a.size(), 0);
    memset(mn, 0, sizeof(mn));
    for(int i = (int)a.size() - 2; i >= 0; --i) {
        auto it = upper_bound(a.begin() + i + 1, a.end(), (node){a[i].a + a[i].c, 0, 0});
        ll tmp = 1e18;
        if(it != a.end()) tmp = it->a - a[i].a - a[i].c + dp[it - a.begin()];
        int pos = it - a.begin() - 1;
        if(pos > i) tmp = min(tmp, query(i+1, pos, 0, a.size(), 1));
        dp[i] = tmp;
        update(i, tmp, 0, a.size(), 1);
    }
    ll ret = dp[0];
    for(auto p : a) ret += p.c;
    return ret;
}
int main() {
    int n;
    cin >> n;
    vector<node> a;
    for(int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y, i});
    }
    sort(a.begin(), a.end());
    ll ans=solve(a);
    cout<<ans<<endl;
}