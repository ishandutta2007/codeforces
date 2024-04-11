#include<bits/stdc++.h>
using namespace std;
const long long N=4e5+10;
struct segment{
    long long x,l,r,val;
    bool operator<(const segment b)const{
        return x<b.x;
    }
};
long long n,m,q,a[N],b[N];
struct SegmentTree{
    long long t[N<<2],tag[N<<2];
    void pushup(long long rt){t[rt]=min(t[rt<<1],t[rt<<1|1]);}
    void add_tag(long long rt,long long x){t[rt]+=x;tag[rt]+=x;}
    void pushdown(long long rt){return add_tag(rt<<1,tag[rt]),add_tag(rt<<1|1,tag[rt]),tag[rt]=0,void();}
    void upd(long long rt,long long l,long long r,long long L,long long R,long long d){
        if(L<=l&&r<=R)return add_tag(rt,d);
        pushdown(rt);
        long long mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    long long query(long long rt,long long l,long long r,long long L,long long R){
        if(L<=l&&r<=R)return t[rt];
        pushdown(rt);
        long long mid=(l+r)>>1;
        long long res=1e18;
        if(L<=mid)res=min(res,query(rt<<1,l,mid,L,R));
        if(R>mid)res=min(res,query(rt<<1|1,mid+1,r,L,R));
        return res;
    }
}tr;
long long mival[N];
signed main(){
    scanf("%lld%lld%lld",&n,&m,&q);
    vector<pair<long long,long long>>vec[N];
    for(long long i=1;i<n;i++){
        scanf("%lld%lld",&a[i],&b[i+1]);
        tr.upd(1,1,n,i+1,i+1,b[i+1]);
    }
    for(long long i=1;i<=m;i++){
        long long x,y,w;
        scanf("%lld%lld%lld",&x,&y,&w);
        vec[x].push_back({y,w});
    }
    multiset<long long>st;
    for(long long i=1;i<=n;i++){
        for(auto it:vec[i]){
            tr.upd(1,1,n,1,it.first,it.second);
        }
        mival[i]=tr.query(1,1,n,1,n)+a[i];
        st.insert(mival[i]);
    }
    printf("%lld\n",*st.begin());
    while(q--){
        long long x,val;
        scanf("%lld%lld",&x,&val);
        st.erase(st.find(mival[x]));
        mival[x]+=val-a[x];
        a[x]=val;
        st.insert(mival[x]);
        printf("%lld\n",*st.begin());
    }
    return  0;
}