#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
const int M=50*N;
int n,ls[M],rs[M],tsz,root,cnt[M];
ll a[N],pref[N];
void Set(int&c,ll x,int v,int d){
        if(!c)c=++tsz;
        cnt[c]+=v;
        if(d<0)return;
        if(x&(1LL<<d))Set(rs[c],x,v,d-1);
        else Set(ls[c],x,v,d-1);
}
ll Get(int c,ll x,int d){
      if(d<0)return 0;
      if((x&(1LL<<d))&&cnt[ls[c]])return Get(ls[c],x,d-1)+(1LL<<d);
      if((!(x&(1LL<<d)))&&cnt[rs[c]])return Get(rs[c],x,d-1)+(1LL<<d);
      if(cnt[ls[c]])return Get(ls[c],x,d-1);
      if(cnt[rs[c]])return Get(rs[c],x,d-1);
      
}
int main(){
        scanf("%i",&n);
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        Set(root,0,1,50);
        for(int i=1;i<=n;i++)pref[i]=pref[i-1]^a[i],Set(root,pref[i],1,50);
        ll ans=Get(root,0,50),xr=0;
        for(int i=n;i>=1;i--)Set(root,pref[i],-1,50),xr^=a[i],ans=max(ans,Get(root,xr,50));
        printf("%lld",ans);
        return 0;
}