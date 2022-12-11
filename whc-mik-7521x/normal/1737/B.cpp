#include<bits/stdc++.h>
using namespace std;
int t;
long long calc(long long x){
    if(!x)return 0;
    long long l=1,r=1e9,mid,ans;
    while(l<=r){
        mid=(l+r)>>1;
        if(1ll*mid*mid<=x)ans=mid,l=mid+1;
        else r=mid-1;
    }
    long long res=ans*3-2;
    if(1ll*ans*(ans+1)<=x)res++;
    if(1ll*ans*(ans+2)<=x)res++;
    return res;
}
int main(){
    scanf("%d",&t);
    while(t--){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",calc(r)-calc(l-1));
    }
    return 0;
}