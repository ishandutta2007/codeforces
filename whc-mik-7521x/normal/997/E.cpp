#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
struct node{
    int val,cnt;
    node(int k1=1e9,int k2=1){val=k1,cnt=k2;}
    node operator+(const node b)const{
        return val<=b.val?val==b.val?node(val,cnt+b.cnt):*this:b;
    }
};
struct seg{
    node t[N<<2];
    int tag1[N<<2],tag2[N<<2];
    long long ans[N<<2];
    void pushup(int rt){
        t[rt]=t[rt<<1]+t[rt<<1|1];
        ans[rt]=ans[rt<<1]+ans[rt<<1|1];
    }
    void add_tag1(int rt,int d){
        t[rt].val+=d;
        tag1[rt]+=d;
    }
    void add_tag2(int rt,int d){
        ans[rt]+=t[rt].cnt*d;
        tag2[rt]+=d;
    }
    void pushdown(int rt){
        if(tag1[rt]){
            add_tag1(rt<<1,tag1[rt]);
            add_tag1(rt<<1|1,tag1[rt]);
            tag1[rt]=0;
        }
        if(tag2[rt]){
            if(t[rt<<1].val==t[rt].val)add_tag2(rt<<1,tag2[rt]);
            if(t[rt<<1|1].val==t[rt].val)add_tag2(rt<<1|1,tag2[rt]);
            tag2[rt]=0;
        }
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L<=l&&r<=R)return add_tag1(rt,d);
        int mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    void modify(int rt,int l,int r,int X){
        if(l==r)return t[rt]=node(0,1),void();
        int mid=(l+r)>>1;
        pushdown(rt);
        if(X<=mid)modify(rt<<1,l,mid,X);
        else modify(rt<<1|1,mid+1,r,X);
        pushup(rt);
    }
    long long query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return ans[rt];
        int mid=(l+r)>>1;
        long long res=0;
        pushdown(rt);
        if(L<=mid)res+=query(rt<<1,l,mid,L,R);
        if(R>mid)res+=query(rt<<1|1,mid+1,r,L,R);
        return res;
    }
}tr;
long long ans[N];
struct que{
    int l,r,num;
    bool operator<(const que b)const{
        return r<b.r;
    }
}qu[N];
int b[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]),b[i]=a[i];
    int q;
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d%d",&qu[i].l,&qu[i].r);
        qu[i].num=i;
    }
    stable_sort(qu+1,qu+q+1);
    stack<int>st1,st2;
    a[0]=1e9;
    st1.push(0);
    st2.push(0);
    int nn=1;
    for(int i=1;i<=n;i++){
        while(a[st1.top()]<a[i]){
            int now=st1.top();
            st1.pop();
            tr.upd(1,1,n,st1.top()+1,now,a[i]-a[now]);
        }
        st1.push(i);
        while(b[st2.top()]>b[i]){
            int now=st2.top();
            st2.pop();
            tr.upd(1,1,n,st2.top()+1,now,b[now]-b[i]);
        }
        st2.push(i);
        tr.modify(1,1,n,i);
        tr.add_tag2(1,1);
        while(nn<=q&&qu[nn].r<=i){
            ans[qu[nn].num]=tr.query(1,1,n,qu[nn].l,qu[nn].r);
            nn++;
        }
        tr.add_tag1(1,-1);
    }
    for(int i=1;i<=q;i++)printf("%lld\n",ans[i]);
    return  0;
}