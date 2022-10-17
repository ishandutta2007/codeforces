#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 1e5+5;
int pos[N],tr[N*33][2],sum[N*33],tot=0;
int upd(int pre,int x,int d) {
    int rt=++tot;
    tr[rt][0]=tr[pre][0],tr[rt][1]=tr[pre][1],sum[rt]=sum[pre]+1;
    if(d>=0) tr[rt][x>>d&1]=upd(tr[pre][x>>d&1],x,d-1);
    return rt;
}
vector<int> a;
int find(int l, int r, int d, int v) {
    if(d < 0) return v;
    if(sum[tr[r][0]] > sum[tr[l][0]]) return find(tr[l][0], tr[r][0], d - 1, v);
    return find(tr[l][1], tr[r][1], d - 1, v + (1 << d));
}
int query(int l, int r, int d, int v) {
    if(d == -1) return v;
    int ls = sum[tr[r][0]] - sum[tr[l][0]];
    int rs = sum[tr[r][1]] - sum[tr[l][1]];
    for(int i : a) ls += !(i >> d & 1);
    if(ls >= 2) {
        vector<int> na;
        for(int i : a) {
            if(!(i >> d & 1)) na.push_back(i);
        }
        a = move(na);
        return query(tr[l][0], tr[r][0], d - 1, v);
    }
    if(sum[tr[r][0]] - sum[tr[l][0]] == 1) {
        int x = find(tr[l][0], tr[r][0], d - 1, v);
        a.push_back(x);
    }
    return query(tr[l][1], tr[r][1], d - 1, v + (1 << d));
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            pos[i] = upd(pos[i - 1], x, 29);
        }
        int q;
        cin >> q;
        while(q--) {
            int l, r;
            cin >> l >> r;
            a.clear();
            cout << query(pos[l - 1], pos[r], 29, 0) << '\n';
        }
        memset(tr, 0, sizeof(int) * 2 * (tot + 1));
        memset(sum, 0, sizeof(int) * (tot + 1));
        tot = 0;
    }
}