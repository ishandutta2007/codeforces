#include <bits/stdc++.h>
using namespace std;
#define ll long long

int sz = 1;
int seg[1200000];
int lazy[1200000];
int n;
void init(){
    while(sz<n) sz*=2;
}
void prop(int x,int lx,int rx){
    seg[x]+=lazy[x]*(rx-lx);
    if(rx-lx!=1){
        lazy[2*x+1]+=lazy[x];
        lazy[2*x+2]+=lazy[x];
    }
    lazy[x] = 0;
}
void update(int l,int r,int x=0,int lx=0,int rx=sz){
    prop(x,lx,rx);
    if(lx>=l && rx<=r){
        ++seg[x];
        if(rx-lx!=1){
            ++lazy[2*x+1];
            ++lazy[2*x+2];
        }
        return;
    }
    if(lx>=r || rx<=l) return;

    int m = (lx+rx)/2;
    update(l,r,2*x+1,lx,m);
    update(l,r,2*x+2,m,rx);
    seg[x]= seg[2*x+1]+seg[2*x+2];
}
int query(int i,int x=0,int lx=0,int rx=sz){
    prop(x,lx,rx);
    if(rx-lx==1) return seg[x];
    int m = (lx+rx)/2;
    if(i<m) return query(i,2*x+1,lx,m);
    return query(i,2*x+2,m,rx);
}
int binarySearch(int lo,int hi,int s){
    int mid = (lo+hi)/2;
    if(query(mid)>=s){
        if(mid==hi || query(mid+1)<s)
            return mid;
        return binarySearch(mid+1,hi,s);
    }
    return binarySearch(lo,mid-1,s);
}
int ans[300005];
vector<pair<int,int>> queries[300005];
int main(){
    int q;
    scanf("%d%d",&n,&q);
    init();
    int a[n];
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<n;i++){
        if(a[i]<=(i+1)){
            a[i] = (i+1)-a[i];
        }
        else{
            a[i] = 300002;
        }
    }
    for(int i=0;i<q;i++){
        int l,r;
        cin >> l >> r;
        queries[n-r-1].push_back({l,i});
    }
    for(int i=0;i<n;i++){
        if(query(0)>=a[i]){
            int lmax = binarySearch(0,i,a[i]);
            update(0,lmax+1);
        }
        for(pair<int,int> x: queries[i]){
            ans[x.second] = query(x.first);
        }
    }
    for(int i=0;i<q;i++)
        cout << ans[i] << endl;

}