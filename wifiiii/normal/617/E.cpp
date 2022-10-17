#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int lg = 17; // make x < 2^lg and y < 2^lg
ll hilbertorder(int x, int y) {
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

const int blo = 323;
struct qry {
    int l, r, id;
    ll ord;
    bool operator < (const qry & q) const {
//      return l / blo < q.l / blo || (l / blo == q.l / blo && r < q.r);
//        return l / blo < q.l / blo || (l / blo == q.l / blo && ((l / blo & 1) ? r < q.r : r > q.r));
        return ord < q.ord;
    }
};

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n,k,m;
    cin>>n>>m>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int i=1;i<=n;++i) a[i]^=a[i-1];
    vector<int> cnt(1<<20);
    vector<qry> qs;
    for(int i=0;i<m;++i) {
        int l,r;
        cin>>l>>r;
        --l;
        qs.push_back({l,r,i,hilbertorder(l,r)});
    }
    sort(qs.begin(),qs.end());
    int l=0,r=-1;
    ll cur=0;
    vector<ll> ans(m);
    for(auto q:qs) {
        while(r<q.r) {
            ++r;
            cur+=cnt[a[r]^k];
            cnt[a[r]]++;
        }
        while(l>q.l) {
            --l;
            cur+=cnt[a[l]^k];
            cnt[a[l]]++;
        }
        while(r>q.r) {
            cnt[a[r]]--;
            cur-=cnt[a[r]^k];
            --r;
        }
        while(l<q.l) {
            cnt[a[l]]--;
            cur-=cnt[a[l]^k];
            ++l;
        }
        ans[q.id]=cur;
    }
    for(int i=0;i<m;++i) cout<<ans[i]<<'\n';
}