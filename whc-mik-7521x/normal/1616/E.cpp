#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
struct SegmentTree{
    int sum[N<<2],lazy[N<<2];
    void pushup(int rt){return;}
    void pushdown(int rt,int l,int r){
        int mid=(l+r)>>1;
        sum[rt<<1]+=lazy[rt]*(mid-l+1);
        sum[rt<<1|1]+=lazy[rt]*(r-mid);
        lazy[rt<<1]+=lazy[rt];
        lazy[rt<<1|1]+=lazy[rt];
        lazy[rt]=0;
    }
    void build(int rt,int l,int r){
        lazy[rt]=0;
        if(l==r){sum[rt]=l;return;}
        int mid=(l+r)>>1;
        build(rt<<1,l,mid);build(rt<<1|1,mid+1,r);
        pushup(rt);
    }
    void upd(int rt,int l,int r,int L,int R,int d){
        if(L<=l&&r<=R){sum[rt]+=d*(r-l+1),lazy[rt]+=d;return;}
        pushdown(rt,l,r);
        int mid=(l+r)>>1;
        if(L<=mid)upd(rt<<1,l,mid,L,R,d);
        if(R>mid)upd(rt<<1|1,mid+1,r,L,R,d);
        pushup(rt);
    }
    int querysum(int rt,int l,int r,int L,int R){
        if(L<=l&&r<=R)return sum[rt];
        pushdown(rt,l,r);
        int res=0,mid=(l+r)>>1;
        if(L<=mid)res+=querysum(rt<<1,l,mid,L,R);
        if(R>mid)res+=querysum(rt<<1|1,mid+1,r,L,R);
        return res;
    }
};
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d\n",&n);
        char s[N];
        SegmentTree tr;
        queue<int>v[30];
        for(int i=1;i<=n;i++){
            v[getchar()-'a'].push(i);
        }
        scanf("\n");
        cin.getline(s+1,(int)1e9);
        long long ans=1e18,tot=0;
        tr.build(1,1,n);
        for(int i=1;i<=n;i++){
            int now=s[i]-'a';
            for(int o=0;o<now;o++){
                if(v[o].size()){
                    int kk=v[o].front();
                    ans=min(ans,tot+tr.querysum(1,1,n,kk,kk)-i);
                }
            }
            if(v[now].size()){
                int kk=v[now].front();
                v[now].pop();
                tot+=tr.querysum(1,1,n,kk,kk)-i;
                tr.upd(1,1,n,1,kk,1);
            }
            else break;
        }
        printf("%lld\n",ans==(long long)1e18?-1ll:ans);
    }
    return  0;
}