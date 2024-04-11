#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct SegmentTree{
    int sum[N<<2];
    void pushup(int rt){sum[rt]=min(sum[rt<<1],sum[rt<<1|1]);}
    void build(int rt,int l,int r){
        sum[rt]=1e9;
        if(l==r){return;}
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L<=l&&r<=R){sum[rt]=min(d,sum[rt]);return;}
        int mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    int querysum(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[rt];
        int res=1e9,mid=(l+r)>>1;
        if(L<=mid)res=min(res,querysum(rt<<1,l,mid,L,R));
        if(R>mid)res=min(res,querysum(rt<<1|1,mid+1,r,L,R));
        return res;
    }
}segt;
int n,q;
set<int>st;
int main(){
    scanf("%d%d",&n,&q);
    for(int i=0;i<=n+1;i++){
        st.insert(i);
    }
    segt.build(1,0,n+1);
    while(q--){
        int op;
        scanf("%d",&op);
        if(op==0){
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            if(x==0){
                while(*st.lower_bound(l)<=r)st.erase(st.lower_bound(l));
            }
            else{
                segt.upd(1,0,n+1,l,l,r);
            }
        }
        else{
            int j;
            scanf("%d",&j);
            if(st.find(j)==st.end())puts("NO");
            else{
                if(segt.querysum(1,0,n+1,(*(--st.find(j)))+1,j)<(*(++st.find(j))))puts("YES");
                else puts("N/A");
            }
        }
    }
    return  0;
}