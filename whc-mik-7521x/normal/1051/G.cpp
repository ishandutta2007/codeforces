#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,a[N],b[N];
struct seg{
    long long t[N<<4],sum[N<<4],ct[N<<4];
    int ls[N<<4],rs[N<<4],cnt=0;
    void pushup(int rt){
        t[rt]=t[rs[rt]]+sum[ls[rt]]*ct[rs[rt]]+t[ls[rt]];
        sum[rt]=sum[ls[rt]]+sum[rs[rt]];
        ct[rt]=ct[ls[rt]]+ct[rs[rt]];
    }
    void upd(int &rt,int l,int r,int X){
        if(!rt)rt=++cnt;
        if(l==r)return t[rt]=sum[rt]=l,ct[rt]=1,void();
        int mid=(l+r)>>1;
        if(X<=mid)upd(ls[rt],l,mid,X);
        else upd(rs[rt],mid+1,r,X);
        pushup(rt);
    }
    void merge(int &rt1,int rt2,int l,int r){
        if(!rt2)return;
        if(!rt1)return rt1=rt2,void();
        int mid=(l+r)>>1;
        merge(ls[rt1],ls[rt2],l,mid);
        merge(rs[rt1],rs[rt2],mid+1,r);
        pushup(rt1);
    }
}tr;
struct node{
    int l,r,root;
    bool operator<(const node b)const{
        return l<b.l;
    }
};
set<node>st;
long long ans=0;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        node now;
        now.l=now.r=x;
        now.root=0;
        tr.upd(now.root,1,n,y);
        while(st.lower_bound(now)!=st.end()||st.lower_bound(now)!=st.begin()){
            node kk=st.lower_bound(now)!=st.end()?*st.lower_bound(now):node{(int)1e9,(int)1e9,(int)1e9};
            node kkk=st.lower_bound(now)!=st.begin()?*(--st.lower_bound(now)):node{(int)-1e9,(int)-1e9,(int)-1e9};
            if(now.l-kkk.r<=1){
                // cout<<i<<' '<<now.l<<" "<<now.r<<' '<<kkk.l<<' '<<kkk.r<<endl;
                st.erase(kkk);
                int nl=min(kkk.l,now.l),len=kkk.r-kkk.l+now.r-now.l+2;
                ans-=tr.t[now.root]+tr.t[kkk.root]+tr.sum[now.root]*(now.l-1)+tr.sum[kkk.root]*(kkk.l-1);
                // cout<<ans<<endl;
                tr.merge(now.root,kkk.root,1,n);
                now.l=nl,now.r=nl+len-1;
                ans+=tr.t[now.root]+tr.sum[now.root]*(now.l-1);
                // cout<<ans<<endl;
            }
            else if(kk.l-now.r<=1){
                // cout<<i<<' '<<now.l<<" "<<now.r<<' '<<kk.l<<' '<<kk.r<<endl;
                st.erase(kk);
                int nl=min(kk.l,now.l),len=kk.r-kk.l+now.r-now.l+2;
                ans-=tr.t[now.root]+tr.t[kk.root]+tr.sum[now.root]*(now.l-1)+tr.sum[kk.root]*(kk.l-1);
                // cout<<ans<<endl;
                tr.merge(now.root,kk.root,1,n);
                now.l=nl,now.r=nl+len-1;
                ans+=tr.t[now.root]+tr.sum[now.root]*(now.l-1);
                // cout<<ans<<endl;
            }
            else break;
        }
        st.insert(now);
        printf("%lld\n",ans);
    }
    return  0;
}