#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// op 1. query mex of count of i in [l, r]
// op 2. change a[p] to x

int cyc(int x, int d) {
    if(!d) return x;
    if(d==1) return x>>1|(x&1)<<2;
    return x>>2|(x&3)<<1;
}
ll hilbert3d(int x, int y, int z, int m) {
    // 0 <= x,y,z < 2^m
    static int E[] = {0,0,0,3,3,6,6,5};
    static int D[] = {0,1,1,2,2,1,1,0};
    static int rev[] = {0,1,3,2,7,6,4,5};
    ll h = 0;
    int e = 0, d = 0;
    for(int i = m - 1; i >= 0; --i) {
        int l = (x>>i&1)<<2 | (y>>i&1)<<1 | (z>>i&1);
        int w = rev[cyc(l^e, d)];
        h = h << 3 | w;
        e = e ^ cyc(E[w], (3-d)%3);
        d = (d + D[w] + 1) % 3;
    }
    return h;
}
struct qry {
    int l,r,id,tim;
    ll ord;
    bool operator < (const qry & q) const {
        return ord < q.ord;
    }
};
int pos[200005], val[200005], lstval[200005], cnt[200005], cnt2[200005];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    vector<int> aa = a;
    vector<qry> qs;
    int lg=0;
    while(1<<lg<n) ++lg;
    while(1<<lg<m) ++lg;
    int tot=0,qcnt=0;
    for(int i=0;i<m;++i) {
        int op,l,r;
        cin>>op>>l>>r;
        if(op==1) {
            --l, --r; // caution here
            qs.push_back({l,r,qcnt,tot,hilbert3d(l,r,tot,lg)});
            ++qcnt;
        } else {
            ++tot;
            pos[tot]=l-1;
            val[tot]=r;
            aa.push_back(r);
        }
    }
    sort(aa.begin(), aa.end());
    aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
    auto f = [&](int x) {
        return lower_bound(aa.begin(), aa.end(), x) - aa.begin();
    };
    for(int &i : a) i = f(i);
    for(int i=1;i<=tot;++i) val[i]=f(val[i]);
    sort(qs.begin(),qs.end());
    int l=0,r=-1,tim=0;
    vector<ll> ans(m);
    auto add = [&](int x) {
        cnt2[cnt[a[x]]]--;
        cnt[a[x]]++;
        cnt2[cnt[a[x]]]++;
    };
    auto del = [&](int x) {
        cnt2[cnt[a[x]]]--;
        cnt[a[x]]--;
        cnt2[cnt[a[x]]]++;
    };
    for(auto q:qs) {
        while(r<q.r) {
            ++r;
            add(r);
        }
        while(l>q.l) {
            --l;
            add(l);
        }
        while(r>q.r) {
            del(r);
            --r;
        }
        while(l<q.l) {
            del(l);
            ++l;
        }
        while(tim<q.tim) {
            ++tim;
            lstval[tim] = a[pos[tim]];
            if(pos[tim] >= l && pos[tim] <= r) {
                del(pos[tim]);
                a[pos[tim]] = val[tim];
                add(pos[tim]);
            } else {
                a[pos[tim]] = val[tim];
            }
        }
        while(tim>q.tim) {
            if(pos[tim] >= l && pos[tim] <= r) {
                del(pos[tim]);
                a[pos[tim]] = lstval[tim];
                add(pos[tim]);
            } else {
                a[pos[tim]] = lstval[tim];
            }
            --tim;
        }
        int res=1;
        while(cnt2[res]) ++res;
        ans[q.id]=res;
    }
    for(int i=0;i<qcnt;++i) cout<<ans[i]<<"\n";
}