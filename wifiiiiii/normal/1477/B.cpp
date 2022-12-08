#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

const int maxn = 2e5+5;
int sum[maxn<<2], lz[maxn<<2];
string s, t;
void build(int l,int r,int rt) {
    lz[rt] = -1;
    if(l == r) {
        sum[rt] = t[l] - '0';
        return;
    }
    int m = (l + r) >> 1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
void update(int L,int R,int v,int l,int r,int rt) {
    if(L <= l && r <= R) {
        sum[rt] = v * (r-l+1);
        lz[rt] = v;
        return;
    }
    int m = (l + r) >> 1;
    if(lz[rt] != -1) {
        sum[rt<<1] = lz[rt] * (m-l+1);
        sum[rt<<1|1] = lz[rt] * (r-m);
        lz[rt<<1] = lz[rt];
        lz[rt<<1|1] = lz[rt];
        lz[rt] = -1;
    }
    if(m >= L) update(L,R,v,l,m,rt<<1);
    if(m < R) update(L,R,v,m+1,r,rt<<1|1);
    sum[rt] = sum[rt<<1] + sum[rt<<1|1];
}
int query(int L,int R,int l,int r,int rt) {
    if(L <= l && r <= R) return sum[rt];
    int m = (l + r) >> 1;
    if(lz[rt] != -1) {
        sum[rt<<1] = lz[rt] * (m-l+1);
        sum[rt<<1|1] = lz[rt] * (r-m);
        lz[rt<<1] = lz[rt];
        lz[rt<<1|1] = lz[rt];
        lz[rt] = -1;
    }
    ll ret = 0;
    if(m >= L) ret += query(L,R,l,m,rt<<1);
    if(m < R) ret += query(L,R,m+1,r,rt<<1|1);
    return ret;
}
string get(int l, int r, int rt) {
    if(l == r) return string(1, sum[rt] + '0');
    int m = (l + r) / 2;
    if(lz[rt] != -1) {
        sum[rt<<1] = lz[rt] * (m-l+1);
        sum[rt<<1|1] = lz[rt] * (r-m);
        lz[rt<<1] = lz[rt];
        lz[rt<<1|1] = lz[rt];
        lz[rt] = -1;
    }
    return get(l, m, rt<<1) + get(m+1, r, rt<<1|1);
}
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int n, q;
        cin >> n >> q;
        cin >> s >> t;
        build(0, n-1, 1);
        vector<int> l(q), r(q);
        for(int i=0;i<q;++i) cin>>l[i]>>r[i], --l[i], --r[i];
        int ok = 1;
        for(int i=q-1;i>=0;--i) {
            int p = query(l[i], r[i], 0, n-1, 1);
            int len = r[i] - l[i] + 1;
            if(p * 2 < len) {
                update(l[i], r[i], 0, 0, n-1, 1);
            } else if(p * 2 > len) {
                update(l[i], r[i], 1, 0, n-1, 1);
            } else {
                ok = 0;
                break;
            }
        }
        if(!ok) {
            cout << "NO\n";
            continue;
        }
        string res = get(0, n-1, 1);
        cout << (s == res ? "YES" : "NO") << '\n';
    }
}