#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 35005;
int a[maxn], lstpos[maxn];
int dp[maxn], ndp[maxn];

int mn[maxn << 2], lz[maxn << 2];
void build(int l, int r, int rt) {
    if(l == r) {
        lz[rt] = 0;
        mn[rt] = dp[l];
        return;
    }
    int m = (l + r) / 2;
    build(l, m, rt<<1);
    build(m+1, r, rt<<1|1);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
    lz[rt] = 0;
}
void update(int L, int R, int v, int l, int r, int rt) {
    if(L <= l && r <= R) {
        mn[rt] += v;
        lz[rt] += v;
        return;
    }
    if(lz[rt]) {
        mn[rt<<1] += lz[rt]; mn[rt<<1|1] += lz[rt];
        lz[rt<<1] += lz[rt]; lz[rt<<1|1] += lz[rt];
        lz[rt] = 0;
    }
    int m = (l + r) / 2;
    if(l <= m) update(L, R, v, l, m, rt<<1);
    if(m < R) update(L, R, v, m+1, r, rt<<1|1);
    mn[rt] = min(mn[rt<<1], mn[rt<<1|1]);
}
int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) return mn[rt];
    int ret = 2e9;
    if(lz[rt]) {
        mn[rt<<1] += lz[rt]; mn[rt<<1|1] += lz[rt];
        lz[rt<<1] += lz[rt]; lz[rt<<1|1] += lz[rt];
        lz[rt] = 0;
    }
    int m = (l + r) / 2;
    if(l <= m) ret = min(ret, query(L, R, l, m, rt<<1));
    if(m < R) ret = min(ret, query(L, R, m+1, r, rt<<1|1));
    return ret;
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1];
        if(lstpos[a[i]]) dp[i] += i - lstpos[a[i]];
        lstpos[a[i]] = i;
    }
    for(int j = 2; j <= k; ++j) {
        memset(lstpos, 0, sizeof(lstpos));
        build(0, n, 1);
        for(int i = 1; i <= n; ++i) {
            if(lstpos[a[i]]) {
                update(0, lstpos[a[i]] - 1, i - lstpos[a[i]], 0, n, 1);
            }
            dp[i] = query(0, i - 1, 0, n, 1);
            lstpos[a[i]] = i;
        }
    }
    cout << dp[n] << endl;
}