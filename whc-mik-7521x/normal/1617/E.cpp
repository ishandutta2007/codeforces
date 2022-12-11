#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,a[N];
set<int>qa;
map<int,int>val;
long long upp(int x){
    int l=0,r=31,mid,res=0;
    while(l<=r){
        mid=(l+r)>>1;
        if((1ll<<mid)>=x)r=mid-1,res=mid;
        else l=mid+1;
    }
    return 1ll<<res;
}
int solve(int x){
    if(x==0)return 0;
    return solve(upp(x)-x)+1;
}
void ss(int now,int dep){
    qa.insert(now);
    val[now]=dep;
    if(now==0)return;
    ss(upp(now)-now,dep+1);
}
int fi(int x){
    if(qa.find(x)!=qa.end())return val[x];
    return fi(upp(x)-x)+1;
}
int main(){
    scanf("%d",&n);
    int now=0,dpmx=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int kk;
        if(now<(kk=solve(a[i])))now=kk,dpmx=i;
    }
    ss(a[dpmx],0);
    int mxw=0,ans=0;
    for(int i=1;i<=n;i++){
        if(i==dpmx)continue;
        int kk=fi(a[i]);
        if(kk>mxw)ans=i,mxw=kk;
    }
    printf("%d %d %d",dpmx,ans,mxw);
    return  0;
}