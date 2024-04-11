#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll seg[2000000];
ll lazy[2000000];
int n, sz;
void prop(int x,int lx,int rx){
    seg[x]+=lazy[x];
    if(rx-lx!=1){
        lazy[2*x+1]+=lazy[x];
        lazy[2*x+2]+=lazy[x];
    }
    lazy[x] = 0;
}
void build(int x=0,int lx=0,int rx=sz){
    if(rx-lx==1){
        seg[x] = -5000000000;
    }
    else{
        int m = (lx+rx)/2;
        build(2*x+1,lx,m);
        build(2*x+2,m,rx);
        seg[x] = max(seg[2*x+1],seg[2*x+2]);
    }
}
void init(int x){
    sz = 1; while(sz<x) sz*=2;
    build();
}
void update(int l,int r,ll v,int x=0, int lx=0,int rx=sz){
    prop(x,lx,rx);
    if(lx>=r || rx<=l) return;
    if(lx>=l && rx<=r){
        seg[x]+=v;
        if(rx-lx!=1){
            lazy[2*x+1]+=v;
            lazy[2*x+2]+=v;
        }
        return;
    }
    int m = (lx+rx)/2;
    update(l,r,v,2*x+1,lx,m);
    update(l,r,v,2*x+2,m,rx);
    seg[x]= max(seg[2*x+1],seg[2*x+2]);
}
ll query(){
    prop(0,0,sz);
    return seg[0];
}
map<pair<int,int>,int> profit;
map<int,int> compress;
map<int,int> take;
set<int> tot;
int main(){
    int m,p;
    scanf("%d%d%d",&n,&m,&p);
    pair<int,int> a[n];
    pair<int,int> b[m];
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].first,&a[i].second);
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&b[i].first,&b[i].second);
        if(take[b[i].first] == 0) take[b[i].first]=b[i].second;
        else take[b[i].first] = min(take[b[i].first],b[i].second);
        tot.insert(b[i].first);
    }
    for(int i=0;i<p;i++){
        int xk, yk, zk;
        scanf("%d%d%d",&xk,&yk,&zk);
        profit[make_pair(xk,yk)]+=zk;
        tot.insert(yk);
    }
    sort(a,a+n);
    init(tot.size());
    int v =0;
    for(auto &it : tot)
        compress[it] = v++;
    for(auto &it : take){
        update(compress[it.first],compress[it.first]+1,5000000000-it.second);
    }
    ll ans = -3000000000;
    auto it = profit.begin();
    for(int i=0;i<n;i++){
         while(it!=profit.end()){
             if((*it).first.first<a[i].first){
                update(compress[(*it).first.second]+1,sz,(*it).second);
                ++it;
             }
             else{
                 break;
             }
         }
         ans = max(ans,query()-a[i].second);
    }
    printf("%lld",ans);
}