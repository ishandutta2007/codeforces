#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int n,k;
long long ans=0;
vector<int>v;
struct node{
    int x,r,q;
}a[N];
struct BIT{
    int ts[N];
    int ask(int x){
        x=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
        int res=0;
        for(;x;x-=x&-x)res+=ts[x];
        return res;
    }
    void add(int x,int d){
        x=lower_bound(v.begin(),v.end(),x)-v.begin()+1;
        for(;x<=N;x+=x&-x)ts[x]+=d;
    }
}t;
void solve(int l,int r){
    if(l==r)return;
    int mid=(l+r)>>1,p1=l,p2=l-1;
    solve(l,mid),solve(mid+1,r);
    stable_sort(a+l,a+mid+1,[](node k1,node k2){return k1.q<k2.q;});
    stable_sort(a+mid+1,a+r+1,[](node k1,node k2){return k1.q<k2.q;});
    for(int i=mid+1;i<=r;i++){
        while(p2<mid&&a[p2+1].q<=a[i].q+k)t.add(a[++p2].x,1);
        while(p1<=mid&&a[p1].q<a[i].q-k)t.add(a[p1++].x,-1);
        ans+=t.ask(a[i].x+a[i].r)-t.ask(a[i].x-a[i].r-1);
    }
    while(p2<mid)t.add(a[++p2].x,1);
    while(p1<=mid)t.add(a[p1++].x,-1);
}
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&a[i].x,&a[i].r,&a[i].q);
        v.push_back(a[i].x);
        v.push_back(a[i].x-a[i].r-1);
        v.push_back(a[i].x+a[i].r);
    }
    stable_sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    stable_sort(a+1,a+n+1,[](node k1,node k2){return k1.r>k2.r;});
    solve(1,n);
    printf("%lld",ans);
    return  0;
}