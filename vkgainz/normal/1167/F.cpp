#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mod = 1000000007;
struct segtree{
    vector<ll> sum1;
    vector<ll> sum2;
    int sz;
    void init(int n){
        sz = 1;
        while(sz<n) sz*=2;
        sum1.assign(2*sz,0LL);
        sum2.assign(2*sz,0LL);
    }
    void update(int i,int x,int lx,int rx){
        if(rx-lx==1){
            sum1[x]++;
            sum2[x]++;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m)
            update(i,2*x+1,lx,m);
        else
            update(i,2*x+2,m,rx);
        sum1[x] = sum1[2*x+1]+sum1[2*x+2];
        sum2[x] = sum2[2*x+1]+sum2[2*x+2]+(ll) (m-lx)*sum1[2*x+1]; //check if this works
        sum1[x]%=mod;
        sum2[x]%=mod;
    }
    void update(int i){update(i,0,0,sz);}
    ll querySum(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r) return sum1[x];
        int m = (lx+rx)/2;
        return querySum(l,r,2*x+1,lx,m)+querySum(l,r,2*x+2,m,rx);
    }
    ll querySum(int l,int r) { return querySum(l,r,0,0,sz);}
    ll query(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l) return 0;
        if(lx>=l && rx<=r){
            ll ans = sum2[x]+(ll) (r-rx)*querySum(lx,rx);
            ans%=mod;
            return ans;
        }
        int m = (lx+rx)/2;
        return (ll) query(l,r,2*x+1,lx,m)+query(l,r,2*x+2,m,rx);
    }
    ll query(int l,int r) { return query(l,r,0,0,sz); }
};
int main(){
    int n; 
    scanf("%d",&n);
    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        a[i] = {x,i};
    }
    sort(a,a+n);
    segtree t;
    t.init(n);
    ll tot = 0;
    for(int i=0;i<n;i++){
        int idx = a[i].second;
        t.update(idx);
        if(idx!=0){
            ll ans = (ll) (idx+1)*t.query(0,n);
            ans -= (ll) (n+1)*t.query(0,idx);
            ans%=mod;
            if(ans<0) ans+=mod;
            tot+=(ll) ans*a[i].first;
        }
        else{
            ll ans = t.query(0,n);
            tot+=(ll) ans*a[i].first;
        }
        tot%=mod;
        if(tot<0) tot+=mod;
    }
    cout << tot << endl;
}