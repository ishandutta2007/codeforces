#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,p,kp;
struct node{
    vector<pair<int,int>>kk;
    friend node operator+(node p,node q){
        node res;
        for(auto &u:p.kk){
            int pd=0;
            for(auto &v:q.kk){
                if(u.first==v.first){
                    v.second+=u.second;pd=1;break;
                }
            }
            if(pd)continue;
            q.kk.push_back(u);
            if((int)q.kk.size()<=kp)continue;
            int mi=n;
            for(auto &v:q.kk)mi=min(mi,v.second);
            vector<pair<int,int>>res;
            for(auto &v:q.kk)if(v.second-mi)res.push_back(make_pair(v.first,v.second-mi));
            q.kk=res; 
        }
        return q;
    }
    void print(){
        printf("%d ",(int)kk.size());
        for(auto it:kk)printf("%d ",it.first);
        puts("");
    }
};
struct seg{
    node t[N<<2];
    int tag[N<<2];
    void add_tag(int rt,int l,int r,int d){
        node res;
        res.kk.push_back({d,r-l+1});
        t[rt]=res;
        tag[rt]=d;
    }
    void pushup(int rt){
        t[rt]=t[rt<<1]+t[rt<<1|1];
    }
    void pushdown(int rt,int l,int r){
        int mid=(l+r)>>1;
        if(tag[rt]){
            add_tag(rt<<1,l,mid,tag[rt]);
            add_tag(rt<<1|1,mid+1,r,tag[rt]);
        }
        tag[rt]=0;
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L<=l&&r<=R)return add_tag(rt,l,r,d);
        int mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    node query(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1;
        pushdown(rt,l,r);
        if(R<=mid)return query(rt<<1,l,mid,L,R);
        if(L>mid)return query(rt<<1|1,mid+1,r,L,R);
        return query(rt<<1,l,mid,L,R)+query(rt<<1|1,mid+1,r,L,R);
    }
}tr;
int main(){
    scanf("%d%d%d",&n,&m,&p);
    kp=100/p;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        tr.upd(1,1,n,i,i,x);
    }
    while(m--){
        int tp,l,r,d;
        scanf("%d%d%d",&tp,&l,&r);
        if(tp==1){
            scanf("%d",&d);
            tr.upd(1,1,n,l,r,d);
        }
        else{
            tr.query(1,1,n,l,r).print();
        }
    }
    return  0;
}