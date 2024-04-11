#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define D(...)
const int maxn = 2e5+5;
int tot=0;
int ls[maxn*22],rs[maxn*22],pos[maxn],c[maxn],b[maxn],d[maxn];
ll sum[maxn*22],sum2[maxn*22];
vector<int> aa;
int update(int pre,int p,int v,int vc,int l,int r) {
    int rt=++tot;
    ls[rt]=ls[pre],rs[rt]=rs[pre],sum[rt]=sum[pre]+v,sum2[rt]=sum2[pre]+vc;
    if(l<r) {
        int m=(l+r)>>1;
        if(p<=m) ls[rt]=update(ls[pre],p,v,vc,l,m);
        else rs[rt]=update(rs[pre],p,v,vc,m+1,r);
    }
    return rt;
}
pair<ll,ll> query(int L,int R,int k,int l,int r) {
    if(l == r) return {sum[R]-sum[L],sum2[R]-sum2[L]};
    int m = (l+r)>>1;
    if(k>m) return query(rs[L],rs[R],k,m+1,r);
    ll fi=sum[rs[R]]-sum[rs[L]],se=sum2[rs[R]]-sum2[rs[L]];
    pair<ll,ll> ret = query(ls[L],ls[R],k,l,m);
    ret.first += fi, ret.second += se;
    return ret;
}
ll ssc[maxn];

struct node {
    int pos,pt,res;
    bool operator < (const node & n) const {
        return pos < n.pos;
    }
    bool operator == (const node & n) const {
        return pos == n.pos;
    }
};
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> c[i] >> b[i], d[i] = c[i] / b[i];
        aa.push_back(d[i]);
        ssc[i] = ssc[i - 1] + c[i];
    }
    sort(aa.begin(), aa.end());
    aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
    auto f = [&](int x) {return lower_bound(aa.begin(), aa.end(), x) - aa.begin();};
    int m = aa.size();
    for(int i = 1; i <= n; ++i) {
        pos[i] = update(pos[i - 1], f(d[i]), b[i], c[i], 0, m - 1);
    }

    set<node> s;
    s.insert({n,(int)(-1e9-5),0});
    int q;
    cin >> q;
    ll ans = 0;
    for(int k = 0; k < q; ++k) {
        int t; ll h;
        cin >> t >> h;
        auto it = s.begin();
        int l = 1;
        D(t, h);
        while(it != s.end()) {
            int r = it->pos, dt = t - it->pt, res = it->res;
            if(res) {
                assert(l==r);
                res=min((ll)c[r],(ll)b[r]*dt+res);
                if(res>=h) {
                    res-=h;
                    h=0;
                    it=s.erase(it);
                    if(r>1) s.insert({r-1,t,0});
                    s.insert({r,t,res});
                    break;
                } else {
                    h-=res;
                    l=r+1;
                    it=s.erase(it);
                }
            } else {
                D(l, r, dt);
                int qwq = lower_bound(aa.begin(), aa.end(), dt)-aa.begin();
                ll sb = 0, sc = 0;
                if(qwq<m) {
                    auto ss = query(pos[l-1],pos[r],qwq,0,m-1);
                    sb=ss.first,sc=ss.second;
                }
                D(sb, sc);
                sc=ssc[r]-ssc[l-1]-sc;
                ll atk=sb*dt+sc;
                D(qwq, atk);
                if(atk>=h) {
                    int lo=l,hi=r;
                    ll rr=atk-h;
                    while(lo<hi) {
                        int mid=(lo+hi)/2;
                        if(qwq<m){
                            auto ss = query(pos[l-1],pos[mid],qwq,0,m-1);
                            sb=ss.first,sc=ssc[mid]-ssc[l-1]-ss.second;
                        } else {
                            sb=0,sc=ssc[mid]-ssc[l-1];
                        }
                        if(sb*dt+sc>=h) {
                            hi=mid;
                            rr=sb*dt+sc-h;
                        } else {
                            lo=mid+1;
                        }
                    }
                    D(lo,rr);
                    if(lo==r) s.erase(it);
                    assert(rr<=c[lo]);
                    if(lo>1) s.insert({lo-1,t,0});
                    s.insert({lo,t,(int)rr});
                    h=0;
                    break;
                } else {
                    h -= atk;
                    l = r + 1;
                    it = s.erase(it);
                    continue;
                }
            }
        }
        D(h);
        for(auto [pos,pt,res]:s) {
            D(pos,pt,res);
        }
        D();
        ans+=h;
        if(s.empty()) s.insert({n,t,0});
    }
    cout << ans << '\n';
}