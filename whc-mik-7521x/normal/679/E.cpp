#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
const long long inf=2e18;
long long p42[100];
long long n,step[N],q;
struct seg{
    long long t[N<<2],tag[N<<2];
    void add_tag(long long rt,long long d){
        t[rt]=min(t[rt]+d,inf),tag[rt]=min(tag[rt]+d,inf);
    }
    void pushup(long long rt){t[rt]=min(t[rt<<1],t[rt<<1|1]);}
    void pushdown(long long rt){
        add_tag(rt<<1,tag[rt]);
        add_tag(rt<<1|1,tag[rt]);
        tag[rt]=0;
    }
    void upd(long long rt,long long l,long long r,long long L,long long R,long long d){
        if(L>R)return;
        if(L<=l&&r<=R)return add_tag(rt,d);
        long long mid=(l+r)>>1;
        pushdown(rt);
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    void modify(long long rt,long long l,long long r,long long X,long long d){
        if(l==r)return t[rt]=d,void();
        long long mid=(l+r)>>1;
        pushdown(rt);
        if(X<=mid)modify(rt<<1,l,mid,X,d);
        else modify(rt<<1|1,mid+1,r,X,d);
        pushup(rt);
    }
    long long query(long long rt,long long l,long long r,long long L,long long R){
        if(L<=l&&r<=R)return t[rt];
        long long mid=(l+r)>>1;
        long long res=inf;
        pushdown(rt);
        if(L<=mid)res=min(res,query(rt<<1,l,mid,L,R));
        if(R>mid)res=min(res,query(rt<<1|1,mid+1,r,L,R));
        return res; 
    }
    long long findpos(long long rt,long long l,long long r){
        if(l==r)return t[rt]<0?l:0;
        long long mid=(l+r)>>1;
        pushdown(rt);
        if(t[rt<<1]<0)return findpos(rt<<1,l,mid);
        return findpos(rt<<1|1,mid+1,r);
    }
}tr;
void mody(long long x,long long val){
    step[x]=lower_bound(p42,p42+11,val)-p42;
    tr.modify(1,1,n,x,p42[step[x]]-val);
}
long long findval(long long x){
    return p42[step[x]]-tr.query(1,1,n,x,x);
}
struct Node_t{
	long long l,r;
	inline bool operator<(const Node_t &o)const{return l<o.l;}
};
set<Node_t>odt;
void split(long long x) {
	if(x>n)return;
	auto it=--odt.upper_bound(Node_t{x,0});
	if(it->l==x)return;
	long long l=it->l,r=it->r;
	odt.erase(it);
    mody(x-1,findval(r));
    odt.insert(Node_t{l,x-1});
	odt.insert(Node_t{x,r});
}
void fix(){
    while(tr.query(1,1,n,1,n)<0){
        long long now=tr.findpos(1,1,n);
        mody(now,findval(now));
    }
}
int main(){
    p42[0]=1;
    for(long long i=1;i<=10;i++)p42[i]=p42[i-1]*42;
    scanf("%lld%lld",&n,&q);
    for(long long i=1;i<=n;i++){
        long long x;
        scanf("%lld",&x);
        mody(i,x);
        odt.insert({i,i});
    }
    while(q--){
        long long tp,l,r,x;
        scanf("%lld",&tp);
        if(tp==1){
            scanf("%lld",&x);
            printf("%lld\n",findval((--odt.upper_bound({x,x}))->r));
        }
        if(tp==2){
            scanf("%lld%lld%lld",&l,&r,&x);
            split(l),split(r+1);
            while(odt.lower_bound({l,l})!=odt.end()&&odt.lower_bound({l,l})->l<=r){
                odt.erase(odt.lower_bound({l,l}));
            }
            tr.upd(1,1,n,l,r-1,inf);
            mody(r,x);
            odt.insert({l,r});
        }
        if(tp==3){
            scanf("%lld%lld%lld",&l,&r,&x);
            split(l),split(r+1);
            tr.upd(1,1,n,l,r,-x);
            fix();
            while(!tr.query(1,1,n,1,n)){
                tr.upd(1,1,n,l,r,-x);
                fix();
            }
        }
    }
    return  0;
}