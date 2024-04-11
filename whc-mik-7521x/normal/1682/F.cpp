#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10,mod=1e9+7;
struct node{
    long long val1,val2;
    node(long long k1=0,long long k2=0){val1=k1,val2=k2;}
    node operator+(const node b)const{
        return node((val1+b.val1)%mod,(val2+b.val2)%mod);
    }
    node operator-(const node b)const{
        return node(((val1-b.val1)%mod+mod)%mod,((val2-b.val2)%mod+mod)%mod);
    }
};
long long root[N];
struct Persistence_Segment_Tree{
    node t[N<<5];
    long long ls[N<<5],rs[N<<5],tot=0;
    void upd(long long &rt,long long lrt,long long l,long long r,long long X,node d){
        if(!rt)rt=++tot;
        t[rt]=t[lrt]+d;
        ls[rt]=ls[lrt];
        rs[rt]=rs[lrt];
        if(l==r)return;
        long long mid=(l+r)>>1;
        if(X<=mid)upd(ls[rt]=0,ls[lrt],l,mid,X,d);
        else upd(rs[rt]=0,rs[lrt],mid+1,r,X,d);
    }
    node query(long long rt,long long l,long long r,long long L,long long R){
        if(L>R)return node();
        if(!rt)return node();
        if(L<=l&&r<=R)return t[rt];
        long long mid=(l+r)>>1;
        if(R<=mid)return query(ls[rt],l,mid,L,R);
        else if(L>mid)return query(rs[rt],mid+1,r,L,R);
        else return query(ls[rt],l,mid,L,R)+query(rs[rt],mid+1,r,L,R); 
    }
}tr;
long long b[N],a[N];
long long n,q;
vector<long long>vec;
int pos(long long x){
    return lower_bound(vec.begin(),vec.end(),x)-vec.begin()+1;
}
int main(){
    scanf("%lld%lld",&n,&q); 
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(long long i=1;i<=n;i++)scanf("%lld",&b[i]),b[i]+=b[i-1],vec.push_back(b[i]);
    vec.push_back(0ll);
    stable_sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    int m=vec.size();
    for(long long i=1;i<=n;i++){
        tr.upd(root[i],root[i-1],1,m,pos(b[i-1]),node(a[i]-a[i-1],(b[i-1]%mod)*(a[i]-a[i-1])%mod));
    }
    while(q--){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        long long ans=0;
        auto it=tr.query(root[r],1,m,pos(b[l-1]),m)-tr.query(root[l-1],1,m,pos(b[l-1]),m);
        ans+=it.val2-(b[l-1]%mod)*it.val1%mod;
        it=tr.query(root[r],1,m,1,pos(b[l-1])-1)-tr.query(root[l-1],1,m,1,pos(b[l-1])-1);
        ans-=it.val2-(b[l-1]%mod)*it.val1%mod;
        printf("%lld\n",(ans%mod+mod)%mod);
    }
    return  0;
}