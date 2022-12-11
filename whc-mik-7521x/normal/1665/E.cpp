#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N],n;
struct node{
    vector<int>v;
    node operator+(const node b)const{
        vector<int>res;
        int l=0,r=0,t=0;
        while(l<(int)v.size()&&r<(int)b.v.size()&&t<31)res.push_back(v[l]<b.v[r]?v[l++]:b.v[r++]),t++;
        while(l<(int)v.size()&&t<31)res.push_back(v[l++]),t++;
        while(r<(int)b.v.size()&&t<31)res.push_back(b.v[r++]);
        return {res};
    }
    int ans(){
        int res=INT32_MAX;
        for(int i=0;i<(int)v.size();i++){
            for(int o=i+1;o<(int)v.size();o++){
                res=min(res,v[i]|v[o]);
            }
        }
        return res;
    }
};
struct segment{
    node t[N<<2];
    void pushup(int rt){
        t[rt]=t[rt<<1]+t[rt<<1|1];
    }
    void build(int rt,int l,int r){
        if(l==r)return t[rt]={{a[l]}},void();
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);
        build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    node query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1;
        if(L>mid)return query(rt<<1|1,mid+1,r,L,R);
        if(R<=mid)return query(rt<<1,l,mid,L,R);
        return query(rt<<1,l,mid,L,R)+query(rt<<1|1,mid+1,r,L,R);
    }
}tr;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        tr.build(1,1,n);
        int q;
        scanf("%d",&q);
        while(q--){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",tr.query(1,1,n,l,r).ans());
        }
    }
    return  0;
}