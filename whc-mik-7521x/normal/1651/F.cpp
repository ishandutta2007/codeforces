#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
typedef pair<long long,long long> pll;
pll operator+(const pll a,const pll b){
    return {a.first+b.first,a.second+b.second};
}
pll operator-(const pll a,const pll b){
    return {a.first-b.first,a.second-b.second};
}
struct SegmentTree{
    struct node{
        int l,r;
        pll val;
    }t[N<<5];
    int root[N],tot;
    SegmentTree(){memset(t,0,sizeof t),memset(root,0,sizeof root),tot=0;}
    int upd(int rt,int l,int r,int to,pair<int,int>ad){
        t[++tot]=t[rt];
        rt=tot;
        t[rt].val=t[rt].val+ad;
        if(l==r)return rt;
        int mid=(l+r)>>1;
        if(mid>=to)t[rt].l=upd(t[rt].l,l,mid,to,ad);
        else t[rt].r=upd(t[rt].r,mid+1,r,to,ad);
        return rt;
    }
    pll query(int rt1,int rt2,int l,int r,int to){
        if(l==r)return t[rt2].val-t[rt1].val;
        int mid=(l+r)>>1;
        if(mid>=to)return query(t[rt1].l,t[rt2].l,l,mid,to);
        else return (t[t[rt2].l].val-t[t[rt1].l].val)+query(t[rt1].r,t[rt2].r,mid+1,r,to);
    }
}tr;
struct segment{
    long long tp;
    long long l,r,tim;
    long long val;
    bool operator<(const segment b)const{
        return l<b.l;
    }
};
set<segment>st;
int n,q;
long long r[N],c[N],su[N];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld",&c[i],&r[i]);
        su[i]=su[i-1]+r[i];
        long long tim=min(1ll*N,(c[i]+r[i]-1)/r[i]);
        tr.root[i]=tr.upd(tr.root[i-1],1,N,tim,{r[i],c[i]});
    }
    st.insert(segment{2,1,n,0,0});
    scanf("%d",&q);
    long long ans=0;
    while(q--){
        long long t,h;
        scanf("%lld%lld",&t,&h);
        int pd=0;
        while(st.size()){
            segment now=*st.begin();
            st.erase(st.begin());
            if(now.tp==2){
                for(int i=now.l;i<=now.r;i++){
                    if(c[i]>=h){
                        if(1!=i)st.insert(segment{0,1,i-1,t,0});
                        st.insert(segment{1,i,i,t,c[i]-h});
                        if(n!=i)st.insert(segment{2,i+1,n,0,0});
                        pd=1;
                        break;
                    }
                    else h-=c[i];
                }
            }
            else if(now.tp==1){
                int x=now.l;
                long long val=min(c[x],now.val+r[x]*(t-now.tim));
                if(val>=h){
                    if(x!=1)st.insert(segment{0,1,x-1,t,0});
                    st.insert(segment{1,x,x,t,val-h});
                    pd=1;
                }
                else h-=val;
            }
            else{
                pll kk=tr.query(tr.root[now.l-1],tr.root[now.r],1,N,t-now.tim);
                long long val=kk.second+(t-now.tim)*(su[now.r]-su[now.l-1]-kk.first);
                if(val<h)h-=val;
                else{
                    int l=now.l,r=now.r,res=now.r,mid;
                    while(l<=r){
                        mid=(l+r)>>1;
                        pll check=tr.query(tr.root[now.l-1],tr.root[mid],1,N,t-now.tim);
                        long long cheval=check.second+(t-now.tim)*(su[mid]-su[now.l-1]-check.first);
                        if(cheval>=h)res=mid,r=mid-1;
                        else l=mid+1;
                    }
                    pll check=tr.query(tr.root[now.l-1],tr.root[res],1,N,t-now.tim);
                    long long cheval=check.second+(t-now.tim)*(su[res]-su[now.l-1]-check.first);
                    if(res!=1)st.insert(segment{0,1,res-1,t,0});
                    st.insert(segment{1,res,res,t,cheval-h});
                    if(res!=now.r)st.insert(segment{0,res+1,now.r,now.tim,0});
                    pd=1;
                }
            }
            if(pd)break;
        }
        if(!pd){
            ans+=h;
            st.insert(segment{0,1,n,t,0});
        }
    }
    printf("%lld",ans);
    return  0;
}