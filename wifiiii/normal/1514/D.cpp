#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll hilbertorder(int x, int y, int lg) {
    ll ret=0;
    for(int s=lg-1;s>=0;--s) {
        int rx=x>>s&1,ry=y>>s&1;
        ret=(ret<<2)|((rx*3)^ry);
        if(!ry) {
            if(rx) x=(1<<lg)-1-x,y=(1<<lg)-1-y;
            swap(x,y);
        }
    }
    return ret;
}
struct qry {
    int l,r,id;
    ll ord;
    bool operator < (const qry & q) const {
        return ord < q.ord;
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i],--a[i];
    vector<qry> qs(m);
    int lg=0;while(1<<lg<n) ++lg;
    for(int i=0;i<m;++i) {
        int l,r;
        cin>>l>>r;
        --l, --r; // caution here
        qs[i]={l,r,i,hilbertorder(l,r,lg)};
    }
    sort(qs.begin(),qs.end());
    int l=0,r=-1;
    vector<ll> ans(m);
    vector<int> cnt(n+1),cnt2(n+1);
    int mx=0,mxcnt=0;
    auto add = [&](int x) {
        cnt2[cnt[a[x]]]--;
        cnt[a[x]]++;
        cnt2[cnt[a[x]]]++;
        if(cnt[a[x]]>mxcnt) mxcnt=cnt[a[x]];
    };
    auto del = [&](int x) {
        cnt2[cnt[a[x]]]--;
        cnt[a[x]]--;
        cnt2[cnt[a[x]]]++;
        if(!cnt2[mxcnt]) --mxcnt;
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
        ans[q.id]=max(1,mxcnt-(q.r-q.l+1-mxcnt));
    }
    for(int i=0;i<m;++i) cout<<ans[i]<<"\n";
}