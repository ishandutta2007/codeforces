#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct segtree{
    vector<ll> zero;
    vector<ll> first;
    vector<ll> second;
    int sz;
    void init(int n){
        sz = 1;
        while(sz<n) sz*=2;
        first.assign(2*sz,0LL);
        second.assign(2*sz,0LL);
        zero.assign(2*sz,0LL);
    }
    ll queryZero(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)
            return 0;
        if(lx>=l && rx<=r)
            return zero[x];
        return queryZero(l,r,2*x+1,lx,(lx+rx)/2)+queryZero(l,r,2*x+2,(lx+rx)/2,rx);
    }
    ll queryZero(int l,int r){return queryZero(l,r,0,0,sz);}
    void updateZero(int i,int x,int lx,int rx){
        if(rx-lx==1){
            zero[x]++;
            return;
        }
        int m = (lx+rx)/2;
        if(i<m)
            updateZero(i,2*x+1,lx,m);
        else
            updateZero(i,2*x+2,m,rx);
        zero[x] = zero[2*x+1]+zero[2*x+2];
    }
    void updateZero(int i){updateZero(i,0,0,sz);}
    void updateFirst(int i,int x,int lx,int rx){
        if(rx-lx==1){
            first[x]+=queryZero(0,i);
            return;
        }
        int m = (lx+rx)/2;
        if(i<m)
            updateFirst(i,2*x+1,lx,m);
        else
            updateFirst(i,2*x+2,m,rx);
        first[x] = first[2*x+1]+first[2*x+2];
    }
    void updateFirst(int i){updateFirst(i,0,0,sz);}
    ll queryFirst(int l,int r,int x,int lx,int rx){
        if(lx>=r || rx<=l)
            return 0;
        if(lx>=l && rx<=r)
            return first[x];
        return queryFirst(l,r,2*x+1,lx,(lx+rx)/2)+queryFirst(l,r,2*x+2,(lx+rx)/2,rx);
    }
    ll queryFirst(int l,int r){ return queryFirst(l,r,0,0,sz);}
    void updateSecond(int i,int x,int lx,int rx){
        if(rx-lx==1){
            second[x]+=queryFirst(0,i);
            return;
        }
        int m = (lx+rx)/2;
        if(i<m)
            updateSecond(i,2*x+1,lx,m);
        else
            updateSecond(i,2*x+2,m,rx);
        second[x] = second[2*x+1]+second[2*x+2];
    }
    void updateSecond(int i){updateSecond(i,0,0,sz);}
    ll querySecond(){
        return second[0];
    }
};
int main(){
    int n;
    scanf("%d",&n);
    pair<int,int> a[n];
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        a[i] = {x,i};
    }
    sort(a,a+n);
    segtree t;
    t.init(n);
    for(int i=n-1;i>=0;i--){
        t.updateZero(a[i].second);
        t.updateFirst(a[i].second);
        t.updateSecond(a[i].second);
    }
    cout << t.querySecond() << endl;
}