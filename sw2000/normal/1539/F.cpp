#include<bits/stdc++.h>
#define fi first
#define se second
#define lo (o<<1)
#define ro (o<<1|1)
#define mid (l+r>>1)
#define rg 1,1,n+1
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int N=2e5+10;

int n,mi[N<<2],ma[N<<2],lazy[N<<2];
vector<int>pos[N];
void build(int o,int l,int r){
    if(l==r){
        mi[o]=ma[o]=l-1;
        return;
    }
    build(lo,l,mid);
    build(ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
    ma[o]=max(ma[lo],ma[ro]);
}
void pushdown(int o,int l,int r){
    if(lazy[o]){
        mi[lo]+=lazy[o];
        ma[lo]+=lazy[o];
        mi[ro]+=lazy[o];
        ma[ro]+=lazy[o];
        lazy[lo]+=lazy[o];
        lazy[ro]+=lazy[o];
        lazy[o]=0;
    }
}
void update(int ql,int qr,int o,int l,int r){
    if(ql<=l&&r<=qr){
        lazy[o]-=2;
        mi[o]-=2;
        ma[o]-=2;
        return;
    }
    pushdown(o,l,r);
    if(ql<=mid)update(ql,qr,lo,l,mid);
    if(qr>mid)update(ql,qr,ro,mid+1,r);
    mi[o]=min(mi[lo],mi[ro]);
    ma[o]=max(ma[lo],ma[ro]);
}
int findmi(int ql,int qr,int o,int l,int r){
    if(ql<=l&&r<=qr)return mi[o];
    pushdown(o,l,r);
    int ret=inf;
    if(ql<=mid)ret=findmi(ql,qr,lo,l,mid);
    if(qr>mid)ret=min(ret,findmi(ql,qr,ro,mid+1,r));
    return ret;
}
int findma(int ql,int qr,int o,int l,int r){
    if(ql<=l&&r<=qr)return ma[o];
    pushdown(o,l,r);
    int ret=-inf;
    if(ql<=mid)ret=findma(ql,qr,lo,l,mid);
    if(qr>mid)ret=max(ret,findma(ql,qr,ro,mid+1,r));
    return ret;
}
int ans[N];
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
//    freopen("A.in","r",stdin);
    cin>>n;
    for(int i=2;i<=n+1;i++){
        int a;cin>>a;
        pos[a].push_back(i);
    }
    build(rg);
    for(int id=1;id<=n;id++){
        for(auto i:pos[id])ans[i]=(findma(i,n+1,rg)-findmi(1,i-1,rg))/2;
        for(auto i:pos[id])update(i,n+1,rg);
        for(auto i:pos[id])ans[i]=max(ans[i],-(1+findmi(i,n+1,rg)-findma(1,i-1,rg))/2);
    }
    for(int i=2;i<=n+1;i++)cout<<ans[i]<<" \n"[i==n+1];
}