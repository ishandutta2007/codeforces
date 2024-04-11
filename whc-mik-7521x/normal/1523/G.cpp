#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m;
struct seg{
    int t[N<<6],ls[N<<6],rs[N<<6],cnt;
    seg(){memset(t,63,sizeof t);memset(ls,0,sizeof ls),memset(rs,0,sizeof rs);cnt=0;}
    void ins(int &rt,int l,int r,int X,int val){
        if(!rt)rt=++cnt;
        t[rt]=min(t[rt],val);
        if(l==r)return;
        int mid=(l+r)>>1;
        if(X<=mid)ins(ls[rt],l,mid,X,val);
        else ins(rs[rt],mid+1,r,X,val);
    }
    int query(int rt,int l,int r,int L,int R){
        if(!rt)return 1e9;
        if(L<=l&&r<=R)return t[rt];
        int mid=(l+r)>>1,res=1e9;
        if(L<=mid)res=min(res,query(ls[rt],l,mid,L,R));
        if(R>mid)res=min(res,query(rs[rt],mid+1,r,L,R));
        return res;
    }
}tr;
struct BIT{
    int root[N];
    void add(int l,int r,int val){
        for(;r<=n;r+=r&-r)tr.ins(root[r],1,n,l,val);
    }
    int query(int l,int r){
        int res=1e9;
        for(int i=r;i;i-=i&-i)res=min(res,tr.query(root[i],1,n,l,r));
        return res;
    }
}bit;
struct node{
    int l,r,num;
};
vector<node>vec[N];
int ll[N],rr[N];
int solve(int l,int r){
    if(l>r)return 0;
    int now=bit.query(l,r);
    if(now>m)return 0;
    return rr[now]-ll[now]+1+solve(l,ll[now]-1)+solve(rr[now]+1,r);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        scanf("%d%d",&ll[i],&rr[i]);
        vec[rr[i]-ll[i]+1].push_back({ll[i],rr[i],i});
    }
    vector<int>ans;
    for(int i=n;i>=1;i--){
        for(auto it:vec[i])bit.add(it.l,it.r,it.num);
        ans.push_back(solve(1,n));
    }
    while(ans.size())printf("%d\n",ans.back()),ans.pop_back();
    return  0;
}